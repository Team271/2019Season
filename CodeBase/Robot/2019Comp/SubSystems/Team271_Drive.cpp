/*
 *    FRC Team 271's 2019 Comp Season Code
 *    Copyright (C) 2019  FRC Team 271
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "Team271_Includes.hpp"

#if defined(T271_DRIVE_ENABLE)

/*#define JOY_ENABLE*/

#define TANK_ENABLE
/*#define CHEESY_ENABLE*/

//constexpr double kDriveWheelTrackWidthInches = 25.42;             /* 254 */
//constexpr double kDriveWheelTrackWidthInches = 24.679641732;      /* Wheel Track Inner */
//constexpr double kDriveWheelTrackWidthInches = 27.929641732;      /* Wheel Track Outer */
constexpr double kDriveWheelTrackWidthInches = 26.304641732; /* Wheel Track */

constexpr double kTrackScrubFactor = 1.0;

constexpr double kWheelGain = 0.1;
constexpr double kWheelNonlinearity = 0.05;
double denominator = sin(M_PI / 2.0 * kWheelNonlinearity);

DriveSignal::DriveSignal(const double argDriver,
                         const double argPassenger)
      : DriveSignal(argDriver,
                    argPassenger,
                    false)
{

}

DriveSignal::DriveSignal(const double left,
                         const double right,
                         const bool brakeMode)
      : _DriverMotor(left),
        _PassengerMotor(right),
        _BrakeMode(brakeMode)
{

}

DriveSignal DriveSignal::fromControls(const double throttle,
                                      const double turn)
{
   return DriveSignal(throttle - turn,
                      throttle + turn);
}

double DriveSignal::getLeft(void)
{
   return _DriverMotor;
}

double DriveSignal::getRight(void)
{
   return _PassengerMotor;
}

bool DriveSignal::getBrakeMode(void)
{
   return _BrakeMode;
}

/**
 * A movement along an arc at constant curvature and velocity. We can use ideas from "differential calculus" to create
 * new RigidTransform2d's from a Twist2d and visa versa.
 * <p>
 * A Twist can be used to represent a difference between two poses, a velocity, an acceleration, etc.
 */
class Twist2d
{
public:
   double dx = 0;
   double dy = 0;
   double dtheta = 0; /* Radians! */

   Twist2d(double argX,
           double argY,
           double argTheta)
         : dx(argX),
           dy(argY),
           dtheta(argTheta)
   {

   }

   Twist2d scaled(double scale)
   {
      return Twist2d(dx * scale,
                     dy * scale,
                     dtheta * scale);
   }

   double norm()
   {
      // Common case of dy == 0
      if (dy == 0.0)
      {
         return fabs(dx);
      }

      return hypot(dx,
                   dy);
   }

   double curvature()
   {
      if (fabs(dtheta) < T271_EPSILON && norm() < T271_EPSILON)
      {
         return 0.0;
      }

      return dtheta / norm();
   }
};

/**
 * Uses inverse kinematics to convert a Twist2d into left and right wheel velocities
 */
DriveSignal inverseKinematics(Twist2d velocity)
{
   if (fabs(velocity.dtheta) < T271_EPSILON)
   {
      return DriveSignal(velocity.dx,
                         velocity.dx);
   }

   const double delta_v = kDriveWheelTrackWidthInches * velocity.dtheta / ( 2.0 * kTrackScrubFactor );

   return DriveSignal(velocity.dx - delta_v,
                      velocity.dx + delta_v);
}

Team271Drive::Team271Drive(void)
      : Team271Base(nullptr,
                    "Drive",
                    t271_drive_data_index::T271_DATA_COUNT)
{
   LOG_TRACE("%s - Constructor Start",
             GetName());

   LOG_TRACE("%s - Constructor End",
             GetName());
}

Team271Drive::~Team271Drive(void)
{

}

/*
 *
 * Getters
 *
 */
const string Team271Drive::GetClassName(void) const
{
   return "Team271Drive";
}

float Team271Drive::GetHeading(void) const
{
   return 0;
}

float Team271Drive::GetDriverPosition(void) const
{
   float tmpReturn = 0;

   if (_DriverEncoder != nullptr)
   {
      tmpReturn = _DriverEncoder->GetPosition(DRIVE_ENCODER_CONST);
   }

   return tmpReturn;
}

float Team271Drive::GetDriverRate(void) const
{
   float tmpReturn = 0;

   if (_DriverEncoder != nullptr)
   {
      tmpReturn = _DriverEncoder->GetRate(DRIVE_ENCODER_CONST) * 10.0;
   }

   return tmpReturn;
}

float Team271Drive::GetDriverOutputVoltage(void) const
{
   float tmpReturn = 0;

   if (_TransDriver != nullptr)
   {
      tmpReturn = _TransDriver->GetOutputVoltage();
   }

   return tmpReturn;
}

float Team271Drive::GetDriverOutputCurrent(void) const
{
   float tmpReturn = 0;

   if (_TransDriver != nullptr)
   {
      tmpReturn = _TransDriver->GetOutputCurrent();
   }

   return tmpReturn;
}

float Team271Drive::GetPassengerPosition(void) const
{
   float tmpReturn = 0;

   if (_PassengerEncoder != nullptr)
   {
      tmpReturn = _PassengerEncoder->GetPosition(DRIVE_ENCODER_CONST);
   }

   return tmpReturn;
}

float Team271Drive::GetPassengerRate(void) const
{
   float tmpReturn = 0;

   if (_PassengerEncoder != nullptr)
   {
      tmpReturn = _PassengerEncoder->GetRate(DRIVE_ENCODER_CONST) * 10.0;
   }

   return tmpReturn;
}

float Team271Drive::GetPassengerOutputVoltage(void) const
{
   float tmpReturn = 0;

   if (_TransPassenger != nullptr)
   {
      tmpReturn = _TransPassenger->GetOutputVoltage();
   }

   return tmpReturn;
}

float Team271Drive::GetPassengerOutputCurrent(void) const
{
   float tmpReturn = 0;

   if (_TransPassenger != nullptr)
   {
      tmpReturn = _TransPassenger->GetOutputCurrent();
   }

   return tmpReturn;
}

float Team271Drive::GetDriverAxisDriverX(void) const
{
   /*
    * Get Drive Input
    */
   return 0;
#if defined( T271_INPUT_ENABLE )
#if defined(JOY_ENABLE)
   return 0;
#else
   return Team271Input::Instance().GetAxis(eDriverLeft,
                                           eDriverAxisDriveDriverX);
#endif
#else
   return 0;
#endif
}

float Team271Drive::GetDriverAxisDriverY(void) const
{
   /*
    * Get Drive Input
    */
#if defined( T271_INPUT_ENABLE )
#if defined(JOY_ENABLE)
   return Team271Input::Instance().GetAxis(eDriverLeft,
                                           1) * -1.0;
#else
   return Team271Input::Instance().GetAxis(eDriverLeft,
                                           eDriverAxisDriveDriverY) * -1.0;
#endif
#else
   return 0;
#endif
}

float Team271Drive::GetDriverAxisPassengerX(void) const
{
   /*
    * Get Drive Input
    */
#if defined( T271_INPUT_ENABLE )
#if defined(JOY_ENABLE)
   return Team271Input::Instance().GetAxis(eDriverRight,
                                           0);
#else
   return Team271Input::Instance().GetAxis(eDriverLeft,
                                           eDriverAxisDrivePassnegerX);
#endif
#else
   return 0;
#endif
}

float Team271Drive::GetDriverAxisPassengerY(void) const
{
   /*
    * Get Drive Input
    */
   return 0;
#if defined( T271_INPUT_ENABLE )
#if defined(JOY_ENABLE)
   return 0;
#else
   return Team271Input::Instance().GetAxis(eDriverLeft,
                                           eDriverAxisDrivePassnegerY) * -1.0;
#endif
#else
   return 0;
#endif
}

Team271IMU* Team271Drive::GetIMU(void)
{
   return IMU_;
}

/*
 *
 * Setters
 *
 */
void Team271Drive::SetDriveMode(const uint32_t argDriveMode)
{
   Write(t271_drive_data_index::T271_DRIVE_DATA_MODE,
         argDriveMode);
}

void Team271Drive::ShiftGears(const eDriveGear argGear)
{
   if (_TransDriver != nullptr)
   {
      _TransDriver->ShiftGears(TEAM271_SHIFTER_INDEX_1,
                               (eGear)argGear);
   }

   if (_TransPassenger != nullptr)
   {
      _TransPassenger->ShiftGears(TEAM271_SHIFTER_INDEX_1,
                                  (eGear)argGear);
   }
}

void Team271Drive::SetSetpoint(const float argDriverSetpoint,
                               const float argPassSetpoint)
{
   Write(t271_drive_data_index::T271_DRIVE_DATA_DRIVER_VALUE,
         argDriverSetpoint);

   Write(t271_drive_data_index::T271_DRIVE_DATA_PASS_VALUE,
         argPassSetpoint);
}

void Team271Drive::SetNeutral(void)
{
   float tmpDriverSetpoint = 0;
   float tmpPassSetpoint = 0;

   if (_TransDriver != nullptr)
   {
      tmpDriverSetpoint = _TransDriver->GetNeutralValue();
   }

   if (_TransPassenger != nullptr)
   {
      tmpPassSetpoint = _TransDriver->GetNeutralValue();
   }

   SetSetpoint(tmpDriverSetpoint,
               tmpPassSetpoint);
}

void Team271Drive::Init(void)
{
   Team271Motor* tmpMasterMotor = nullptr;
   Team271Motor* tmpSlaveMotor = nullptr;

   /*
    * Create Driver Side Transmission
    *
    * Add it to the Child List
    */
   _TransDriver = Team271BaseManager::InstanceAdd(new Team271Transmission(this,
                                                                          "Driver Side"));

   if (_TransDriver != nullptr)
   {
      /*
       * Add the motors
       */
      tmpMasterMotor = _TransDriver->AddMotor("Driver Front",
                                              TEAM271_MOTOR_CONTROLLER_TYPE_SPARK_MAX_PWM,
                                              FRONT_DRIVER_MOTOR);

      tmpMasterMotor->SetInvertedOutput(TEAM271_INVERTED_STATE_INVERTED);

      tmpMasterMotor->SetNeutralDeadband(0.05f);

      tmpSlaveMotor = _TransDriver->AddMotor("Driver Middle",
                                             TEAM271_MOTOR_CONTROLLER_TYPE_SPARK_MAX_PWM,
                                             MIDDLE_DRIVER_MOTOR,
                                             tmpMasterMotor);

      tmpSlaveMotor = _TransDriver->AddMotor("Driver Rear",
                                             TEAM271_MOTOR_CONTROLLER_TYPE_SPARK_MAX_PWM,
                                             REAR_DRIVER_MOTOR,
                                             tmpMasterMotor);

      /*
       * Create the Shifter
       */
      _DriveShifter = _TransDriver->SetShifter(TEAM271_SHIFTER_INDEX_1,
                                               new Team271Shifter_Drive(_TransDriver));

      /*
       * Setup Driver Side Sensors
       */
#if 0
      _DriverEncoder = new Team271SensorCTRE(_TransDriver,
            "Driver Side Enc",
            DRIVER_CANIFIER,
            TEAM271_SENSOR_TYPE_MAG_REL,
            TEAM271_INVERTED_STATE_NOT_INVERTED,
            TEAM271_SENSOR_SETTINGS_NONE,
            0);

      _DriverEncoder->SetVelMeas(T271_VelocityMeasPeriod::T271_Period_20Ms,
                                 16);

      /*
       _DriverEncoder->SetVelMeas( T271_VelocityMeasPeriod::T271_Period_100Ms,
       64 );
       */

      _TransDriver->SetSensor(TEAM271_SENSOR_INDEX_ENCODER,
                              _DriverEncoder);
#endif
      _TransDriver->SetControlMode(TEAM271_CONTROL_MODE_PERCENT_OUTPUT);
   }

   /*
    * Create Passenger Side Transmission
    *
    * Add it to the Child List
    */
   _TransPassenger = Team271BaseManager::InstanceAdd(new Team271Transmission(this,
                                                                             "Passenger Side"));

   if (_TransPassenger != nullptr)
   {
      /*
       * Add the motors
       */
      tmpMasterMotor = _TransPassenger->AddMotor("Passenger Front",
                                                 TEAM271_MOTOR_CONTROLLER_TYPE_SPARK_MAX_PWM,
                                                 FRONT_PASSENGER_MOTOR);

      tmpMasterMotor->SetInvertedOutput(TEAM271_INVERTED_STATE_NOT_INVERTED);

      tmpMasterMotor->SetNeutralDeadband(0.05f);

      tmpSlaveMotor = _TransPassenger->AddMotor("Passenger Middle",
                                                TEAM271_MOTOR_CONTROLLER_TYPE_SPARK_MAX_PWM,
                                                MIDDLE_PASSENGER_MOTOR,
                                                tmpMasterMotor);

      tmpSlaveMotor = _TransPassenger->AddMotor("Passenger Rear",
                                                TEAM271_MOTOR_CONTROLLER_TYPE_SPARK_MAX_PWM,
                                                REAR_PASSENGER_MOTOR,
                                                tmpMasterMotor);

      /*
       * Set the Shifters
       */
      _TransPassenger->SetShifter(TEAM271_SHIFTER_INDEX_1,
                                  new Team271Shifter_Drive(_TransPassenger,
                                                           0));

      /*
       * Setup Passenger Side Sensors
       */
#if 0
      _PassengerEncoder = new Team271SensorCTRE( _TransPassenger,
            "Passenger Side Enc",
            PASSENGER_CANIFIER,
            TEAM271_SENSOR_TYPE_MAG_REL,
            TEAM271_INVERTED_STATE_NOT_INVERTED,
            TEAM271_SENSOR_SETTINGS_NONE,
            0 );

      _PassengerEncoder->SetVelMeas(T271_VelocityMeasPeriod::T271_Period_20Ms,
                                    16);
      /*
       _PassengerEncoder->SetVelMeas( T271_VelocityMeasPeriod::T271_Period_100Ms,
       64 );
       */

      _TransPassenger->SetSensor(TEAM271_SENSOR_INDEX_ENCODER,
                                 _PassengerEncoder);
#endif

      _TransPassenger->SetControlMode(TEAM271_CONTROL_MODE_PERCENT_OUTPUT);
   }

   /*
    * Setup IMU
    */
   /*
    IMU_ = Team271BaseManager::InstanceAdd( new Team271Pigeon( this,
    PIGEON_IMU ) );
    */
   //CreateTable();
}

void Team271Drive::RobotInit(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::RobotInit();

   /*
    * Initialize Shifter
    */
   ShiftGears(DRIVE_DEFAULT_GEAR);

   /*
    * Stop Driving
    */
   SetNeutral();
}

void Team271Drive::PreRobotPeriodic(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::PreRobotPeriodic();

   /*
    * Store Previous Drive Mode
    */
   ModePrev_ = Read<uint8_t>(t271_drive_data_index::T271_DRIVE_DATA_MODE);

   /*
    * Store the Previous Input Values
    */
   _InputDriverValuePrev = Read<float>(t271_drive_data_index::T271_DRIVE_DATA_INPUT_DRIVER_VALUE);
   _InputPassValuePrev = Read<float>(t271_drive_data_index::T271_DRIVE_DATA_INPUT_PASS_VALUE);
}

void Team271Drive::PostRobotPeriodic(const bool argIsParent)
{
   float tmpDriver = Read<float>(t271_drive_data_index::T271_DRIVE_DATA_DRIVER_VALUE);
   float tmpPassenger = Read<float>(t271_drive_data_index::T271_DRIVE_DATA_PASS_VALUE);

   /*const float batteryVoltage = frc::DriverStation::GetInstance().GetBatteryVoltage();*/

   /*
    * Driver Side
    */
   if (_TransDriver != nullptr)
   {
      /*
       if( Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) != SharedDataDrive_Continuous_.ModePrev_ )
       {
       if( Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) == 0 )
       {
       _TransDriver->Set( TEAM271_CONTROL_MODE_PERCENT_OUTPUT );
       }
       else if( Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) == 3 )
       {
       _TransDriver->Set( TEAM271_CONTROL_MODE_POSITION );
       }
       }

       if( Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) == 3 )
       {
       tmpDriver = (tmpDriver / WHEEL_CIRCUMFRENCE) * 4096.0;
       }
       */
      /*
       if( Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) == 1 )
       {
       tmpDriver = m_drivetrain.ControllerLeftVoltage() / batteryVoltage;
       }
       */
#if 0
      float Vintercept = ( 1.2 / 12 ) * 1023;
      float Kv = 0.626736178;
      float Ka = 0.18713812;

      if( tmpDriver < 0 )
      {
         Vintercept *= -1.0;
         Kv *= -1.0;
         Ka *= -1.0;
      }

      float tmpDriverF = Kv * 100 + Ka * 1.0 + Vintercept;

      if( ( tmpDriver > -0.03 && tmpDriver < 0.03 ) || Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) != 6 )
      {
         tmpDriverF = 0;
      }
      tmpDriverF = 0;

      if( Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) == 6 )
      {
         tmpDriver /= 0.1;
         tmpDriver /= DRIVE_ENCODER_CONST;
      }

      _TransDriver->SetOutput( tmpDriver,
            1.0f,
            tmpDriverF );
#endif
      _TransDriver->SetOutput(tmpDriver,
                              1.0f,
                              0);
   }

   /*
    * Passenger Side
    */
   if (_TransPassenger != nullptr)
   {
      /*
       if( Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) != SharedDataDrive_Continuous_.ModePrev_ )
       {
       if( Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) == 0 )
       {
       _TransPassenger->Set( TEAM271_CONTROL_MODE_PERCENT_OUTPUT );
       }
       else if( Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) == 3 )
       {
       _TransPassenger->Set( TEAM271_CONTROL_MODE_POSITION );
       }
       }

       if( Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) == 3 )
       {
       tmpPassenger = (tmpPassenger / WHEEL_CIRCUMFRENCE) * 4096.0;
       }
       */
      /*
       if( Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) == 1 )
       {
       tmpDriver = m_drivetrain.ControllerRightVoltage() / batteryVoltage;
       }
       */
#if 0
      float Vintercept = ( 1.2 / 12 ) * 1023;
      float Kv = 0.626736178;
      float Ka = 0.18713812;

      if( tmpPassenger < 0 )
      {
         Vintercept *= -1.0;
         Kv *= -1.0;
         Ka *= -1.0;
      }

      float tmpPassengerF = Kv * 100 + Ka * 1.0 + Vintercept;

      if( ( tmpPassenger > -0.03 && tmpPassenger < 0.03 ) || Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) != 6 )
      {
         tmpPassengerF = 0;
      }
      tmpPassengerF = 0;

      if( Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) == 6 )
      {
         tmpPassenger /= 0.1;
         tmpPassenger /= DRIVE_ENCODER_CONST;
      }

      _TransPassenger->SetOutput( tmpPassenger,
            1.0f,
            tmpPassengerF );
#endif
      _TransPassenger->SetOutput(tmpPassenger,
                                 1.0f,
                                 0);
   }

   /*
    if( _ClimbMode == 0 )
    {

    }
    else
    {
    _DriverValue = newPassenger * -1.0f;
    _PassengerValue = newDriver * -1.0f;
    }
    */

   /*
    * Base Call
    */
   Team271Base::PostRobotPeriodic();
}

void Team271Drive::DisabledInit(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::DisabledInit();

   /*
    * Stop Driving
    */
   SetNeutral();
}

void Team271Drive::AutonomousInit(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::AutonomousInit();

   /*
    * Stop Driving
    */
   SetNeutral();

   /*
    * Switch to Default Auto Gear
    */
   /*ShiftGears( DRIVE_DEFAULT_AUTO_GEAR );*/
#if defined(T271_AUTO_ENABLE)
   /*ShiftGears( _Auto->GetDriveGear() );*/
#endif
}

void Team271Drive::AutonomousPeriodic(const bool argIsParent)
{
   /*
    * Set Drive Values
    */
#if 0
   if( Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) == 0 )
   {
      /*m_drivetrain.Disable();*/
      /*
       m_thread.Stop();
       */

      if( ModePrev_ != Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) )
      {
         _TransDriver->SetControlMode( TEAM271_CONTROL_MODE_PERCENT_OUTPUT );
         _TransPassenger->SetControlMode( TEAM271_CONTROL_MODE_PERCENT_OUTPUT );
      }

      SetSetpoint( Read<float>( t271_drive_data_index::T271_DRIVE_DATA_INPUT_DRIVER_VALUE ),
            Read<float>( t271_drive_data_index::T271_DRIVE_DATA_INPUT_PASS_VALUE ) );
   }
   else if( Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) == 1 )
   {
      static float myInitalHeading = 0;

      if( ModePrev_ != Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) )
      {
         _TransDriver->SetControlMode( TEAM271_CONTROL_MODE_PERCENT_OUTPUT );
         _TransPassenger->SetControlMode( TEAM271_CONTROL_MODE_PERCENT_OUTPUT );

         myInitalHeading = GetIMU()->GetYaw();
      }

      float tmpDriverValue = Read<float>( t271_drive_data_index::T271_DRIVE_DATA_INPUT_DRIVER_VALUE );
      float tmpPassValue = Read<float>( t271_drive_data_index::T271_DRIVE_DATA_INPUT_PASS_VALUE );

      SetSetpoint( tmpDriverValue,
            tmpPassValue );
   }
   else if( Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) == 6 )
   {
      if( ModePrev_ != Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) )
      {
         _TransDriver->SetControlMode( TEAM271_CONTROL_MODE_VELOCITY );
         _TransPassenger->SetControlMode( TEAM271_CONTROL_MODE_VELOCITY );
      }
   }
   else if( Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) == 7 )
   {
      if( ModePrev_ != Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) )
      {
         _TransDriver->SetControlMode( TEAM271_CONTROL_MODE_MOTION_MAGIC );
         _TransPassenger->SetControlMode( TEAM271_CONTROL_MODE_MOTION_MAGIC );
      }
   }
#endif

   if (ModePrev_ != Read<uint8_t>(t271_drive_data_index::T271_DRIVE_DATA_MODE))
   {
      _TransDriver->SetControlMode(TEAM271_CONTROL_MODE_PERCENT_OUTPUT);
      _TransPassenger->SetControlMode(TEAM271_CONTROL_MODE_PERCENT_OUTPUT);
   }

   SetSetpoint(Read<float>(t271_drive_data_index::T271_DRIVE_DATA_INPUT_DRIVER_VALUE),
               Read<float>(t271_drive_data_index::T271_DRIVE_DATA_INPUT_PASS_VALUE));
}

void Team271Drive::TeleopInit(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::TeleopInit();

   /*
    * Stop Driving
    */
   /*SetNeutral();*/

   /*
    * Switch to Default Teleop Gear
    */
   /*ShiftGears( DRIVE_DEFAULT_TELEOP_GEAR );*/
}

void Team271Drive::TeleopPeriodic(const bool argIsParent)
{
   /*
    * Set Drive Values
    */
#if 0
   if( Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) == 0 )
   {
      /*m_drivetrain.Disable();*/
      /*
       m_thread.Stop();
       */

      if( ModePrev_ != Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) )
      {
         _TransDriver->SetControlMode( TEAM271_CONTROL_MODE_PERCENT_OUTPUT );
         _TransPassenger->SetControlMode( TEAM271_CONTROL_MODE_PERCENT_OUTPUT );
      }

      SetSetpoint( Read<float>( t271_drive_data_index::T271_DRIVE_DATA_INPUT_DRIVER_VALUE ),
            Read<float>( t271_drive_data_index::T271_DRIVE_DATA_INPUT_PASS_VALUE ) );
   }
   else if( Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) == 1 )
   {
      static float myInitalHeading = 0;

      if( ModePrev_ != Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) )
      {
         _TransDriver->SetControlMode( TEAM271_CONTROL_MODE_PERCENT_OUTPUT );
         _TransPassenger->SetControlMode( TEAM271_CONTROL_MODE_PERCENT_OUTPUT );

         myInitalHeading = GetIMU()->GetYaw();
      }

      float tmpDriverValue = Read<float>( t271_drive_data_index::T271_DRIVE_DATA_INPUT_DRIVER_VALUE );
      float tmpPassValue = Read<float>( t271_drive_data_index::T271_DRIVE_DATA_INPUT_PASS_VALUE );

      SetSetpoint( tmpDriverValue,
            tmpPassValue );
   }
   else if( Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) == 6 )
   {
      if( ModePrev_ != Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) )
      {
         _TransDriver->SetControlMode( TEAM271_CONTROL_MODE_VELOCITY );
         _TransPassenger->SetControlMode( TEAM271_CONTROL_MODE_VELOCITY );
      }
   }
   else if( Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) == 7 )
   {
      if( ModePrev_ != Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) )
      {
         _TransDriver->SetControlMode( TEAM271_CONTROL_MODE_MOTION_MAGIC );
         _TransPassenger->SetControlMode( TEAM271_CONTROL_MODE_MOTION_MAGIC );
      }
   }
#endif

   if (ModePrev_ != Read<uint8_t>(t271_drive_data_index::T271_DRIVE_DATA_MODE))
   {
      _TransDriver->SetControlMode(TEAM271_CONTROL_MODE_PERCENT_OUTPUT);
      _TransPassenger->SetControlMode(TEAM271_CONTROL_MODE_PERCENT_OUTPUT);
   }

   SetSetpoint(Read<float>(t271_drive_data_index::T271_DRIVE_DATA_INPUT_DRIVER_VALUE),
               Read<float>(t271_drive_data_index::T271_DRIVE_DATA_INPUT_PASS_VALUE));
}

/*
 *
 * Robot State
 *
 */
void Team271Drive::UpdateInput(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::UpdateInput();

   /*
    * Normal Throttle Drive
    */
   const float tmpDriverY = GetDriverAxisDriverY();
   const float tmpDriverX = GetDriverAxisDriverX();

   const float tmpPassengerY = GetDriverAxisPassengerY();
   const float tmpPassengerX = GetDriverAxisPassengerX();
   /*
    if( fabs(tmpDriverY - tmpPassengerY) < 0.10 )
    {
    tmpPassengerY = tmpDriverY;
    }
    */
   /*
    * Deadband and Deadband Scaling
    */
   float tmpDriverYDeadScale = 0;
   float tmpDriverXDeadScale = 0;
   float tmpPassengerYDeadScale = 0;
   float tmpPassengerXDeadScale = 0;

   /*
    * These must be floats
    */
   float tmpDriver = 0.0f;
   float tmpPassenger = 0.0f;

   ApplyRadialDeadZone(tmpDriverXDeadScale,
                       tmpDriverYDeadScale,
                       tmpDriverX,
                       tmpDriverY,
                       DRIVE_DEADZONE_LOW_DRIVER,
                       DRIVE_DEADZONE_HIGH_DRIVER);
   ApplyRadialDeadZone(tmpPassengerXDeadScale,
                       tmpPassengerYDeadScale,
                       tmpPassengerX,
                       tmpPassengerY,
                       DRIVE_DEADZONE_LOW_PASSENGER,
                       DRIVE_DEADZONE_HIGH_PASSENGER);

   /*
    * Apply a scaling factor for the different Gears
    */
   double tmpScaleFactor = 1.0;

#if defined(TANK_ENABLE)
   /*
   if (_DriveShifter != nullptr)
   {
      if (_DriveShifter->GetGear() == (eGear)DRIVE_LOW)
      {
         tmpScaleFactor = DRIVE_SCALE_LOW;
      }
      else
      {
         tmpScaleFactor = DRIVE_SCALE_HIGH;
      }
   }
*/
   tmpDriver = tmpScaleFactor * ( tmpDriverYDeadScale * tmpDriverYDeadScale * tmpDriverYDeadScale ) + ( DRIVE_INPUT_MAX_SCALE - tmpScaleFactor ) * tmpDriverYDeadScale;
   tmpPassenger = tmpScaleFactor * ( tmpPassengerYDeadScale * tmpPassengerYDeadScale * tmpPassengerYDeadScale ) + ( DRIVE_INPUT_MAX_SCALE - tmpScaleFactor ) * tmpPassengerYDeadScale;
#if 0
#if !defined(JOY_ENABLE)
   double tmpDriveFwd = Team271Input::Instance().GetAxis(eDriverLeft,
                                                         eDriverAxisDriveFwd);
   double tmpDriveRev = Team271Input::Instance().GetAxis(eDriverLeft,
                                                         eDriverAxisDriveRev);

   double tmpSteer = tmpScaleFactor * ( tmpPassengerXDeadScale * tmpPassengerXDeadScale * tmpPassengerXDeadScale ) + ( DRIVE_INPUT_MAX_SCALE - tmpScaleFactor ) * tmpPassengerXDeadScale;

   if (tmpDriveFwd > 0.0)
   {
      tmpDriver = tmpDriveFwd;
      tmpPassenger = tmpDriveFwd;
#if 0
      /* Apply a sin function that's scaled to make it feel better. */
      tmpSteer = sin(M_PI / 2.0 * kWheelNonlinearity * tmpSteer);
      tmpSteer = sin(M_PI / 2.0 * kWheelNonlinearity * tmpSteer);
      tmpSteer = tmpSteer / ( denominator * denominator ) * fabs(tmpDriveFwd);

      tmpSteer *= kWheelGain;

      DriveSignal signal = inverseKinematics(Twist2d(tmpDriveFwd,
                                                     0.0,
                                                     tmpSteer));

      double scaling_factor = max(1.0,
                                  max(fabs(signal.getLeft()),
                                      fabs(signal.getRight())));

      DriveSignal tmpSignal = DriveSignal(signal.getLeft() / scaling_factor,
                                          signal.getRight() / scaling_factor);

      tmpDriver = tmpSignal.getRight();
      tmpPassenger = tmpSignal.getLeft();
#endif
   }
   else if (tmpDriveRev > 0.0)
   {
      tmpDriver = tmpDriveRev * -1.0;
      tmpPassenger = tmpDriveRev * -1.0;
#if 0
      /* Apply a sin function that's scaled to make it feel better. */
      tmpSteer = sin(M_PI / 2.0 * kWheelNonlinearity * tmpSteer);
      tmpSteer = sin(M_PI / 2.0 * kWheelNonlinearity * tmpSteer);
      tmpSteer = tmpSteer / ( denominator * denominator ) * fabs(tmpDriveRev);

      tmpSteer *= kWheelGain;

      DriveSignal signal = inverseKinematics(Twist2d(tmpDriveRev,
                                                     0.0,
                                                     tmpSteer));

      double scaling_factor = max(1.0,
                                  max(fabs(signal.getLeft()),
                                      fabs(signal.getRight())));

      DriveSignal tmpSignal = DriveSignal(signal.getLeft() / scaling_factor,
                                          signal.getRight() / scaling_factor);

      tmpDriver = tmpSignal.getRight();
      tmpPassenger = tmpSignal.getLeft();
#endif
   }
#endif
#endif
#elif defined(CHEESY_ENABLE)
   double tmpThrottle = tmpScaleFactor * ( tmpDriverYDeadScale * tmpDriverYDeadScale * tmpDriverYDeadScale ) + ( DRIVE_INPUT_MAX_SCALE - tmpScaleFactor ) * tmpDriverYDeadScale;
   double tmpSteer = tmpScaleFactor * ( tmpPassengerXDeadScale * tmpPassengerXDeadScale * tmpPassengerXDeadScale ) + ( DRIVE_INPUT_MAX_SCALE - tmpScaleFactor ) * tmpPassengerXDeadScale;
/*
   if (Team271_EpsilonEquals(tmpThrottle,
                             0.0,
                             0.04))
   {
      tmpThrottle = 0.0;
   }

   if (Team271_EpsilonEquals(tmpSteer,
                             0.0,
                             0.035))
   {
      tmpSteer = 0.0;
   }
*/
/*
   DEBUG_PRINT("Drive",
               "tmpDriverYDeadScale: %f | tmpThrottle: %f | tmpPassengerXDeadScale: %f | tmpSteer: %f",
               tmpDriverYDeadScale,
               tmpThrottle,
               tmpPassengerXDeadScale,
               tmpSteer);
*/
   if (tmpThrottle < 0)
   {
      tmpSteer *= -1.0;
   }

   /* Apply a sin function that's scaled to make it feel better. */
#if !defined(JOY_ENABLE)
   /*if (Team271Input::Instance().GetButtonState(eDriverLeft,
                                               eDriverButtonDriveQuickTurn) == false )*/
   if (tmpThrottle != 0.0f)
   {
      tmpSteer = sin(M_PI / 2.0 * kWheelNonlinearity * tmpSteer);
      tmpSteer = sin(M_PI / 2.0 * kWheelNonlinearity * tmpSteer);
      tmpSteer = tmpSteer / ( denominator * denominator ) * fabs(tmpThrottle);

      tmpSteer *= kWheelGain;
   }
   else if (Team271Input::Instance().GetButtonState(eDriverLeft,
                                                    eDriverButtonDriveQuickTurn) == true )
   {
      if (_DriveShifter != nullptr)
      {
         if (_DriveShifter->GetGear() == (eGear)DRIVE_LOW)
         {
            tmpSteer *= 0.07;
         }
         else
         {
            tmpSteer *= 0.05;
         }
      }
   }
   else
   {
      if (_DriveShifter != nullptr)
      {
         if (_DriveShifter->GetGear() == (eGear)DRIVE_LOW)
         {
            tmpSteer *= 0.05;
         }
         else
         {
            tmpSteer *= 0.03;
         }
      }
   }
#else
   if (Team271Input::Instance().GetButtonState(eDriverLeft,
                                               5) == false && Team271Input::Instance().GetButtonState(eDriverLeft,
                                                                                                      6) == false)
   {
      tmpSteer = sin(M_PI / 2.0 * kWheelNonlinearity * tmpSteer);
      tmpSteer = sin(M_PI / 2.0 * kWheelNonlinearity * tmpSteer);
      tmpSteer = tmpSteer / ( denominator * denominator ) * fabs(tmpThrottle);
   }
#endif
/*
   printf("tmpSteer: %f ",
          tmpSteer);
*/
   /*tmpSteer *= kWheelGain;*/
/*
   printf("tmpSteer: %f | ",
          tmpSteer);
*/
   DriveSignal signal = inverseKinematics(Twist2d(tmpThrottle,
                                                  0.0,
                                                  tmpSteer));
/*
   printf("getLeft: %f | getRight: %f | ",
          signal.getLeft(),
          signal.getRight());
*/
   double scaling_factor = max(1.0,
                               max(fabs(signal.getLeft()),
                                   fabs(signal.getRight())));
/*
   printf("scaling_factor: %f | ",
          scaling_factor);
*/
   DriveSignal tmpSignal = DriveSignal(signal.getLeft() / scaling_factor,
                                       signal.getRight() / scaling_factor);

   tmpDriver = tmpSignal.getRight();
   tmpPassenger = tmpSignal.getLeft();
/*
   printf("tmpDriver: %f | tmpPassenger: %f\r\n",
          tmpDriver,
          tmpPassenger);
*/
/*
   DEBUG_PRINT("Drive",
               "tmpThrottle: %f | tmpSteer: %f | tmpDriver: %f | tmpPassenger: %f",
               tmpThrottle,
               tmpSteer,
               tmpDriver,
               tmpPassenger);
*/
#elif define(TEST)
   float tmpThrottle = tmpScaleFactor * ( tmpDriverYDeadScale * tmpDriverYDeadScale * tmpDriverYDeadScale ) + ( DRIVE_INPUT_MAX_SCALE - tmpScaleFactor ) * tmpDriverYDeadScale;
   float tmpSteer = tmpScaleFactor * ( tmpPassengerXDeadScale * tmpPassengerXDeadScale * tmpPassengerXDeadScale ) + ( DRIVE_INPUT_MAX_SCALE - tmpScaleFactor ) * tmpPassengerXDeadScale;

   float tmpDriver = tmpThrottle;
   float tmpPassenger = tmpThrottle;

   if (tmpThrottle > 0.0f)
   {
      if (tmpSteer > 0.0f)
      {
         tmpPassenger = tmpPassenger - tmpSteer;
      }
      else
      {
         tmpDriver = tmpDriver + tmpSteer;
      }
   }
   else
   {
      if (tmpSteer > 0)
      {
         tmpDriver = tmpDriver + tmpSteer;
      }
      else
      {
         tmpPassenger = tmpPassenger - tmpSteer;
      }
   }
   /*
    tmpDriver = Team271_Remap(tmpThrottle + tmpSteer,
    -2.0f,
    2.0f,
    -1.0f,
    1.0f);

    tmpPassenger = Team271_Remap(tmpThrottle - tmpSteer,
    -2.0f,
    2.0f,
    -1.0f,
    1.0f);
    */
   /*
    DEBUG_PRINT("Drive",
    "tmpThrottle: %f | tmpSteer: %f | tmpDriver: %f | tmpPassenger: %f",
    tmpThrottle,
    tmpSteer,
    tmpDriver,
    tmpPassenger);*/
#endif

   /*
    * Calculate the new Value
    * Cube the Input, scale to Max Value
    */
   Write(t271_drive_data_index::T271_DRIVE_DATA_INPUT_DRIVER_VALUE,
         tmpDriver);

   Write(t271_drive_data_index::T271_DRIVE_DATA_INPUT_PASS_VALUE,
         tmpPassenger);

#if defined( T271_INPUT_ENABLE )
   /*
    *
    * Shift
    *
    */
#if !defined(JOY_ENABLE)
   if (Team271Input::Instance().GetButtonState(eDriverLeft,
                                               eDriverButtonDriveLowGear) != Team271Input::Instance().GetButtonStatePrev(eDriverLeft,
                                                                                                                         eDriverButtonDriveLowGear))
   {
      if (Team271Input::Instance().GetButtonState(eDriverLeft,
                                                  eDriverButtonDriveLowGear) != 0)
      {
         ShiftGears(DRIVE_LOW);
      }
   }

   if (Team271Input::Instance().GetButtonState(eDriverLeft,
                                               eDriverButtonDriveHighGear) != Team271Input::Instance().GetButtonStatePrev(eDriverLeft,
                                                                                                                          eDriverButtonDriveHighGear))
   {
      if (Team271Input::Instance().GetButtonState(eDriverLeft,
                                                  eDriverButtonDriveHighGear) != 0)
      {
         ShiftGears(DRIVE_HIGH);
      }
   }
#else
   if (Team271Input::Instance().GetButtonState(eDriverRight,
                                               9) != Team271Input::Instance().GetButtonStatePrev(eDriverRight,
                                                                                                  9))
   {
      if (Team271Input::Instance().GetButtonState(eDriverRight,
                                                  9) != 0)
      {
         ShiftGears(DRIVE_LOW);
      }
   }
   if (Team271Input::Instance().GetButtonState(eDriverRight,
                                               10) != Team271Input::Instance().GetButtonStatePrev(eDriverRight,
                                                                                                  10))
   {
      if (Team271Input::Instance().GetButtonState(eDriverRight,
                                                  10) != 0)
      {
         ShiftGears(DRIVE_LOW);
      }
   }

   if (Team271Input::Instance().GetButtonState(eDriverLeft,
                                               9) != Team271Input::Instance().GetButtonStatePrev(eDriverLeft,
                                                                                                  9))
   {
      if (Team271Input::Instance().GetButtonState(eDriverLeft,
                                                  9) != 0)
      {
         ShiftGears(DRIVE_HIGH);
      }
   }
   if (Team271Input::Instance().GetButtonState(eDriverLeft,
                                               10) != Team271Input::Instance().GetButtonStatePrev(eDriverLeft,
                                                                                                  10))
   {
      if (Team271Input::Instance().GetButtonState(eDriverLeft,
                                                  10) != 0)
      {
         ShiftGears(DRIVE_HIGH);
      }
   }
#endif
   /*
    if( Team271Input::Instance().GetButtonState( eDriver, 1 ) != Team271Input::Instance().GetButtonStatePrev( eDriver, 1 ) )
    {
    if( Team271Input::Instance().GetButtonState( eDriver, 1 ) != 0 )
    {
    Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) = 2;
    }
    }

    if( Team271Input::Instance().GetButtonState( eDriver, 4 ) != Team271Input::Instance().GetButtonStatePrev( eDriver, 4 ) )
    {
    if( Team271Input::Instance().GetButtonState( eDriver, 4 ) != 0 )
    {
    Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) = 1;
    }
    }

    if( Team271Input::Instance().GetButtonState( eDriver, 2 ) != Team271Input::Instance().GetButtonStatePrev( eDriver, 2 ) )
    {
    if( Team271Input::Instance().GetButtonState( eDriver, 2 ) != 0 )
    {
    Read<uint8_t>( t271_drive_data_index::T271_DRIVE_DATA_MODE ) = 0;
    }
    }
    */
#endif
}

void Team271Drive::StateSpaceUpdate(void)
{
   /*
    m_drivetrain.SetMeasuredStates( _TransDriver->GetPosition(),
    _TransPassenger->GetPosition() );
    */
   // Run controller update
   /*
    auto now = std::chrono::steady_clock::now();
    if( m_lastTime != std::chrono::steady_clock::time_point::min() )
    {
    m_drivetrain.Update( now - m_lastTime );
    }
    else
    {
    m_drivetrain.Update();
    }

    m_lastTime = now;
    */
   /*
    m_drivetrain.Update();
    */
}

#endif
