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

#if defined( T271_ARM_ENABLE )

#define ARM_LIMIT_DOWN        (-1790)
#define ARM_LIMIT_UP          (-400)
#define ARM_LIMIT_BACK        (0)
#define ARM_LIMIT_UP_DEG      (180.0f)

#define ARM_LIMIT_DELTA       (ARM_LIMIT_BACK - ARM_LIMIT_DOWN)

#define ARM_CNTS_PER_DEG      (ARM_LIMIT_UP / 180.0f)

#define ARM_SETPOINT_TOL_DEG  (1.0f)

#define ARM_SETPOINT_LOW      (0.0f)
#define ARM_SETPOINT_MID      (35.0f)
#define ARM_SETPOINT_HIGH     (57.0f)

#define ARM_FF                (-0.08f)

static constexpr units::second_t kDt = 10_ms;

frc2::PIDController m_controller_arm {0.002,
                                      0.0000,
                                      0.00,
                                      kDt};

frc::TrapezoidProfile::Constraints m_constraints_arm {1.75_mps,
                                                      0.75_mps_sq};
frc::TrapezoidProfile::State m_goal_arm;
frc::TrapezoidProfile::State m_setpoint_arm;

Team271Arm::Team271Arm(void)
      : Team271Base(nullptr,
                    "Arm",
                    t271_arm_data_index::T271_DATA_COUNT)
{
   LOG_TRACE("%s - Constructor Start",
             GetName().c_str());

   LOG_TRACE("%s - Constructor End",
             GetName().c_str());
}

Team271Arm::~Team271Arm(void)
{

}

/*
 *
 * Getters
 *
 */
const string Team271Arm::GetClassName(void) const
{
   return "Team271Arm";
}

float Team271Arm::GetSetpoint(void) const
{
   return Read<float>(t271_arm_data_index::T271_ARM_DATA_SETPOINT);
}

float Team271Arm::GetOperatorArmAxisY(void) const
{
   /*
    * Get Arm Input
    */
#if defined(T271_INPUT_ENABLE)
   return Team271Input::Instance().GetAxis(eOperatorLeft,
                                           eOperatorLeftAxisArm) * -1.0;
#else
   return 0;
#endif
}

/*
 *
 * Setters
 *
 */
void Team271Arm::SetSetpoint(const float argSetpoint)
{
   Write(t271_arm_data_index::T271_ARM_DATA_SETPOINT,
         argSetpoint);
}

/*
 *
 * Base
 *
 */
void Team271Arm::Init(void)
{
   Team271Motor* tmpMasterMotor = nullptr;

   /*
    * Create Arm Transmission
    *
    * Add it to the Child List
    */
   _TransArm = Team271BaseManager::InstanceAdd(new Team271Transmission(this,
                                                                       "Arm"));
   if (_TransArm != nullptr)
   {
      /*
       * Add the motors
       */
      tmpMasterMotor = _TransArm->AddMotor("Arm 1",
                                           TEAM271_MOTOR_CONTROLLER_TYPE_SPARK_MAX_PWM,
                                           ARM_ONE_MOTOR);

      tmpMasterMotor->SetInvertedOutput(TEAM271_INVERTED_STATE_INVERTED);
      tmpMasterMotor->SetNeutralDeadband(0.05f);
      /*tmpMasterMotor->SetNeutralMode( TEAM271_NEUTRAL_MODE_BRAKE );

       tmpMasterMotor->SetOpenLoopRamp( 0.25 );*/

      /*
       * Setup Sensors
       */
#if 1
      _Encoder = new Team271SensorCTRE(_TransArm,
                                       "Team271Arm - Encoder",
                                       ARM_CANIFIER,
                                       (TEAM271_SENSOR_TYPE)(TEAM271_SENSOR_TYPE_MAG_REL | TEAM271_SENSOR_TYPE_LIMIT_REV),
                                       TEAM271_INVERTED_STATE_NOT_INVERTED,
                                       TEAM271_SENSOR_SETTINGS_CONTINUOUS,
                                       0);

      _TransArm->SetSensor(TEAM271_SENSOR_INDEX_ENCODER,
                           _Encoder);
#endif

      _TransArm->SetControlMode(TEAM271_CONTROL_MODE_PERCENT_OUTPUT);
   }

   m_controller_arm.SetTolerance(ARM_SETPOINT_TOL_DEG);
}

/*
 *
 * Robot
 *
 */
void Team271Arm::RobotInit(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::RobotInit();

   /*
    * Zero Position
    */
   if (_TransArm != nullptr)
   {
      SetSetpoint(_TransArm->GetNeutralValue());
   }

   /*
    * Set Position to 0
    */
   if (_Encoder != nullptr)
   {
      _Encoder->SetPosition(0);
   }
}

void Team271Arm::PreRobotPeriodic(const bool argIsParent)
{
   float tmpTransOutput = 0.0f;

   /*
    * Base Call
    */
   Team271Base::PreRobotPeriodic();

   ModePrev_ = Read<t271_arm_mode_t>(t271_arm_data_index::T271_ARM_DATA_MODE);

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
         _Encoder->SetPosition(ARM_LIMIT_BACK);
      }
   }
   else
   {
      /*
       * DSO or No Encoder Switch to Manual Control
       */
      Write(t271_arm_data_index::T271_ARM_DATA_MODE,
            T271_ARM_MODE_MANUAL);
   }

   /*
    * Check Mode
    */
   if (Read<uint8_t>(t271_arm_data_index::T271_ARM_DATA_MODE) == T271_ARM_MODE_PID)
   {
      /*
       * Calculate PID
       */
      tmpTransOutput = m_controller_arm.Calculate(_Encoder->GetPosition(),
                                                  GetSetpoint());
   }
   else
   {
      /*
       * Use User Input
       */
      tmpTransOutput = Read<float>(t271_arm_data_index::T271_ARM_DATA_INPUT);
   }

   /*
    * Apply Feed Forward
    */
   if (Team271Input::InstanceGetDSOState() != TEAM271_DSO_STATE_ACTIVE)
   {
      if (_Encoder->GetPosition() < ARM_LIMIT_UP)
      {
         tmpTransOutput += ARM_FF;
      }
   }

   /*
    * Store Value
    */
   Write(t271_arm_data_index::T271_ARM_DATA_VALUE,
         tmpTransOutput);
}

void Team271Arm::PostRobotPeriodic(const bool argIsParent)
{
   const int32_t tmpLowerLimit = 0;
   const int32_t tmpUpperLimit = ARM_LIMIT_DELTA;

   const float tmpOutput = Read<float>(t271_arm_data_index::T271_ARM_DATA_VALUE);

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
             m_controller_arm.GetPositionError(),
             m_controller_arm.GetVelocityError(),
             m_controller_arm.GetSetpoint(),
             m_controller_arm.AtSetpoint());
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
         Write(t271_arm_data_index::T271_ARM_DATA_CAN_MOVE,
               1);
      }
      else if ((_Encoder->GetPosition() < tmpUpperLimit) && (tmpOutput > 0))
      {
         Write(t271_arm_data_index::T271_ARM_DATA_CAN_MOVE,
               1);
      }
      else
      {
         Write(t271_arm_data_index::T271_ARM_DATA_CAN_MOVE,
               0);
      }
   }
   else
   {
      /*
       * Fail Safe Always Move
       */
      Write(t271_arm_data_index::T271_ARM_DATA_CAN_MOVE,
            1);
   }

#if defined(T271_INPUT_ENABLE)
   if (Team271Input::InstanceGetDSOState() == TEAM271_DSO_STATE_ACTIVE)
   {
      Write(t271_arm_data_index::T271_ARM_DATA_CAN_MOVE,
            1);
   }
#endif

   /*
    * Arm
    */
   if (_TransArm != nullptr)
   {
      if (Read<uint8_t>(t271_arm_data_index::T271_ARM_DATA_CAN_MOVE) == 0)
      {
         _TransArm->SetOutput(0);
      }
      else
      {
         _TransArm->SetOutput(tmpOutput);
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
void Team271Arm::DisabledInit(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::DisabledInit();

   /*
    * Stop Driving
    */
   if (_TransArm != nullptr)
   {
      SetSetpoint(_TransArm->GetNeutralValue());
   }

   m_controller_arm.Reset();

   Write(t271_arm_data_index::T271_ARM_DATA_MODE,
         T271_ARM_MODE_MANUAL);
}

void Team271Arm::AutonomousInit(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::AutonomousInit();

   /*
    * Stop Driving
    */
   if (_TransArm != nullptr)
   {
      SetSetpoint(_TransArm->GetNeutralValue());
   }
}

void Team271Arm::TeleopInit(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::TeleopInit();

   /*
    * Stop Driving
    */
   if (_TransArm != nullptr)
   {
      SetSetpoint(_TransArm->GetNeutralValue());
   }
}

void Team271Arm::TeleopPeriodic(const bool argIsParent)
{

}

void Team271Arm::TestInit(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::TestInit();

   /*
    * Stop Driving
    */
   if (_TransArm != nullptr)
   {
      SetSetpoint(_TransArm->GetNeutralValue());
   }
}

/*
 *
 * Robot State
 *
 */
void Team271Arm::UpdateInput(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::UpdateInput();

   /*
    * Store the Previous Value
    */
   Write(t271_arm_data_index::T271_ARM_DATA_INPUT_PREV,
         Read<float>(t271_arm_data_index::T271_ARM_DATA_INPUT));

   float tmpArmDown = (Team271Input::InstanceGetAxis(eOperatorLeft,
                                                     eOperatorLeftAxisElevationDown) + 1.0f) / 3.0f;

   tmpArmDown = tmpArmDown * tmpArmDown * tmpArmDown;

   if (tmpArmDown > 0.25)
   {
      tmpArmDown = 0.25;
   }

   float tmpArmUp = (Team271Input::InstanceGetAxis(eOperatorLeft,
                                                   eOperatorLeftAxisElevationUp) + 1.0f) / 3.0f;

   tmpArmUp = tmpArmUp * tmpArmUp * tmpArmUp;

   if (tmpArmUp > 0.3)
   {
      tmpArmUp = 0.3;
   }

   if (Team271Input::InstanceGetAxis(eOperatorLeft,
                                     eOperatorLeftAxisElevationDown) > 0.05 && tmpArmDown > 0.09)
   {
      Write(t271_arm_data_index::T271_ARM_DATA_INPUT,
            tmpArmDown);

      Write(t271_arm_data_index::T271_ARM_DATA_POSITION,
            _TransArm->GetPosition());
   }
   else if (Team271Input::InstanceGetAxis(eOperatorLeft,
                                          eOperatorLeftAxisElevationUp) > 0.05 && tmpArmUp > 0.09)
   {
      Write(t271_arm_data_index::T271_ARM_DATA_INPUT,
            tmpArmUp * -1.0f);

      Write(t271_arm_data_index::T271_ARM_DATA_POSITION,
            _Encoder->GetPosition());
   }
   else
   {
      if (_TransArm->GetPosition() > Read<float>(t271_arm_data_index::T271_ARM_DATA_POSITION))
      {
         Write(t271_arm_data_index::T271_ARM_DATA_INPUT,
               -0.08f);
      }
      else
      {
         Write(t271_arm_data_index::T271_ARM_DATA_INPUT,
               0.0f);
      }
   }

#if 0
#if defined(T271_INPUT_ENABLE)
   if (Team271Input::Instance().GetPOVState(eOperatorLeft,
                                            0) != Team271Input::Instance().GetPOVStatePrev(eOperatorLeft,
                                                                                           0))
   {
      if (Team271Input::Instance().GetPOVState(eOperatorLeft,
                                               0) == ePS4POV_North)
      {
         SetSetpoint(ARM_SETPOINT_HIGH);

         m_controller_arm.Reset();

         Write(t271_arm_data_index::T271_ARM_DATA_MODE,
               T271_ARM_MODE_PID);
      }
      if (Team271Input::Instance().GetPOVState(eOperatorLeft,
                                               0) == ePS4POV_West)
      {
         SetSetpoint(ARM_SETPOINT_MID);

         m_controller_arm.Reset();

         Write(t271_arm_data_index::T271_ARM_DATA_MODE,
               T271_ARM_MODE_PID);
      }
      if (Team271Input::Instance().GetPOVState(eOperatorLeft,
                                               0) == ePS4POV_East)
      {
         SetSetpoint(ARM_SETPOINT_MID);

         m_controller_arm.Reset();

         Write(t271_arm_data_index::T271_ARM_DATA_MODE,
               T271_ARM_MODE_PID);
      }
      if (Team271Input::Instance().GetPOVState(eOperatorLeft,
                                               0) == ePS4POV_South)
      {
         SetSetpoint(ARM_SETPOINT_LOW);

         m_controller_arm.Reset();

         Write(t271_arm_data_index::T271_ARM_DATA_MODE,
               T271_ARM_MODE_PID);
      }
   }
#endif
#endif
}
#endif
