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

#if defined(T271_MOTOR_ENABLE)

t271_motor_data_index::t271_motor_data_index(void)
{
   /*
    * Controller Type
    */
   Names_[T271_MOTOR_DATA_CONTROLLER_TYPE] = "T271_MOTOR_DATA_CONTROLLER_TYPE";

   /*
    * IDs
    */
   Names_[T271_MOTOR_DATA_ID] = "T271_MOTOR_DATA_ID";
   Names_[T271_MOTOR_DATA_ID_MASTER] = "T271_MOTOR_DATA_ID_MASTER";

   /*
    * Output Values
    */
   Names_[T271_MOTOR_DATA_VALUE_PREV] = "T271_MOTOR_DATA_VALUE_PREV";
   Names_[T271_MOTOR_DATA_VALUE_CURRENT] = "T271_MOTOR_DATA_VALUE_CURRENT";
   Names_[T271_MOTOR_DATA_VALUE_NEXT] = "T271_MOTOR_DATA_VALUE_NEXT";
   Names_[T271_MOTOR_DATA_VALUE_NEUTRAL] = "T271_MOTOR_DATA_VALUE_NEUTRAL";

   Names_[T271_MOTOR_DATA_ARB_FF_PREV] = "T271_MOTOR_DATA_ARB_FF_PREV";
   Names_[T271_MOTOR_DATA_ARB_FF_CURRENT] = "T271_MOTOR_DATA_ARB_FF_CURRENT";
   Names_[T271_MOTOR_DATA_ARB_FF_NEXT] = "T271_MOTOR_DATA_ARB_FF_NEXT";

   /*
    * Motion Magic
    */
   Names_[T271_MOTOR_DATA_CONTROL_MODE] = "T271_MOTOR_DATA_CONTROL_MODE";

   /*
    * Control Mode
    */
   Names_[T271_MOTOR_DATA_MM_VEL] = "T271_MOTOR_DATA_MM_VEL";
   Names_[T271_MOTOR_DATA_MM_ACCEL] = "T271_MOTOR_DATA_MM_ACCEL";

   /*
    * Status Frame Rates
    */
   Names_[T271_MOTOR_DATA_STATUS_FRAME_RATE_GENERAL] = "T271_MOTOR_DATA_STATUS_FRAME_RATE_GENERAL";
   Names_[T271_MOTOR_DATA_STATUS_FRAME_RATE_FEEDBACK] = "T271_MOTOR_DATA_STATUS_FRAME_RATE_FEEDBACK";
   Names_[T271_MOTOR_DATA_STATUS_FRAME_RATE_QUAD_ENCODER] = "T271_MOTOR_DATA_STATUS_FRAME_RATE_QUAD_ENCODER";
   Names_[T271_MOTOR_DATA_STATUS_FRAME_RATE_ANALOG_TEMP_VBAT] = "T271_MOTOR_DATA_STATUS_FRAME_RATE_ANALOG_TEMP_VBAT";
   Names_[T271_MOTOR_DATA_STATUS_FRAME_RATE_PULSE_WIDTH_MEAS] = "T271_MOTOR_DATA_STATUS_FRAME_RATE_PULSE_WIDTH_MEAS";
   Names_[T271_MOTOR_DATA_STATUS_FRAME_RATE_BASE_PIDF] = "T271_MOTOR_DATA_STATUS_FRAME_RATE_BASE_PIDF";
   Names_[T271_MOTOR_DATA_STATUS_FRAME_RATE_MOTION_MAGIC] = "T271_MOTOR_DATA_STATUS_FRAME_RATE_MOTION_MAGIC";

   /*
    * Status Frame Rates As Slave
    */
   Names_[T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_GENERAL] = "T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_GENERAL";
   Names_[T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_FEEDBACK] = "T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_FEEDBACK";
   Names_[T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_QUAD_ENCODER] = "T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_QUAD_ENCODER";
   Names_[T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_ANALOG_TEMP_VBAT] = "T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_ANALOG_TEMP_VBAT";
   Names_[T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_PULSE_WIDTH_MEAS] = "T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_PULSE_WIDTH_MEAS";
   Names_[T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_BASE_PIDF] = "T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_BASE_PIDF";
   Names_[T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_MOTION_MAGIC] = "T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_MOTION_MAGIC";

   /*
    * Output Settings
    */
   Names_[T271_MOTOR_DATA_INVERTED_OUTPUT] = "T271_MOTOR_DATA_INVERTED_OUTPUT";
   Names_[T271_MOTOR_DATA_NEUTRAL_MODE] = "T271_MOTOR_DATA_NEUTRAL_MODE";

   /*
    * Current Limiting
    */
   Names_[T271_MOTOR_DATA_CURRENT_LIMIT_ENABLE] = "T271_MOTOR_DATA_CURRENT_LIMIT_ENABLE";
   Names_[T271_MOTOR_DATA_PEAK_CURRENT_LIMIT] = "T271_MOTOR_DATA_PEAK_CURRENT_LIMIT";
   Names_[T271_MOTOR_DATA_PEAK_CURRENT_DURATION] = "T271_MOTOR_DATA_PEAK_CURRENT_DURATION";
   Names_[T271_MOTOR_DATA_CONTINUOUS_CURRENT_LIMIT] = "T271_MOTOR_DATA_CONTINUOUS_CURRENT_LIMIT";

   /*
    * Output Shaping
    */
   /* Seconds */
   Names_[T271_MOTOR_DATA_OPEN_LOOP_RAMP] = "T271_MOTOR_DATA_OPEN_LOOP_RAMP";
   Names_[T271_MOTOR_DATA_CLOSED_LOOP_RAMP] = "T271_MOTOR_DATA_CLOSED_LOOP_RAMP";

   /* Percent */
   Names_[T271_MOTOR_DATA_PEAK_VOLT_FWD] = "T271_MOTOR_DATA_PEAK_VOLT_FWD";
   Names_[T271_MOTOR_DATA_PEAK_VOLT_REV] = "T271_MOTOR_DATA_PEAK_VOLT_REV";

   /* Percent */
   Names_[T271_MOTOR_DATA_NOMINAL_VOLT_FWD] = "T271_MOTOR_DATA_NOMINAL_VOLT_FWD";
   Names_[T271_MOTOR_DATA_NOMINAL_VOLT_REV] = "T271_MOTOR_DATA_NOMINAL_VOLT_REV";

   /* Percent */
   Names_[T271_MOTOR_DATA_NEUTRAL_DEADBAND] = "T271_MOTOR_DATA_NEUTRAL_DEADBAND";

   Names_[T271_MOTOR_DATA_ENABLE_VOLT_COMP] = "T271_MOTOR_DATA_ENABLE_VOLT_COMP";
}

Team271Motor::Team271Motor(Team271Base* const argParent,
                           const string& argMotorName,
                           const TEAM271_MOTOR_CONTROLLER_TYPE argControllerType,
                           const uint32_t argControlID,
                           Team271Motor* const argMasterMotor)
      : Team271Base(argParent,
                    argMotorName,
                    t271_motor_data_index::T271_DATA_COUNT),
        MasterMotor_(argMasterMotor)
{
   LOG_TRACE("%s - Constructor Start",
             GetName().c_str() );

   /*
    * Store Parameters
    */
   Write(t271_motor_data_index::T271_MOTOR_DATA_CONTROLLER_TYPE,
         argControllerType);

   Write(t271_motor_data_index::T271_MOTOR_DATA_ID,
         argControlID);

   /*
    * Status Frame Rates
    */
   /* Default: 10ms */
   Write(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_GENERAL,
         10U);

   /* Default: 20ms */
   Write(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_FEEDBACK,
         20U);

   /* Default: 160ms */
   Write(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_QUAD_ENCODER,
         250U);

   /* Default: 160ms */
   Write(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_ANALOG_TEMP_VBAT,
         250U);

   /* Default: 160ms */
   Write(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_PULSE_WIDTH_MEAS,
         250U);

   /* Default: ??ms */
   Write(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_BASE_PIDF,
         10U);

   /* Default: ??ms */
   Write(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_MOTION_MAGIC,
         10U);

   /*
    * Status Frame Rates As Slave
    */
   /* Default: 10ms */
   Write(t271_motor_data_index::T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_GENERAL,
         250U);

   /* Default: 20ms */
   Write(t271_motor_data_index::T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_FEEDBACK,
         250U);

   /* Default: 160ms */
   Write(t271_motor_data_index::T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_QUAD_ENCODER,
         250U);

   /* Default: 160ms */
   Write(t271_motor_data_index::T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_ANALOG_TEMP_VBAT,
         250U);

   /* Default: 160ms */
   Write(t271_motor_data_index::T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_PULSE_WIDTH_MEAS,
         250U);

   /* Default: ??ms */
   Write(t271_motor_data_index::T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_BASE_PIDF,
         250U);

   /* Default: ??ms */
   Write(t271_motor_data_index::T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_MOTION_MAGIC,
         250U);

   /*
    * Output Settings
    */
   Write(t271_motor_data_index::T271_MOTOR_DATA_INVERTED_OUTPUT,
         TEAM271_INVERTED_STATE_NOT_INVERTED);

   Write(t271_motor_data_index::T271_MOTOR_DATA_NEUTRAL_MODE,
         TEAM271_NEUTRAL_MODE_COAST);

   /*
    * Output Shaping
    */
   /* Percent */
   Write(t271_motor_data_index::T271_MOTOR_DATA_PEAK_VOLT_FWD,
         1.0f);

   Write(t271_motor_data_index::T271_MOTOR_DATA_PEAK_VOLT_REV,
         -1.0f);

   /* Percent */
   Write(t271_motor_data_index::T271_MOTOR_DATA_NEUTRAL_DEADBAND,
         0.04f);

   LOG_TRACE("%s - Constructor End",
             GetName().c_str() );
}

Team271Motor::~Team271Motor(void)
{
#if defined(T271_CTRE)
   if (MotorController_ != nullptr)
   {
      delete MotorController_;
      MotorController_ = nullptr;
   }
#endif
#if 0
   if( MotorControllerPWM_ != nullptr )
   {
      delete MotorControllerPWM_;
      MotorControllerPWM_ = nullptr;
   }
#endif
}

/*
 *
 * Getters
 *
 */
const string Team271Motor::GetClassName(void) const
{
   return "Team271Motor";
}

const Team271Motor* Team271Motor::GetMaster(void) const
{
   return MasterMotor_;
}

uint32_t Team271Motor::GetIDControl(void) const
{
   return Read<uint8_t>(t271_motor_data_index::T271_MOTOR_DATA_ID);
}

TEAM271_CONTROL_MODE Team271Motor::GetControlMode(void) const
{
   return Read<TEAM271_CONTROL_MODE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROL_MODE);
}

/*
 * Output Values
 */
float Team271Motor::GetValuePrev(void) const
{
   return Read<float>(t271_motor_data_index::T271_MOTOR_DATA_VALUE_PREV);
}

float Team271Motor::GetValueCurrent(void) const
{
   return Read<float>(t271_motor_data_index::T271_MOTOR_DATA_VALUE_CURRENT);
}

float Team271Motor::GetValueNext(void) const
{
   return Read<float>(t271_motor_data_index::T271_MOTOR_DATA_VALUE_NEXT);
}

float Team271Motor::GetValueNeutral(void) const
{
   float tmpValue = Read<float>(t271_motor_data_index::T271_MOTOR_DATA_VALUE_NEUTRAL);

   /*
    * Position Neutral Value is the Current Value
    */
   if (Read<TEAM271_CONTROL_MODE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROL_MODE) == TEAM271_CONTROL_MODE_POSITION)
   {
      tmpValue = Read<float>(t271_motor_data_index::T271_MOTOR_DATA_VALUE_CURRENT);
   }

   return tmpValue;
}

/*
 * Motor Controllers
 */
#if defined(T271_CTRE)
BaseMotorController* Team271Motor::GetBaseMotorController(void) const
{
   return MotorController_;
}

TalonSRX* Team271Motor::GetTalon(void) const
{
   return dynamic_cast<TalonSRX*>(MotorController_);
}

VictorSPX* Team271Motor::GetVictor(void) const
{
   return dynamic_cast<VictorSPX*>(MotorController_);
}
#endif

Team271PWM* Team271Motor::GetPWM(void) const
{
   return MotorControllerPWM_;
}

/*
 * Power
 */
float Team271Motor::GetBusVoltage(void) const
{
   float tmpVoltage = 0;

#if defined(T271_CTRE)
   if (( MotorController_ == nullptr ) && ( MotorControllerPWM_ == nullptr ))
   {
      LOG_ERROR("%s - No Motor Controller",
                GetName().c_str());
   }
   else if (Read<TEAM271_MOTOR_CONTROLLER_TYPE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROLLER_TYPE) == TEAM271_MOTOR_CONTROLLER_TYPE_TALON_SRX)
   {
      TalonSRX* const tmpSRX = dynamic_cast<TalonSRX*>(MotorController_);

      if (tmpSRX != nullptr)
      {
         tmpVoltage = tmpSRX->GetBusVoltage();
      }
   }
   else if (Read<TEAM271_MOTOR_CONTROLLER_TYPE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROLLER_TYPE) == TEAM271_MOTOR_CONTROLLER_TYPE_VICTOR_SPX)
   {
      VictorSPX* const tmpSPX = dynamic_cast<VictorSPX*>(MotorController_);

      if (tmpSPX != nullptr)
      {
         tmpVoltage = tmpSPX->GetBusVoltage();
      }
   }
   else if (Read<TEAM271_MOTOR_CONTROLLER_TYPE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROLLER_TYPE) == TEAM271_MOTOR_CONTROLLER_TYPE_SPARK
         || Read<TEAM271_MOTOR_CONTROLLER_TYPE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROLLER_TYPE) == TEAM271_MOTOR_CONTROLLER_TYPE_SPARK_MAX_PWM)
   {
      tmpVoltage = Team271PDP::getInstance().GetBusVoltage();
   }
   else
   {
      LOG_ERROR("%s - Motor Controller Unsupported",
                GetName().c_str());
   }
#else
   tmpVoltage = Team271PDP::getInstance().GetBusVoltage();
#endif

   return tmpVoltage;
}

float Team271Motor::GetOutputVoltage(void) const
{
   float tmpVoltage = 0;

#if defined(T271_CTRE)
   if (MotorController_ == nullptr)
   {
      LOG_ERROR("%s - No Motor Controller",
                GetName().c_str());
   }
   else if (Read<TEAM271_MOTOR_CONTROLLER_TYPE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROLLER_TYPE) == TEAM271_MOTOR_CONTROLLER_TYPE_TALON_SRX)
   {
      TalonSRX* const tmpSRX = dynamic_cast<TalonSRX*>(MotorController_);

      if (tmpSRX != nullptr)
      {
         tmpVoltage = tmpSRX->GetMotorOutputVoltage();
      }
   }
   else if (Read<TEAM271_MOTOR_CONTROLLER_TYPE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROLLER_TYPE) == TEAM271_MOTOR_CONTROLLER_TYPE_VICTOR_SPX)
   {
      VictorSPX* const tmpSPX = dynamic_cast<VictorSPX*>(MotorController_);

      if (tmpSPX != nullptr)
      {
         tmpVoltage = tmpSPX->GetMotorOutputVoltage();
      }
   }
   else
   {
      LOG_ERROR("%s - Motor Controller Unsupported",
                GetName().c_str());
   }
#endif

   return tmpVoltage;
}

float Team271Motor::GetOutputCurrent(void) const
{
   float tmpCurrent = 0;

#if defined(T271_CTRE)
   if (MotorController_ == nullptr)
   {
      LOG_ERROR("%s - No Motor Controller",
                GetName().c_str());
   }
   else if (Read<TEAM271_MOTOR_CONTROLLER_TYPE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROLLER_TYPE) == TEAM271_MOTOR_CONTROLLER_TYPE_TALON_SRX)
   {
      TalonSRX* const tmpSRX = dynamic_cast<TalonSRX*>(MotorController_);

      if (tmpSRX != nullptr)
      {
         tmpCurrent = tmpSRX->GetOutputCurrent();
      }
   }
   else
   {
      LOG_ERROR("%s - Motor Controller Unsupported",
                GetName().c_str());
   }
#else
   /*tmpCurrent = Team271PDP::getInstance().GetCurrent( GetIDControl() );*/
#endif

   return tmpCurrent;
}

/*
 *
 * Setters
 *
 */
void Team271Motor::SetMaster(const Team271Motor* const argMasterMotor)
{
   if (argMasterMotor == nullptr)
   {
      LOG_ERROR("%s - Invalid Master Motor",
                GetName().c_str());
   }
   else
   {
      /*
       * - Store Master
       * - Store Master ID
       */
      MasterMotor_ = argMasterMotor;

      Write(t271_motor_data_index::T271_MOTOR_DATA_ID_MASTER,
            argMasterMotor->Read<uint8_t>(t271_motor_data_index::T271_MOTOR_DATA_ID));

      /*
       * Setup as Follower
       * - Setup Status Frames
       * - Change the Control Mode
       */
      SetStatusFrameGeneral(Read<uint32_t>(t271_motor_data_index::T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_GENERAL));
      SetStatusFrameFeedback(Read<uint32_t>(t271_motor_data_index::T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_FEEDBACK));
      SetStatusFrameQuadEncoder(Read<uint32_t>(t271_motor_data_index::T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_QUAD_ENCODER));
      SetStatusFrameAnalogTempVbat(Read<uint32_t>(t271_motor_data_index::T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_ANALOG_TEMP_VBAT));
      SetStatusFramePulseWidthMeas(Read<uint32_t>(t271_motor_data_index::T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_PULSE_WIDTH_MEAS));
      SetStatusFrameBasePIDF(Read<uint32_t>(t271_motor_data_index::T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_BASE_PIDF));
      SetStatusFrameMotionMagic(Read<uint32_t>(t271_motor_data_index::T271_MOTOR_DATA_SLAVE_STATUS_FRAME_RATE_MOTION_MAGIC));

      SetControlMode(TEAM271_CONTROL_MODE_FOLLOWER);
   }
}

void Team271Motor::SetControlMode(const TEAM271_CONTROL_MODE argSetControlMode)
{
   /*
    * Check if there is a valid Motor Controller
    */
#if defined(T271_CTRE)
   if (( MotorController_ == nullptr ) && ( MotorControllerPWM_ == nullptr ))
#else
   if( MotorControllerPWM_ == nullptr )
#endif
   {
      LOG_ERROR("%s - No Motor Controller",
                GetName().c_str());
   }
   else
   {
      /*
       * Store the new value appropriately
       */
      Write(t271_motor_data_index::T271_MOTOR_DATA_CONTROL_MODE,
            argSetControlMode);

#if defined(T271_CTRE)
      if (MotorController_ != nullptr)
      {
         /*
          * Apply the new value appropriately
          *
          * Will also Stop the Motor
          */
         if (Read<TEAM271_CONTROL_MODE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROL_MODE) == TEAM271_CONTROL_MODE_DISABLED)
         {
#if defined( ENABLE_DEBUG_PRINTING_TRACE )
            DEBUG_PRINT_FUNC( GetName().c_str(),
                  T271_FUNC_NAME,
                  "TEAM271_CONTROL_MODE_DISABLED" );
#endif

            MotorController_->Set(ControlMode::Disabled,
                                  0);
         }
         else if (Read<TEAM271_CONTROL_MODE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROL_MODE) == TEAM271_CONTROL_MODE_PERCENT_OUTPUT)
         {
#if defined( ENABLE_DEBUG_PRINTING_TRACE )
            DEBUG_PRINT_FUNC( GetName().c_str(),
                  T271_FUNC_NAME,
                  "TEAM271_CONTROL_MODE_PERCENT_OUTPUT" );
#endif

            MotorController_->Set(ControlMode::PercentOutput,
                                  GetValueNeutral());
         }
         else if (Read<TEAM271_CONTROL_MODE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROL_MODE) == TEAM271_CONTROL_MODE_CURRENT)
         {
#if defined( ENABLE_DEBUG_PRINTING_TRACE )
            DEBUG_PRINT_FUNC( GetName().c_str(),
                  T271_FUNC_NAME,
                  "TEAM271_CONTROL_MODE_CURRENT" );
#endif

            MotorController_->Set(ControlMode::Current,
                                  GetValueNeutral());
         }
         else if (Read<TEAM271_CONTROL_MODE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROL_MODE) == TEAM271_CONTROL_MODE_FOLLOWER)
         {
#if defined( ENABLE_DEBUG_PRINTING_TRACE )
            DEBUG_PRINT_FUNC( GetName().c_str(),
                  T271_FUNC_NAME,
                  "TEAM271_CONTROL_MODE_FOLLOWER" );
#endif

            if (MasterMotor_ != nullptr)
            {
               MotorController_->Follow(*MasterMotor_->GetBaseMotorController());
            }
            else
            {
               MotorController_->Set(ControlMode::Follower,
                                     Read<uint8_t>(t271_motor_data_index::T271_MOTOR_DATA_ID_MASTER));
            }
         }
         else if (Read<TEAM271_CONTROL_MODE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROL_MODE) == TEAM271_CONTROL_MODE_POSITION)
         {
#if defined( ENABLE_DEBUG_PRINTING_TRACE )
            DEBUG_PRINT_FUNC( GetName().c_str(),
                  T271_FUNC_NAME,
                  "TEAM271_CONTROL_MODE_POSITION" );
#endif

            MotorController_->Set(ControlMode::Position,
                                  GetValueNeutral());
         }
         else if (Read<TEAM271_CONTROL_MODE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROL_MODE) == TEAM271_CONTROL_MODE_VELOCITY)
         {
#if defined( ENABLE_DEBUG_PRINTING_TRACE )
            DEBUG_PRINT_FUNC( GetName().c_str(),
                  T271_FUNC_NAME,
                  "TEAM271_CONTROL_MODE_VELOCITY" );
#endif

            MotorController_->Set(ControlMode::Velocity,
                                  GetValueNeutral());
         }
         else if (Read<TEAM271_CONTROL_MODE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROL_MODE) == TEAM271_CONTROL_MODE_MOTION_MAGIC)
         {
#if defined( ENABLE_DEBUG_PRINTING_TRACE )
            DEBUG_PRINT_FUNC( GetName().c_str(),
                  T271_FUNC_NAME,
                  "TEAM271_CONTROL_MODE_MOTION_MAGIC" );
#endif

            MotorController_->Set(ControlMode::MotionMagic,
                                  GetValueNeutral());
         }
         else
         {
            LOG_ERROR("%s - Invalid Control Mode",
                      GetName().c_str());

            MotorController_->Set(ControlMode::PercentOutput,
                                  GetValueNeutral());
         }
      }
#else
      if( MotorControllerPWM_ != nullptr )
      {
         /*
          * Apply the new value appropriately
          *
          * Will also Stop the Motor
          */
         if( Read<TEAM271_CONTROL_MODE>( t271_motor_data_index::T271_MOTOR_DATA_CONTROL_MODE ) == TEAM271_CONTROL_MODE_DISABLED )
         {
#if defined( ENABLE_DEBUG_PRINTING_TRACE )
            DEBUG_PRINT_FUNC( GetName().c_str(),
                  T271_FUNC_NAME,
                  "TEAM271_CONTROL_MODE_DISABLED" );
#endif

            MotorControllerPWM_->Set( 0.0 );
         }
         else if( Read<TEAM271_CONTROL_MODE>( t271_motor_data_index::T271_MOTOR_DATA_CONTROL_MODE ) == TEAM271_CONTROL_MODE_PERCENT_OUTPUT )
         {
#if defined( ENABLE_DEBUG_PRINTING_TRACE )
            DEBUG_PRINT_FUNC( GetName().c_str(),
                  T271_FUNC_NAME,
                  "TEAM271_CONTROL_MODE_PERCENT_OUTPUT" );
#endif

            MotorControllerPWM_->Set( GetValueNeutral() );
         }
         else if( Read<TEAM271_CONTROL_MODE>( t271_motor_data_index::T271_MOTOR_DATA_CONTROL_MODE ) == TEAM271_CONTROL_MODE_FOLLOWER )
         {
#if defined( ENABLE_DEBUG_PRINTING_TRACE )
            DEBUG_PRINT_FUNC( GetName().c_str(),
                  T271_FUNC_NAME,
                  "TEAM271_CONTROL_MODE_FOLLOWER" );
#endif
         }
         else
         {
            LOG_ERROR( "%s - Invalid Control Mode",
                  GetName().c_str() );

            MotorControllerPWM_->Set( GetValueNeutral() );
         }
      }
#endif
   }
}

void Team271Motor::SetStatusFrameGeneral(const uint32_t argMilliSecs)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_GENERAL,
         argMilliSecs);

#if defined(T271_CTRE)
   if (MotorController_ != nullptr)
   {
      MotorController_->SetStatusFramePeriod(StatusFrameEnhanced::Status_1_General,
                                             Read<uint32_t>(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_GENERAL),
                                             _StatusFrameRateTimeout);
   }
#endif
}

void Team271Motor::SetStatusFrameFeedback(const uint32_t argMilliSecs)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_FEEDBACK,
         argMilliSecs);

#if defined(T271_CTRE)
   if (MotorController_ != nullptr)
   {
      MotorController_->SetStatusFramePeriod(StatusFrameEnhanced::Status_2_Feedback0,
                                             Read<uint32_t>(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_FEEDBACK),
                                             _StatusFrameRateTimeout);
   }
#endif
}

void Team271Motor::SetStatusFrameQuadEncoder(const uint32_t argMilliSecs)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_QUAD_ENCODER,
         argMilliSecs);

#if defined(T271_CTRE)
   if (MotorController_ != nullptr)
   {
      MotorController_->SetStatusFramePeriod(StatusFrameEnhanced::Status_3_Quadrature,
                                             Read<uint32_t>(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_QUAD_ENCODER),
                                             _StatusFrameRateTimeout);
   }
#endif
}

void Team271Motor::SetStatusFrameAnalogTempVbat(const uint32_t argMilliSecs)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_ANALOG_TEMP_VBAT,
         argMilliSecs);

#if defined(T271_CTRE)
   if (MotorController_ != nullptr)
   {
      MotorController_->SetStatusFramePeriod(StatusFrameEnhanced::Status_4_AinTempVbat,
                                             Read<uint32_t>(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_ANALOG_TEMP_VBAT),
                                             _StatusFrameRateTimeout);
   }
#endif
}

void Team271Motor::SetStatusFramePulseWidthMeas(const uint32_t argMilliSecs)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_PULSE_WIDTH_MEAS,
         argMilliSecs);

#if defined(T271_CTRE)
   if (MotorController_ != nullptr)
   {
      MotorController_->SetStatusFramePeriod(StatusFrameEnhanced::Status_8_PulseWidth,
                                             Read<uint32_t>(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_PULSE_WIDTH_MEAS),
                                             _StatusFrameRateTimeout);
   }
#endif
}

void Team271Motor::SetStatusFrameBasePIDF(const uint32_t argMilliSecs)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_BASE_PIDF,
         argMilliSecs);

#if defined(T271_CTRE)
   if (MotorController_ != nullptr)
   {
      MotorController_->SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0,
                                             Read<uint32_t>(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_BASE_PIDF),
                                             _StatusFrameRateTimeout);
   }
#endif
}

void Team271Motor::SetStatusFrameMotionMagic(const uint32_t argMilliSecs)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_MOTION_MAGIC,
         argMilliSecs);

#if defined(T271_CTRE)
   if (MotorController_ != nullptr)
   {
      MotorController_->SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic,
                                             Read<uint32_t>(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_MOTION_MAGIC),
                                             _StatusFrameRateTimeout);
   }
#endif
}

void Team271Motor::SetInvertedOutput(const TEAM271_INVERTED_STATE argInvertedOutput)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_INVERTED_OUTPUT,
         argInvertedOutput);

#if defined(T271_CTRE)
   if (MotorController_ != nullptr)
   {
      if (Read<TEAM271_INVERTED_STATE>(t271_motor_data_index::T271_MOTOR_DATA_INVERTED_OUTPUT) == TEAM271_INVERTED_STATE_INVERTED)
      {
         MotorController_->SetInverted(true);
      }
      else
      {
         MotorController_->SetInverted(false);
      }
   }
   else if (MotorControllerPWM_ != nullptr)
   {
      MotorControllerPWM_->SetInverted(Read<TEAM271_INVERTED_STATE>(t271_motor_data_index::T271_MOTOR_DATA_INVERTED_OUTPUT));
   }
#else
   if( MotorControllerPWM_ != nullptr )
   {
      MotorControllerPWM_->SetInverted( Read<TEAM271_INVERTED_STATE>( t271_motor_data_index::T271_MOTOR_DATA_INVERTED_OUTPUT ) );
   }
#endif
}

void Team271Motor::SetNeutralMode(const TEAM271_NEUTRAL_MODE argNeutralMode)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_NEUTRAL_MODE,
         argNeutralMode);

#if defined(T271_CTRE)
   if (MotorController_ != nullptr)
   {
      if (Read<TEAM271_NEUTRAL_MODE>(t271_motor_data_index::T271_MOTOR_DATA_NEUTRAL_MODE) == TEAM271_NEUTRAL_MODE_BRAKE)
      {
         MotorController_->SetNeutralMode(NeutralMode::Brake);
      }
      else
      {
         MotorController_->SetNeutralMode(NeutralMode::Coast);
      }
   }
#endif
}

void Team271Motor::SetPeakCurrentLimit(const float argCurrentLimit)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_PEAK_CURRENT_LIMIT,
         argCurrentLimit);

#if defined(T271_CTRE)
   TalonSRX* const tmpSRX = dynamic_cast<TalonSRX*>(MotorController_);

   if (tmpSRX != nullptr)
   {
      tmpSRX->ConfigPeakCurrentLimit(Read<float>(t271_motor_data_index::T271_MOTOR_DATA_PEAK_CURRENT_LIMIT),
                                     _StatusFrameRateTimeout);
   }
#endif
}

void Team271Motor::SetPeakCurrentDuration(const float argCurrentDuration)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_PEAK_CURRENT_DURATION,
         argCurrentDuration);

#if defined(T271_CTRE)
   TalonSRX* const tmpSRX = dynamic_cast<TalonSRX*>(MotorController_);

   if (tmpSRX != nullptr)
   {
      tmpSRX->ConfigPeakCurrentDuration(Read<float>(t271_motor_data_index::T271_MOTOR_DATA_PEAK_CURRENT_DURATION),
                                        _StatusFrameRateTimeout);
   }
#endif
}

void Team271Motor::SetContinuousCurrentLimit(const float argContinuousCurrentLimit)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_CONTINUOUS_CURRENT_LIMIT,
         argContinuousCurrentLimit);

#if defined(T271_CTRE)
   TalonSRX* const tmpSRX = dynamic_cast<TalonSRX*>(MotorController_);

   if (tmpSRX != nullptr)
   {
      tmpSRX->ConfigContinuousCurrentLimit(Read<float>(t271_motor_data_index::T271_MOTOR_DATA_CONTINUOUS_CURRENT_LIMIT),
                                           _StatusFrameRateTimeout);
   }
#endif
}

void Team271Motor::SetEnableCurrentLimit(const bool argEnable)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_CURRENT_LIMIT_ENABLE,
         argEnable);

#if defined(T271_CTRE)
   TalonSRX* const tmpSRX = dynamic_cast<TalonSRX*>(MotorController_);

   if (tmpSRX != nullptr)
   {
      tmpSRX->EnableCurrentLimit(Read<bool>(t271_motor_data_index::T271_MOTOR_DATA_CURRENT_LIMIT_ENABLE));
   }
#endif
}

void Team271Motor::SetContinuousCurrentLimit(const float argCurrentLimit,
                                             const float argCurrentDuration,
                                             const float argContinuousCurrentLimit)
{
   bool tmpEnableCurrentLimit = false;

   Write(t271_motor_data_index::T271_MOTOR_DATA_PEAK_CURRENT_LIMIT,
         argCurrentLimit);

   Write(t271_motor_data_index::T271_MOTOR_DATA_PEAK_CURRENT_DURATION,
         argCurrentDuration);

   Write(t271_motor_data_index::T271_MOTOR_DATA_CONTINUOUS_CURRENT_LIMIT,
         argContinuousCurrentLimit);

   /*
    * Set Current Limits
    */
   if (( Read<float>(t271_motor_data_index::T271_MOTOR_DATA_PEAK_CURRENT_LIMIT) > 0 ) && ( Read<float>(t271_motor_data_index::T271_MOTOR_DATA_PEAK_CURRENT_DURATION) > 0 ))
   {
      SetPeakCurrentLimit(Read<float>(t271_motor_data_index::T271_MOTOR_DATA_PEAK_CURRENT_LIMIT));
      SetPeakCurrentDuration(Read<float>(t271_motor_data_index::T271_MOTOR_DATA_PEAK_CURRENT_DURATION));

      tmpEnableCurrentLimit = true;
   }

   if (Read<float>(t271_motor_data_index::T271_MOTOR_DATA_CONTINUOUS_CURRENT_LIMIT) > 0)
   {
      SetContinuousCurrentLimit(Read<float>(t271_motor_data_index::T271_MOTOR_DATA_CONTINUOUS_CURRENT_LIMIT));

      tmpEnableCurrentLimit = true;
   }

   SetEnableCurrentLimit(tmpEnableCurrentLimit);
}

void Team271Motor::SetOpenLoopRamp(const float argRamp)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_OPEN_LOOP_RAMP,
         argRamp);

#if defined(T271_CTRE)
   if (MotorController_ != nullptr)
   {
      MotorController_->ConfigOpenloopRamp(Read<float>(t271_motor_data_index::T271_MOTOR_DATA_OPEN_LOOP_RAMP),
                                           _StatusFrameRateTimeout);
   }
#endif
}

void Team271Motor::SetClosedLoopRamp(const float argRamp)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_CLOSED_LOOP_RAMP,
         argRamp);

#if defined(T271_CTRE)
   if (MotorController_ != nullptr)
   {
      MotorController_->ConfigClosedloopRamp(Read<float>(t271_motor_data_index::T271_MOTOR_DATA_CLOSED_LOOP_RAMP),
                                             _StatusFrameRateTimeout);
   }
#endif
}

void Team271Motor::SetPeakFwdVoltage(const float argVoltage)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_PEAK_VOLT_FWD,
         argVoltage);

#if defined(T271_CTRE)
   if (MotorController_ != nullptr)
   {
      MotorController_->ConfigPeakOutputForward(Read<float>(t271_motor_data_index::T271_MOTOR_DATA_PEAK_VOLT_FWD),
                                                _StatusFrameRateTimeout);
   }
#endif
}

void Team271Motor::SetPeakRevVoltage(const float argVoltage)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_PEAK_VOLT_REV,
         argVoltage);

#if defined(T271_CTRE)
   if (MotorController_ != nullptr)
   {
      MotorController_->ConfigPeakOutputReverse(Read<float>(t271_motor_data_index::T271_MOTOR_DATA_PEAK_VOLT_REV),
                                                _StatusFrameRateTimeout);
   }
#endif
}

void Team271Motor::SetNominalFwdVoltage(const float argVoltage)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_NOMINAL_VOLT_FWD,
         argVoltage);

#if defined(T271_CTRE)
   if (MotorController_ != nullptr)
   {
      MotorController_->ConfigNominalOutputForward(Read<float>(t271_motor_data_index::T271_MOTOR_DATA_NOMINAL_VOLT_FWD),
                                                   _StatusFrameRateTimeout);
   }
#endif
}
void Team271Motor::SetNominalRevVoltage(const float argVoltage)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_NOMINAL_VOLT_REV,
         argVoltage);

#if defined(T271_CTRE)
   if (MotorController_ != nullptr)
   {
      MotorController_->ConfigNominalOutputReverse(Read<float>(t271_motor_data_index::T271_MOTOR_DATA_NOMINAL_VOLT_REV),
                                                   _StatusFrameRateTimeout);
   }
#endif
}

void Team271Motor::SetNeutralDeadband(const float argDeadband)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_NEUTRAL_DEADBAND,
         argDeadband);

#if defined(T271_CTRE)
   if (MotorController_ != nullptr)
   {
      MotorController_->ConfigNeutralDeadband(Read<float>(t271_motor_data_index::T271_MOTOR_DATA_NEUTRAL_DEADBAND),
                                              _StatusFrameRateTimeout);
   }
   else if (MotorControllerPWM_ != nullptr)
   {
      MotorControllerPWM_->SetNeutralDeadband(Read<float>(t271_motor_data_index::T271_MOTOR_DATA_NEUTRAL_DEADBAND));
   }
#else
   if( MotorControllerPWM_ != nullptr )
   {
      MotorControllerPWM_->SetNeutralDeadband( Read<float>( t271_motor_data_index::T271_MOTOR_DATA_NEUTRAL_DEADBAND ) );
   }
#endif
}

void Team271Motor::SetVoltageCompensation(const bool argEnable)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_ENABLE_VOLT_COMP,
         argEnable);

#if defined(T271_CTRE)
   if (MotorController_ != nullptr)
   {
      MotorController_->ConfigVoltageCompSaturation(12.0,
                                                    _StatusFrameRateTimeout);

      MotorController_->EnableVoltageCompensation(Read<bool>(t271_motor_data_index::T271_MOTOR_DATA_ENABLE_VOLT_COMP));

      MotorController_->ConfigVoltageMeasurementFilter(8,
                                                       _StatusFrameRateTimeout);
   }
#endif
}

void Team271Motor::SetMotionMagicVel(const int16_t argVel)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_MM_VEL,
         argVel);

#if defined(T271_CTRE)
   TalonSRX* const tmpSRX = dynamic_cast<TalonSRX*>(MotorController_);

   if (tmpSRX != nullptr)
   {
      /*
       * Set Motion Magic Cruise Velocity
       */
      tmpSRX->ConfigMotionCruiseVelocity(argVel,
                                         _StatusFrameRateTimeout);
   }
#endif
}

void Team271Motor::SetMotionMagicAccel(const int16_t argAccel)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_MM_ACCEL,
         argAccel);

#if defined(T271_CTRE)
   TalonSRX* const tmpSRX = dynamic_cast<TalonSRX*>(MotorController_);

   if (tmpSRX != nullptr)
   {
      /*
       * Set Motion Magic Cruise Acceleration
       */
      tmpSRX->ConfigMotionAcceleration(argAccel,
                                       _StatusFrameRateTimeout);
   }
#endif
}

void Team271Motor::SetNext(const float argNextValue,
                           const float argNextArbFF)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_VALUE_NEXT,
         argNextValue);

   Write(t271_motor_data_index::T271_MOTOR_DATA_ARB_FF_NEXT,
         argNextArbFF);
}

void Team271Motor::SetNextValue(const float argNextValue)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_VALUE_NEXT,
         argNextValue);
}

void Team271Motor::SetNextArbFF(const float argNextArbFF)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_ARB_FF_NEXT,
         argNextArbFF);
}

void Team271Motor::SetNeutralValue(const float argValue)
{
   Write(t271_motor_data_index::T271_MOTOR_DATA_VALUE_NEUTRAL,
         argValue);
}

/*
 *
 * Base
 *
 */
void Team271Motor::Init(void)
{
#if defined(T271_CTRE)
   /*
    * Create Controller
    */
   if (Read<TEAM271_MOTOR_CONTROLLER_TYPE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROLLER_TYPE) == TEAM271_MOTOR_CONTROLLER_TYPE_TALON_SRX)
   {
      MotorController_ = new TalonSRX(Read<uint8_t>(t271_motor_data_index::T271_MOTOR_DATA_ID));
   }
   else if (Read<TEAM271_MOTOR_CONTROLLER_TYPE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROLLER_TYPE) == TEAM271_MOTOR_CONTROLLER_TYPE_VICTOR_SPX)
   {
      MotorController_ = new VictorSPX(Read<uint8_t>(t271_motor_data_index::T271_MOTOR_DATA_ID));
   }
   else if (Read<TEAM271_MOTOR_CONTROLLER_TYPE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROLLER_TYPE) == TEAM271_MOTOR_CONTROLLER_TYPE_SPARK
         || Read<TEAM271_MOTOR_CONTROLLER_TYPE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROLLER_TYPE) == TEAM271_MOTOR_CONTROLLER_TYPE_SPARK_MAX_PWM)
   {
      MotorControllerPWM_ = Team271BaseManager::InstanceAdd(new Team271PWM(this,
                                                                           Read<uint8_t>(t271_motor_data_index::T271_MOTOR_DATA_ID)));

      if (Read<TEAM271_MOTOR_CONTROLLER_TYPE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROLLER_TYPE) == TEAM271_MOTOR_CONTROLLER_TYPE_SPARK_MAX_PWM)
      {
         /* Note that the Spark Max uses the following bounds for PWM values. These
          * values should work reasonably well for most controllers, but if users
          * experience issues such as asymmetric behavior around the deadband or
          * inability to saturate the controller in either direction, calibration is
          * recommended. The calibration procedure can be found in the Spark Max User
          * Manual available from REV Robotics.
          *
          *   2.003ms = full "forward"
          *   1.55ms = the "high end" of the deadband range
          *   1.50ms = center of the deadband range (off)
          *   1.46ms = the "low end" of the deadband range
          *   0.999ms = full "reverse"
          */
         MotorControllerPWM_->SetConfig(2.003,
                                        1.55,
                                        1.50,
                                        1.46,
                                        0.999);

         MotorControllerPWM_->SetPeriodScale(0);

         MotorControllerPWM_->Set(0);

         MotorControllerPWM_->LatchZero();
      }
   }
   else
   {
      LOG_ERROR("%s - Invalid Motor Controller Type",
                GetName().c_str());
   }
#else
   if( Read<TEAM271_MOTOR_CONTROLLER_TYPE>( t271_motor_data_index::T271_MOTOR_DATA_CONTROLLER_TYPE ) == TEAM271_MOTOR_CONTROLLER_TYPE_SPARK ||
         Read<TEAM271_MOTOR_CONTROLLER_TYPE>( t271_motor_data_index::T271_MOTOR_DATA_CONTROLLER_TYPE ) == TEAM271_MOTOR_CONTROLLER_TYPE_SPARK_MAX_PWM )
   {
      MotorControllerPWM_ = Team271BaseManager::InstanceAdd( new Team271PWM( this,
                  Read<uint8_t>( t271_motor_data_index::T271_MOTOR_DATA_ID ) ) );

      if( Read<TEAM271_MOTOR_CONTROLLER_TYPE>( t271_motor_data_index::T271_MOTOR_DATA_CONTROLLER_TYPE ) == TEAM271_MOTOR_CONTROLLER_TYPE_SPARK_MAX_PWM )
      {
         /* Note that the Spark Max uses the following bounds for PWM values. These
          * values should work reasonably well for most controllers, but if users
          * experience issues such as asymmetric behavior around the deadband or
          * inability to saturate the controller in either direction, calibration is
          * recommended. The calibration procedure can be found in the Spark Max User
          * Manual available from REV Robotics.
          *
          *   2.003ms = full "forward"
          *   1.55ms = the "high end" of the deadband range
          *   1.50ms = center of the deadband range (off)
          *   1.46ms = the "low end" of the deadband range
          *   0.999ms = full "reverse"
          */
         MotorControllerPWM_->SetConfig( 2.003,
               1.55,
               1.50,
               1.46,
               0.999 );

         MotorControllerPWM_->SetPeriodScale( 0 );

         MotorControllerPWM_->Set( 0 );

         MotorControllerPWM_->LatchZero();
      }
   }
   else
   {
      LOG_ERROR( "%s - Invalid Motor Controller Type",
            GetName().c_str() );
   }
#endif

   /*
    * TODO: Find a way to detect this motor controller is different then the expected
    */
#if defined( FUTURE_USE )
   if( MotorController_ != nullptr )
   {
      char toFill[32];
      int32_t numBytesFilled;

      c_MotController_GetDescription( MotorController_->GetHandle(),
            toFill,
            32,
            &numBytesFilled );
      int32_t tmpFirm = 0;

      c_MotController_GetFirmwareVersion( MotorController_->GetHandle(),
            &tmpFirm );

      LOG_ERROR( "%s - Desc %s | Firm: %d",
            GetName().c_str(),
            toFill,
            tmpFirm );

      if( tmpFirm == -1 )
      {
         delete MotorController_;

         if( _ControllerType == TEAM271_MOTOR_CONTROLLER_TYPE_TALON_SRX )
         {
            LOG_ERROR( "%s - Trying as Talon SRX",
                  GetName().c_str() );

            _ControllerType = TEAM271_MOTOR_CONTROLLER_TYPE_VICTOR_SPX;

            MotorController_ = new VictorSPX( _IDControl );
         }
         else if( _ControllerType == TEAM271_MOTOR_CONTROLLER_TYPE_VICTOR_SPX )
         {
            LOG_ERROR( "%s - Trying as Victor SPX",
                  GetName().c_str() );

            _ControllerType = TEAM271_MOTOR_CONTROLLER_TYPE_TALON_SRX;

            MotorController_ = new TalonSRX( _IDControl );
         }
      }
   }
#endif

   /*
    * Set the Motor Controller to Disabled
    */
   SetControlMode(TEAM271_CONTROL_MODE_DISABLED);

   /*
    * No Master
    */
   if (MasterMotor_ == nullptr)
   {
      Setup(this);
   }

   /*
    * Copy Master Motor Settings
    */
   else
   {
      /*
       * Output Values
       */
      Set(t271_motor_data_index::T271_MOTOR_DATA_VALUE_PREV,
          MasterMotor_);

      Set(t271_motor_data_index::T271_MOTOR_DATA_VALUE_CURRENT,
          MasterMotor_);

      Set(t271_motor_data_index::T271_MOTOR_DATA_VALUE_NEUTRAL,
          MasterMotor_);

      Setup(MasterMotor_);

      SetMaster(MasterMotor_);
   }
}

/*
 *
 * Robot
 *
 */
void Team271Motor::PostRobotPeriodic(const bool argIsParent)
{
   /*
    * Check if Follower has to be emulated
    * Assume the Master Value has already been set
    */
   if (Read<TEAM271_CONTROL_MODE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROL_MODE) == TEAM271_CONTROL_MODE_FOLLOWER)
   {
      Set(t271_motor_data_index::T271_MOTOR_DATA_VALUE_NEXT,
          GetMaster());
      Set(t271_motor_data_index::T271_MOTOR_DATA_ARB_FF_NEXT,
          GetMaster());
   }

   /*
    * if _ValueNext != _ValueCurrent || _ArbFFNext != _ArbFFCurrent
    *    - If it is set the output
    */
   if (( Read<float>(t271_motor_data_index::T271_MOTOR_DATA_VALUE_NEXT) != Read<float>(t271_motor_data_index::T271_MOTOR_DATA_VALUE_CURRENT) )
         || ( Read<float>(t271_motor_data_index::T271_MOTOR_DATA_ARB_FF_NEXT) != Read<float>(t271_motor_data_index::T271_MOTOR_DATA_ARB_FF_CURRENT) ))
   {
      SetOutput(Read<float>(t271_motor_data_index::T271_MOTOR_DATA_VALUE_NEXT),
                Read<float>(t271_motor_data_index::T271_MOTOR_DATA_ARB_FF_NEXT));
   }

   /*
    * Base Call
    */
   Team271Base::PostRobotPeriodic();
}

/*
 *
 * Robot State
 *
 */
void Team271Motor::ClearStickyFaults(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::ClearStickyFaults();

   /*
    * Clear Motor Controller Sticky Faults
    */
#if defined(T271_CTRE)
   if (MotorController_ != nullptr)
   {
      MotorController_->ClearStickyFaults(0);
   }
#endif
}

/*
 *
 * Controller Functions
 *
 */
void Team271Motor::Setup(const Team271Motor* const argSetupFromMotor)
{
   if (argSetupFromMotor != nullptr)
   {
      /*
       * Setup Status Frames
       */
      SetStatusFrameGeneral(argSetupFromMotor->Read<uint32_t>(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_GENERAL));
      SetStatusFrameFeedback(argSetupFromMotor->Read<uint32_t>(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_FEEDBACK));
      SetStatusFrameQuadEncoder(argSetupFromMotor->Read<uint32_t>(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_QUAD_ENCODER));
      SetStatusFrameAnalogTempVbat(argSetupFromMotor->Read<uint32_t>(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_ANALOG_TEMP_VBAT));
      SetStatusFramePulseWidthMeas(argSetupFromMotor->Read<uint32_t>(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_PULSE_WIDTH_MEAS));
      SetStatusFrameBasePIDF(argSetupFromMotor->Read<uint32_t>(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_BASE_PIDF));
      SetStatusFrameMotionMagic(argSetupFromMotor->Read<uint32_t>(t271_motor_data_index::T271_MOTOR_DATA_STATUS_FRAME_RATE_MOTION_MAGIC));

      /*
       * Invert as needed so we always apply +1.0 for Forward
       */
      SetInvertedOutput(argSetupFromMotor->Read<TEAM271_INVERTED_STATE>(t271_motor_data_index::T271_MOTOR_DATA_INVERTED_OUTPUT));

      /*
       * Set Neutral Mode to Brake or Coast
       */
      SetNeutralMode(argSetupFromMotor->Read<TEAM271_NEUTRAL_MODE>(t271_motor_data_index::T271_MOTOR_DATA_NEUTRAL_MODE));

      /*
       * Current Limiting
       */
      SetContinuousCurrentLimit(argSetupFromMotor->Read<float>(t271_motor_data_index::T271_MOTOR_DATA_PEAK_CURRENT_LIMIT),
                                argSetupFromMotor->Read<float>(t271_motor_data_index::T271_MOTOR_DATA_PEAK_CURRENT_DURATION),
                                argSetupFromMotor->Read<float>(t271_motor_data_index::T271_MOTOR_DATA_CONTINUOUS_CURRENT_LIMIT));

      /*
       * Output Shaping
       */
      SetOpenLoopRamp(argSetupFromMotor->Read<float>(t271_motor_data_index::T271_MOTOR_DATA_OPEN_LOOP_RAMP));
      SetClosedLoopRamp(argSetupFromMotor->Read<float>(t271_motor_data_index::T271_MOTOR_DATA_CLOSED_LOOP_RAMP));

      SetPeakFwdVoltage(argSetupFromMotor->Read<float>(t271_motor_data_index::T271_MOTOR_DATA_PEAK_VOLT_FWD));
      SetPeakRevVoltage(argSetupFromMotor->Read<float>(t271_motor_data_index::T271_MOTOR_DATA_PEAK_VOLT_REV));

      SetNominalFwdVoltage(argSetupFromMotor->Read<float>(t271_motor_data_index::T271_MOTOR_DATA_NOMINAL_VOLT_FWD));
      SetNominalRevVoltage(argSetupFromMotor->Read<float>(t271_motor_data_index::T271_MOTOR_DATA_NOMINAL_VOLT_REV));

      SetNeutralDeadband(argSetupFromMotor->Read<float>(t271_motor_data_index::T271_MOTOR_DATA_NEUTRAL_DEADBAND));

      SetVoltageCompensation(argSetupFromMotor->Read<bool>(t271_motor_data_index::T271_MOTOR_DATA_ENABLE_VOLT_COMP));

      /*
       * Motion Magic
       */
      SetMotionMagicVel(argSetupFromMotor->Read<uint16_t>(t271_motor_data_index::T271_MOTOR_DATA_MM_VEL));
      SetMotionMagicAccel(argSetupFromMotor->Read<uint16_t>(t271_motor_data_index::T271_MOTOR_DATA_MM_ACCEL));
   }
}

/*
 *
 * Output Functions
 *
 */
void Team271Motor::Stop(void)
{
#if defined(T271_CTRE)
   /*
    * Check if there is a valid Master Controller
    */
   if (( MotorController_ == nullptr ) && ( MotorControllerPWM_ == nullptr ))
   {
      LOG_ERROR("%s - No Motor Controller",
                GetName().c_str());
   }
   else
   {
      SetNext(GetValueNeutral(),
              0);
   }
#else
   /*
    * Check if there is a valid Master Controller
    */
   if( MotorControllerPWM_ == nullptr )
   {
      LOG_ERROR( "%s - No Motor Controller",
            GetName().c_str() );
   }
   else
   {
      SetNext( GetValueNeutral(),
            0 );
   }
#endif
}

void Team271Motor::SetOutput(const float argSet,
                             const float argArgA)
{
   float tmpSet = argSet;

   /*
    * Store the Previous value
    */
   Set(t271_motor_data_index::T271_MOTOR_DATA_VALUE_PREV,
       t271_motor_data_index::T271_MOTOR_DATA_VALUE_CURRENT);

   Set(t271_motor_data_index::T271_MOTOR_DATA_ARB_FF_PREV,
       t271_motor_data_index::T271_MOTOR_DATA_ARB_FF_CURRENT);

#if defined(T271_CTRE)
   /*
    * Check if there is a valid Master Controller
    */
   if (( MotorController_ == nullptr ) && ( MotorControllerPWM_ == nullptr ))
   {
      LOG_ERROR("%s - No Motor Controller",
                GetName().c_str());
   }
   else
   {
      /*
       * Check if Follower
       */
      if (Read<TEAM271_CONTROL_MODE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROL_MODE) == TEAM271_CONTROL_MODE_FOLLOWER)
      {
         /*
          * Check if Follower has to be emulated
          * Assume the Master Value has already been set
          */
         if (MotorControllerPWM_ != nullptr)
         {
            MotorControllerPWM_->Set(tmpSet);
         }
      }
      else
      {
         /*
          * Apply the new value appropriately
          */
         if (MotorController_ != nullptr)
         {
            if (Read<TEAM271_CONTROL_MODE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROL_MODE) == TEAM271_CONTROL_MODE_PERCENT_OUTPUT)
            {
               MotorController_->Set(ControlMode::PercentOutput,
                                     tmpSet);
            }
            else if (Read<TEAM271_CONTROL_MODE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROL_MODE) == TEAM271_CONTROL_MODE_POSITION)
            {
               MotorController_->Set(ControlMode::Position,
                                     tmpSet);
            }
            else if (Read<TEAM271_CONTROL_MODE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROL_MODE) == TEAM271_CONTROL_MODE_VELOCITY)
            {
               /*
                MotorController_->Set( ControlMode::Velocity,
                tmpSet );
                */
               MotorController_->Set(ControlMode::Velocity,
                                     tmpSet,
                                     DemandType::DemandType_ArbitraryFeedForward,
                                     argArgA);
            }
            else if (Read<TEAM271_CONTROL_MODE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROL_MODE) == TEAM271_CONTROL_MODE_CURRENT)
            {
               MotorController_->Set(ControlMode::Current,
                                     tmpSet);
            }
            else if (Read<TEAM271_CONTROL_MODE>(t271_motor_data_index::T271_MOTOR_DATA_CONTROL_MODE) == TEAM271_CONTROL_MODE_MOTION_MAGIC)
            {
               MotorController_->Set(ControlMode::MotionMagic,
                                     tmpSet);
            }
            else
            {
               LOG_ERROR("%s - Invalid Control Mode",
                         GetName().c_str());

               MotorController_->Set(ControlMode::PercentOutput,
                                     tmpSet);
            }
         }
         else if (MotorControllerPWM_ != nullptr)
         {
            MotorControllerPWM_->Set(tmpSet);
         }
      }
   }
#else
   /*
    * Check if there is a valid Master Controller
    */
   if( ( MotorControllerPWM_ == nullptr ) )
   {
      LOG_ERROR( "%s - No Motor Controller",
            GetName().c_str() );
   }
   else
   {
      /*
       * Apply the new value appropriately
       */
      if( MotorControllerPWM_ != nullptr )
      {
         MotorControllerPWM_->Set( tmpSet );
      }
   }
#endif

   /*
    * Store the value
    */
   Write(t271_motor_data_index::T271_MOTOR_DATA_VALUE_CURRENT,
         tmpSet);

   Write(t271_motor_data_index::T271_MOTOR_DATA_ARB_FF_CURRENT,
         argArgA);
}
#endif

