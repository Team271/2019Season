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

#if defined( T271_LADDER_ENABLE )

#define LADDER_LIMIT_DOWN           (0)
#define LADDER_LIMIT_UP             (25000.0f)
#define LADDER_LIMIT_UP_IN          (57.0f)

#define LADDER_CNTS_PER_IN          (LADDER_LIMIT_UP / 55.0f)

#define LADDER_LIMIT_DELTA          (LADDER_LIMIT_UP-LADDER_LIMIT_DOWN)

#define LADDER_SETPOINT_TOL_IN      (0.1f)

#define LADDER_SETPOINT_LOW         (0.0f)
#define LADDER_SETPOINT_MID         (35.0f)
#define LADDER_SETPOINT_HIGH        (57.0f)

#define LADDER_FF_LOW               (0.06f)
#define LADDER_FF_HIGH              (0.08f)

static constexpr units::second_t kDt = 10_ms;

frc2::PIDController m_controller {0.4,
                                  0.005,
                                  0.00,
                                  kDt};

frc::TrapezoidProfile::Constraints m_constraints {5_mps,
                                                  1.5_mps_sq};
frc::TrapezoidProfile::State m_goal;
frc::TrapezoidProfile::State m_setpoint;

Team271Ladder::Team271Ladder(void)
      : Team271Base(nullptr,
                    "Ladder",
                    t271_ladder_data_index::T271_DATA_COUNT)
{
   LOG_TRACE("%s - Constructor Start",
             GetName().c_str() );

   LOG_TRACE("%s - Constructor End",
             GetName().c_str() );
}

Team271Ladder::~Team271Ladder(void)
{

}

/*
 *
 * Getters
 *
 */
const string Team271Ladder::GetClassName(void) const
{
   return "Team271Ladder";
}

float Team271Ladder::GetSetpoint(void) const
{
   return Read<float>(t271_ladder_data_index::T271_LADDER_DATA_SETPOINT);
}

bool Team271Ladder::GetClimbMode(void) const
{
   return Read<uint8_t>(t271_ladder_data_index::T271_LADDER_DATA_CLIMB_MODE);
}

float Team271Ladder::GetOperatorLadderAxisY(void) const
{
   /*
    * Get Ladder Input
    */
#if defined(T271_INPUT_ENABLE)
   return Team271Input::Instance().GetAxis(eOperatorLeft,
                                           eOperatorLeftAxisLadder) * -1.0;
#else
   return 0;
#endif
}

/*
 *
 * Setters
 *
 */
void Team271Ladder::SetSetpoint(const float argSetpoint)
{
   Write(t271_ladder_data_index::T271_LADDER_DATA_SETPOINT,
         argSetpoint);
}

void Team271Ladder::SetClimbMode(const bool argClimbMode)
{
   Write(t271_ladder_data_index::T271_LADDER_DATA_CLIMB_MODE,
         argClimbMode);
}

/*
 *
 * Base
 *
 */
void Team271Ladder::Init(void)
{
   Team271Motor *tmpMasterMotor = nullptr;
   Team271Motor *tmpSlaveMotor = nullptr;

   /*
    * Create Ladder Transmission
    *
    * Add it to the Child List
    */
   _TransLadder = Team271BaseManager::InstanceAdd(new Team271Transmission(this,
                                                                          "Ladder"));
   //Children_[LADDER_CHILD_INDEX_TRANS] = _TransLadder;

   if (_TransLadder != nullptr)
   {
      /*
       * Add the motors
       */
      tmpMasterMotor = _TransLadder->AddMotor("Ladder 1",
                                              TEAM271_MOTOR_CONTROLLER_TYPE_SPARK_MAX_PWM,
                                              LADDER_ONE_MOTOR,
                                              nullptr);

      tmpMasterMotor->SetInvertedOutput(TEAM271_INVERTED_STATE_NOT_INVERTED);
      tmpMasterMotor->SetNeutralMode(TEAM271_NEUTRAL_MODE_BRAKE);

      tmpMasterMotor->SetOpenLoopRamp(0.125);
      /*tmpMasterMotor->SetClosedLoopRamp( 0.25 );*/

      tmpMasterMotor->SetPeakFwdVoltage(0.1);
      tmpMasterMotor->SetPeakRevVoltage(-0.8);

      tmpMasterMotor->SetStatusFrameQuadEncoder(20);
      tmpMasterMotor->SetStatusFramePulseWidthMeas(20);

      tmpSlaveMotor = _TransLadder->AddMotor("Ladder 2",
                                             TEAM271_MOTOR_CONTROLLER_TYPE_SPARK_MAX_PWM,
                                             LADDER_TWO_MOTOR,
                                             tmpMasterMotor);

      tmpSlaveMotor = _TransLadder->AddMotor("Ladder 3",
                                             TEAM271_MOTOR_CONTROLLER_TYPE_SPARK_MAX_PWM,
                                             LADDER_THREE_MOTOR,
                                             tmpMasterMotor);

      /*
       * Create the Shifter - Speed
       */
      _ShifterSpeed = _TransLadder->SetShifter(TEAM271_SHIFTER_INDEX_1,
                                               new Team271Shifter_LadderSpeed(_TransLadder));

      /*
       * Create the Shifter - Break
       */
      _ShifterLock = _TransLadder->SetShifter(TEAM271_SHIFTER_INDEX_2,
                                              new Team271Shifter_LadderLock(_TransLadder));

      //_TransLadder->GetMasterTalon()->ConfigReverseSoftLimitThreshold( LADDER_LIMIT_DOWN, 10 );
      //_TransLadder->GetMasterTalon()->ConfigReverseSoftLimitEnable( true, 10 );

      //_TransLadder->GetMasterTalon()->ConfigForwardSoftLimitThreshold( LADDER_LIMIT_UP, 10 );
      //_TransLadder->GetMasterTalon()->ConfigForwardSoftLimitEnable( true, 10 );

      /*
       * Setup Sensors
       */
      _Encoder = new Team271SensorCTRE(_TransLadder,
                                       "Team271Ladder - Encoder",
                                       LADDER_CANIFIER,
                                       (TEAM271_SENSOR_TYPE)(TEAM271_SENSOR_TYPE_MAG_REL | TEAM271_SENSOR_TYPE_LIMIT_REV),
                                       TEAM271_INVERTED_STATE_INVERTED,
                                       TEAM271_SENSOR_SETTINGS_NONE,
                                       0);

      _TransLadder->SetSensor(TEAM271_SENSOR_INDEX_ENCODER,
                              _Encoder);

      _TransLadder->SetControlMode(TEAM271_CONTROL_MODE_PERCENT_OUTPUT);
   }

   m_controller.SetTolerance(LADDER_SETPOINT_TOL_IN);
}

/*
 *
 * Robot
 *
 */
void Team271Ladder::RobotInit(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::RobotInit();

   /*
    * Initialize Shifter
    */
   ShiftGears(LADDER_LOCK_OFF);
   ShiftGears(LADDER_DEFAULT_GEAR);

   /*
    * Zero Position
    */
   if (_TransLadder != nullptr)
   {
      SetSetpoint(_TransLadder->GetNeutralValue());
   }

   /*
    * Set Position to 0
    */
   if (_Encoder != nullptr)
   {
      _Encoder->SetPosition(0);
   }
}

void Team271Ladder::PreRobotPeriodic(const bool argIsParent)
{
   float tmpTransOutput = 0.0f;

   /*
    * Base Call
    */
   Team271Base::PreRobotPeriodic();

   ModePrev_ = Read<t271_ladder_mode_t>(t271_ladder_data_index::T271_LADDER_DATA_MODE);

   /*
    * Check for DSO
    */
#if defined(T271_INPUT_ENABLE)
   if ((Team271Input::InstanceGetDSOState() != TEAM271_DSO_STATE_ACTIVE) && (_Encoder != nullptr))
#else
   if (_Encoder != nullptr)
#endif
   {
      /*
       * Check for Limit Switches
       */
      if (_Encoder->GetLimitSWRev() == TEAM271_SENSOR_LIMIT_SW_STATE_CLOSED)
      {
         _Encoder->SetPosition(LADDER_LIMIT_DOWN);
      }
   }
   else
   {
      /*
       * DSO or No Encoder Switch to Manual Control
       */
      Write(t271_ladder_data_index::T271_LADDER_DATA_MODE,
            T271_LADDER_MODE_MANUAL);
   }

   /*
    * Check Mode
    */
   if (Read<uint8_t>(t271_ladder_data_index::T271_LADDER_DATA_MODE) == T271_LADDER_MODE_PID)
   {
      /*
       * Calculate PID
       */
      m_goal = {units::inch_t(GetSetpoint()),
                0_mps};

      frc::TrapezoidProfile profile {m_constraints,
                                     m_goal,
                                     m_setpoint};

      m_setpoint = profile.Calculate(kDt);

      tmpTransOutput = m_controller.Calculate(_Encoder->GetPosition() / LADDER_CNTS_PER_IN,
                                              units::inch_t(m_setpoint.position).to<double>());
   }
   else
   {
      /*
       * Use User Input
       */
      tmpTransOutput = Read<float>(t271_ladder_data_index::T271_LADDER_DATA_INPUT);
   }

   /*
    * Apply Feed Forward
    */
   if (Team271Input::InstanceGetDSOState() != TEAM271_DSO_STATE_ACTIVE)
   {
      if (_ShifterSpeed != nullptr)
      {
         if (_ShifterSpeed->GetGear() == (eGear)LADDER_LOW)
         {
            tmpTransOutput += LADDER_FF_LOW;
         }
         else
         {
            tmpTransOutput += LADDER_FF_HIGH;
         }
      }
   }

   /*
    * Store Value
    */
   Write(t271_ladder_data_index::T271_LADDER_DATA_VALUE,
         tmpTransOutput);
}

void Team271Ladder::PostRobotPeriodic(const bool argIsParent)
{
   const int32_t tmpLowerLimit = 0;
   const int32_t tmpUpperLimit = LADDER_LIMIT_DELTA;

   const float tmpOutput = Read<float>(t271_ladder_data_index::T271_LADDER_DATA_VALUE);

#if 0
   static uint32_t tmpCount = 0;

   if (tmpCount > 50)
   {
      tmpCount = 0;

      printf("GetPosition: %f | GetRate: %f | GetLimitSWFwd: %u | GetLimitSWRev: %u\r\n",
             _Encoder->GetPosition(),
             _Encoder->GetRate(),
             _Encoder->GetLimitSWFwd(),
             _Encoder->GetLimitSWRev());

      printf("tmpOutput: %f | GetPositionError: %f | GetVelocityError: %f | GetSetpoint: %f | AtSetpoint: %u\r\n\r\n",
             tmpOutput,
             m_controller.GetPositionError(),
             m_controller.GetVelocityError(),
             m_controller.GetSetpoint(),
             m_controller.AtSetpoint());
   }
   else
   {
      ++tmpCount;
   }
#endif

   /*
    * Check the Encoder
    */
   if (_Encoder != nullptr)
   {
      if ((_Encoder->GetPosition() > tmpLowerLimit) && (tmpOutput < 0))
      {
         Write(t271_ladder_data_index::T271_LADDER_DATA_CAN_MOVE,
               1);
      }
      else if ((_Encoder->GetPosition() < tmpUpperLimit) && (tmpOutput > 0))
      {
         Write(t271_ladder_data_index::T271_LADDER_DATA_CAN_MOVE,
               1);
      }
      else
      {
         Write(t271_ladder_data_index::T271_LADDER_DATA_CAN_MOVE,
               0);
      }
   }
   else
   {
      /*
       * Fail Safe Always Move
       */
      Write(t271_ladder_data_index::T271_LADDER_DATA_CAN_MOVE,
            1);
   }

#if defined(T271_INPUT_ENABLE)
   if (Team271Input::InstanceGetDSOState() == TEAM271_DSO_STATE_ACTIVE)
   {
      Write(t271_ladder_data_index::T271_LADDER_DATA_CAN_MOVE,
            1);
   }
#endif

   /*
    * Ladder
    */
   if (_TransLadder != nullptr)
   {
      if (Read<uint8_t>(t271_ladder_data_index::T271_LADDER_DATA_CAN_MOVE) == 0)
      {
         _TransLadder->SetOutput(0);
      }
      else
      {
         _TransLadder->SetOutput(tmpOutput);
      }
   }

   /*
    * Base Call
    */
   Team271Base::PostRobotPeriodic();
}

/*
 *
 * Disabled
 *
 */
void Team271Ladder::DisabledInit(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::DisabledInit();

   /*
    * Stop Driving
    */
   if (_TransLadder != nullptr)
   {
      SetSetpoint(_TransLadder->GetNeutralValue());
   }

   m_controller.Reset();

   Write(t271_ladder_data_index::T271_LADDER_DATA_MODE,
         T271_LADDER_MODE_MANUAL);
}

void Team271Ladder::AutonomousInit(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::AutonomousInit();

   /*
    * Stop Driving
    */
   if (_TransLadder != nullptr)
   {
      SetSetpoint(_TransLadder->GetNeutralValue());
   }

   /*
    * Switch to Default Auto Gear
    */
   ShiftGears(LADDER_LOCK_OFF);
   ShiftGears(LADDER_DEFAULT_AUTO_GEAR);
}

void Team271Ladder::TeleopInit(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::TeleopInit();

   /*
    * Stop Driving
    */
   if (_TransLadder != nullptr)
   {
      SetSetpoint(_TransLadder->GetNeutralValue());
   }

   /*
    * Switch to Default Teleop Gear
    */
   ShiftGears(LADDER_LOCK_OFF);
   ShiftGears(LADDER_DEFAULT_TELEOP_GEAR);
}

void Team271Ladder::TeleopPeriodic(const bool argIsParent)
{

}

void Team271Ladder::TestInit(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::TestInit();

   /*
    * Stop Driving
    */
   if (_TransLadder != nullptr)
   {
      SetSetpoint(_TransLadder->GetNeutralValue());
   }
}

/*
 *
 * Robot State
 *
 */
void Team271Ladder::UpdateInput(const bool argIsParent)
{
   float tmpInput = 0;

   /*
    * Base Call
    */
   Team271Base::UpdateInput();

   /*
    * Store the Previous Value
    */
   Write(t271_ladder_data_index::T271_LADDER_DATA_INPUT_PREV,
         Read<float>(t271_ladder_data_index::T271_LADDER_DATA_INPUT));

   /*
    * Normal Throttle Drive
    */
   const float tmpLadderY = GetOperatorLadderAxisY();

   /*
    * Deadband and Deadband Scaling
    */
   float tmpLadderXDeadScale = 0;
   float tmpLadderYDeadScale = 0;

   ApplyRadialDeadZone(tmpLadderXDeadScale,
                       tmpLadderYDeadScale,
                       0,
                       tmpLadderY,
                       LADDER_DEADZONE_LOW,
                       LADDER_DEADZONE_HIGH);

   /*
    * Apply a scaling factor for the different Gears
    */
   float tmpScaleFactor = 1.0f;

   if (_ShifterSpeed != nullptr)
   {
      if (_ShifterSpeed->GetGear() == (eGear)LADDER_LOW)
      {
         tmpScaleFactor = LADDER_SCALE_LOW;
      }
      else
      {
         tmpScaleFactor = LADDER_SCALE_HIGH;
      }
   }

   /*
    * Calculate the new Value
    * Cube the Input, scale to Max Value
    */
   tmpInput = tmpScaleFactor * (tmpLadderYDeadScale * tmpLadderYDeadScale * tmpLadderYDeadScale) + ( LADDER_INPUT_MAX_SCALE - tmpScaleFactor) * tmpLadderYDeadScale;

   if (tmpInput != 0.0f)
   {
      Write(t271_ladder_data_index::T271_LADDER_DATA_MODE,
            T271_LADDER_MODE_MANUAL);
   }

   if (tmpInput < -0.5)
   {
      tmpInput = -0.5;
   }

   Write(t271_ladder_data_index::T271_LADDER_DATA_INPUT,
         tmpInput);

#if defined(T271_INPUT_ENABLE)
   if (Team271Input::Instance().GetPOVState(eOperatorLeft,
                                            0) != Team271Input::Instance().GetPOVStatePrev(eOperatorLeft,
                                                                                           0))
   {
      if (Team271Input::Instance().GetPOVState(eOperatorLeft,
                                               0) == ePS4POV_North)
      {
         SetSetpoint(LADDER_SETPOINT_HIGH);

         m_controller.Reset();

         Write(t271_ladder_data_index::T271_LADDER_DATA_MODE,
               T271_LADDER_MODE_PID);
      }
      if (Team271Input::Instance().GetPOVState(eOperatorLeft,
                                               0) == ePS4POV_West)
      {
         SetSetpoint(LADDER_SETPOINT_MID);

         m_controller.Reset();

         Write(t271_ladder_data_index::T271_LADDER_DATA_MODE,
               T271_LADDER_MODE_PID);
      }
      if (Team271Input::Instance().GetPOVState(eOperatorLeft,
                                               0) == ePS4POV_East)
      {
         SetSetpoint(LADDER_SETPOINT_MID);

         m_controller.Reset();

         Write(t271_ladder_data_index::T271_LADDER_DATA_MODE,
               T271_LADDER_MODE_PID);
      }
      if (Team271Input::Instance().GetPOVState(eOperatorLeft,
                                               0) == ePS4POV_South)
      {
         SetSetpoint(LADDER_SETPOINT_LOW);

         m_controller.Reset();

         Write(t271_ladder_data_index::T271_LADDER_DATA_MODE,
               T271_LADDER_MODE_PID);
      }
   }

   /*
    *
    * Shift
    *
    */

   /*
    * Ladder Speed Shifter
    */
   if (Team271Input::Instance().GetButtonState(eOperatorLeft,
                                               PS4Button_Circle) != Team271Input::Instance().GetButtonStatePrev(eOperatorLeft,
                                                                                                                PS4Button_Circle))
   {
      if (Team271Input::Instance().GetButtonState(eOperatorLeft,
                                                  PS4Button_Circle) != 0)
      {
         ShiftGears(LADDER_LOW);
      }
   }

   if (Team271Input::Instance().GetButtonState(eOperatorLeft,
                                               PS4Button_Triangle) != Team271Input::Instance().GetButtonStatePrev(eOperatorLeft,
                                                                                                                  PS4Button_Triangle))
   {
      if (Team271Input::Instance().GetButtonState(eOperatorLeft,
                                                  PS4Button_Triangle) != 0)
      {
         ShiftGears(LADDER_HIGH);
      }
   }

   if (Team271Input::Instance().GetButtonState(eOperatorLeft,
                                               eOperatorLeftButtonDSOEnter) != Team271Input::Instance().GetButtonStatePrev(eOperatorLeft,
                                                                                                                           eOperatorLeftButtonDSOEnter))
   {
      if (Team271Input::Instance().GetButtonState(eOperatorLeft,
                                                  eOperatorLeftButtonDSOEnter) != 0)
      {
         Team271Input::Instance().SetDSOState(TEAM271_DSO_STATE_ENTER);
      }
   }
   else if (Team271Input::Instance().GetButtonState(eOperatorLeft,
                                                    eOperatorLeftButtonDSOExit) != Team271Input::Instance().GetButtonStatePrev(eOperatorLeft,
                                                                                                                            eOperatorLeftButtonDSOExit))
   {
      if (Team271Input::Instance().GetButtonState(eOperatorLeft,
                                                  eOperatorLeftButtonDSOExit) != 0)
      {
         Team271Input::Instance().SetDSOState(TEAM271_DSO_STATE_EXIT);
      }
   }

#endif
}

void Team271Ladder::ShiftGears(const eLadderGear argGear)
{
   if (_TransLadder != nullptr)
   {
      _TransLadder->ShiftGears(TEAM271_SHIFTER_INDEX_1,
                               (eGear)argGear);
   }
}

void Team271Ladder::ShiftGears(const eLadderLock argGear)
{
   if (_TransLadder != nullptr)
   {
      _TransLadder->ShiftGears(TEAM271_SHIFTER_INDEX_2,
                               (eGear)argGear);
   }
}

#endif
