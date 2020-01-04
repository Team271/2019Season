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

#if defined(T271_SENSOR_ENABLE)

Team271SensorCTRE::Team271SensorCTRE(Team271Base* const argParent,
                                     const string& argSensorName,
                                     Team271Motor* const argMotor,
                                     const TEAM271_SENSOR_TYPE argSensorType,
                                     const TEAM271_INVERTED_STATE argSensorInverted,
                                     const TEAM271_SENSOR_SETTINGS argSensorSettings,
                                     const float argArgumentA)
      : Team271Sensor(argParent,
                      argSensorName,
                      t271_sensor_ctre_data_index::T271_DATA_COUNT,
                      argSensorType,
                      argSensorInverted,
                      argSensorSettings,
                      argArgumentA)
{
   LOG_TRACE("%s - Constructor Start",
             GetName().c_str());

#if defined(T271_CTRE)
   if (argMotor != nullptr)
   {
      /*
       * Store Talon
       */
      TalonSRX_ = argMotor->GetTalon();

      if (TalonSRX_ != nullptr)
      {
         /*
          * Cache the Sensor Collection
          */
         SensorCollection_ = &TalonSRX_->GetSensorCollection();

         /*
          * Setup Sensor
          */
         if (T271_OPTION_CHECK_SET_ANY(argSensorType,
                                       TEAM271_SENSOR_TYPE_QUAD_ENCODER))
         {
            TalonSRX_->ConfigSelectedFeedbackSensor(QuadEncoder,
                                                    0,
                                                    _StatusFrameRateTimeout);

         }

         if (T271_OPTION_CHECK_SET_ANY(argSensorType,
                                       TEAM271_SENSOR_TYPE_ANALOG))
         {
            TalonSRX_->ConfigSelectedFeedbackSensor(Analog,
                                                    0,
                                                    _StatusFrameRateTimeout);

            if (T271_OPTION_CHECK_SET_ANY(argSensorSettings,
                                          TEAM271_SENSOR_SETTINGS_CONTINUOUS))
            {
               TalonSRX_->ConfigSetParameter(ParamEnum::eFeedbackNotContinuous,
                                             0,
                                             0x00,
                                             0x00,
                                             0x00);
            }
            else
            {
               TalonSRX_->ConfigSetParameter(ParamEnum::eFeedbackNotContinuous,
                                             1,
                                             0x00,
                                             0x00,
                                             0x00);
            }
         }

         if (T271_OPTION_CHECK_SET_ANY(argSensorType,
                                       TEAM271_SENSOR_TYPE_PULSE_WIDTH_ENCODED_POSITION))
         {
            TalonSRX_->ConfigSelectedFeedbackSensor(PulseWidthEncodedPosition,
                                                    0,
                                                    _StatusFrameRateTimeout);
         }

         if (T271_OPTION_CHECK_SET_ANY(argSensorType,
                                       TEAM271_SENSOR_TYPE_LIMIT_FWD))
         {
            if (T271_OPTION_CHECK_SET_ANY(argSensorSettings,
                                          TEAM271_SENSOR_SETTINGS_NORMALLY_OPEN))
            {
               TalonSRX_->ConfigForwardLimitSwitchSource(LimitSwitchSource_FeedbackConnector,
                                                         LimitSwitchNormal_NormallyOpen,
                                                         _StatusFrameRateTimeout);
            }
            else if (T271_OPTION_CHECK_SET_ANY(argSensorSettings,
                                               TEAM271_SENSOR_SETTINGS_NORMALLY_OPEN))
            {
               TalonSRX_->ConfigForwardLimitSwitchSource(LimitSwitchSource_FeedbackConnector,
                                                         LimitSwitchNormal_NormallyClosed,
                                                         _StatusFrameRateTimeout);
            }
            else
            {
               TalonSRX_->ConfigForwardLimitSwitchSource(LimitSwitchSource_FeedbackConnector,
                                                         LimitSwitchNormal_Disabled,
                                                         _StatusFrameRateTimeout);
            }
         }

         if (T271_OPTION_CHECK_SET_ANY(argSensorType,
                                       TEAM271_SENSOR_TYPE_LIMIT_REV))
         {
            if (T271_OPTION_CHECK_SET_ANY(argSensorSettings,
                                          TEAM271_SENSOR_SETTINGS_NORMALLY_OPEN))
            {
               TalonSRX_->ConfigReverseLimitSwitchSource(LimitSwitchSource_FeedbackConnector,
                                                         LimitSwitchNormal_NormallyOpen,
                                                         _StatusFrameRateTimeout);
            }
            else if (T271_OPTION_CHECK_SET_ANY(argSensorSettings,
                                               TEAM271_SENSOR_SETTINGS_NORMALLY_OPEN))
            {
               TalonSRX_->ConfigReverseLimitSwitchSource(LimitSwitchSource_FeedbackConnector,
                                                         LimitSwitchNormal_NormallyClosed,
                                                         _StatusFrameRateTimeout);
            }
            else
            {
               TalonSRX_->ConfigReverseLimitSwitchSource(LimitSwitchSource_FeedbackConnector,
                                                         LimitSwitchNormal_Disabled,
                                                         _StatusFrameRateTimeout);
            }
         }

         /*
          * Software Emulated Limit Switch
          */
         if (T271_OPTION_CHECK_SET_ANY(argSensorType,
                                       TEAM271_SENSOR_TYPE_LIMIT_FWD_SW))
         {
            TalonSRX_->ConfigForwardSoftLimitThreshold(Read<TEAM271_INVERTED_STATE>(t271_sensor_data_index::T271_SENSOR_DATA_ARGUMENT_A),
                                                       _StatusFrameRateTimeout);
            TalonSRX_->ConfigForwardSoftLimitEnable(true,
                                                    _StatusFrameRateTimeout);
         }

         if (T271_OPTION_CHECK_SET_ANY(argSensorType,
                                       TEAM271_SENSOR_TYPE_LIMIT_REV_SW))
         {
            TalonSRX_->ConfigReverseSoftLimitThreshold(Read<TEAM271_INVERTED_STATE>(t271_sensor_data_index::T271_SENSOR_DATA_ARGUMENT_A),
                                                       _StatusFrameRateTimeout);
            TalonSRX_->ConfigReverseSoftLimitEnable(true,
                                                    _StatusFrameRateTimeout);
         }

         /*
          * Math "Sensors"
          */
         if (T271_OPTION_CHECK_SET_ANY(argSensorType,
                                       TEAM271_SENSOR_TYPE_SENSOR_SUM))
         {
            TalonSRX_->ConfigSelectedFeedbackSensor(SensorSum,
                                                    0,
                                                    _StatusFrameRateTimeout);
         }

         if (T271_OPTION_CHECK_SET_ANY(argSensorType,
                                       TEAM271_SENSOR_TYPE_SENSOR_DIFFERENCE))
         {
            TalonSRX_->ConfigSelectedFeedbackSensor(SensorDifference,
                                                    0,
                                                    _StatusFrameRateTimeout);
         }

         if (T271_OPTION_CHECK_SET_ANY(argSensorType,
                                       TEAM271_SENSOR_TYPE_REMOTE_0))
         {
            TalonSRX_->ConfigSelectedFeedbackSensor(RemoteSensor0,
                                                    0,
                                                    _StatusFrameRateTimeout);
         }

         if (T271_OPTION_CHECK_SET_ANY(argSensorType,
                                       TEAM271_SENSOR_TYPE_REMOTE_1))
         {
            TalonSRX_->ConfigSelectedFeedbackSensor(RemoteSensor1,
                                                    0,
                                                    _StatusFrameRateTimeout);
         }

         /*
          * Set Position to 0
          */
         TalonSRX_->SetSelectedSensorPosition(0,
                                              0,
                                              _StatusFrameRateTimeout);
      }
   }
#endif

   /*
    * Setup Velocity Measurement
    */
   SetVelMeasPeriod(T271_VelocityMeasPeriod::T271_Period_100Ms);

   SetVelMeasWindow(64U);

   /*
    * Invert as needed so the sensor always increases as we always move Forward
    */
   SetInverted(argSensorInverted);

   LOG_TRACE("%s - Constructor End",
             GetName().c_str());
}

Team271SensorCTRE::Team271SensorCTRE(Team271Base* const argParent,
                                     const string& argSensorName,
                                     const uint32_t argCANifierID,
                                     const TEAM271_SENSOR_TYPE argSensorType,
                                     const TEAM271_INVERTED_STATE argSensorInverted,
                                     const TEAM271_SENSOR_SETTINGS argSensorSettings,
                                     const float argArgumentA)
      : Team271Sensor(argParent,
                      argSensorName,
                      t271_sensor_ctre_data_index::T271_DATA_COUNT,
                      argSensorType,
                      argSensorInverted,
                      argSensorSettings,
                      argArgumentA)
{
   LOG_TRACE("%s - Constructor Start",
             GetName().c_str());

#if defined(T271_CTRE)
   CANifier_ = new CANifier(argCANifierID);

   /*
    * Setup Sensor
    */
   if (T271_OPTION_CHECK_SET_ANY(argSensorType,
                                 TEAM271_SENSOR_TYPE_QUAD_ENCODER))
   {

   }

   if (T271_OPTION_CHECK_SET_ANY(argSensorType,
                                 TEAM271_SENSOR_TYPE_ANALOG))
   {
      if (T271_OPTION_CHECK_SET_ANY(argSensorSettings,
                                    TEAM271_SENSOR_SETTINGS_CONTINUOUS))
      {
         CANifier_->ConfigSetParameter(ParamEnum::eFeedbackNotContinuous,
                                       0,
                                       0x00,
                                       0x00,
                                       0x00);
      }
      else
      {
         CANifier_->ConfigSetParameter(ParamEnum::eFeedbackNotContinuous,
                                       1,
                                       0x00,
                                       0x00,
                                       0x00);
      }
   }

   if (T271_OPTION_CHECK_SET_ANY(argSensorType,
                                 TEAM271_SENSOR_TYPE_PULSE_WIDTH_ENCODED_POSITION))
   {

   }

   if (T271_OPTION_CHECK_SET_ANY(argSensorType,
                                 TEAM271_SENSOR_TYPE_LIMIT_FWD))
   {
      if (T271_OPTION_CHECK_SET_ANY(argSensorSettings,
                                    TEAM271_SENSOR_SETTINGS_NORMALLY_OPEN))
      {

      }
      else if (T271_OPTION_CHECK_SET_ANY(argSensorSettings,
                                         TEAM271_SENSOR_SETTINGS_NORMALLY_OPEN))
      {

      }
      else
      {

      }
   }

   if (T271_OPTION_CHECK_SET_ANY(argSensorType,
                                 TEAM271_SENSOR_TYPE_LIMIT_REV))
   {
      if (T271_OPTION_CHECK_SET_ANY(argSensorSettings,
                                    TEAM271_SENSOR_SETTINGS_NORMALLY_OPEN))
      {

      }
      else if (T271_OPTION_CHECK_SET_ANY(argSensorSettings,
                                         TEAM271_SENSOR_SETTINGS_NORMALLY_OPEN))
      {

      }
      else
      {

      }
   }

   /*
    * Set Position to 0
    */
   CANifier_->SetQuadraturePosition(0,
                                    _StatusFrameRateTimeout);
#endif

   /*
    * Setup Velocity Measurement
    */
   SetVelMeasPeriod(T271_VelocityMeasPeriod::T271_Period_100Ms);

   SetVelMeasWindow(64U);

   /*
    * Invert as needed so the sensor always increases as we always move Forward
    */
   SetInverted(argSensorInverted);

   LOG_TRACE("%s - Constructor End",
             GetName().c_str());
}

Team271SensorCTRE::~Team271SensorCTRE(void)
{

}

/*
 *
 * Getters
 *
 */
const string Team271SensorCTRE::GetClassName(void) const
{
   return "Team271SensorCTRE";
}

/*
 *
 * Setters
 *
 */
void Team271SensorCTRE::SetPosition(const float argPosition)
{
#if defined(T271_CTRE)
   uint8_t tmpIsValid = 0;
   static uint8_t tmpWasValid = 0;

   if ((TalonSRX_ != nullptr) && (SensorCollection_ != nullptr))
   {
      tmpIsValid = 1;

      Team271Sensor::SetPosition(argPosition);

      TalonSRX_->SetSelectedSensorPosition(argPosition,
                                           0,
                                           _StatusFrameRateTimeout);
   }
   else if (CANifier_ != nullptr)
   {
      tmpIsValid = 1;

      Team271Sensor::SetPosition(argPosition);

      CANifier_->SetQuadraturePosition(argPosition,
                                       _StatusFrameRateTimeout);
   }
   else
   {
      if (tmpWasValid == 1)
      {
         LOG_ERROR("%s - No CTRE Sensor",
                   GetName().c_str());
      }

      tmpWasValid = 0;
   }

   tmpWasValid = tmpIsValid;
#endif
}

void Team271SensorCTRE::SetInverted(const TEAM271_INVERTED_STATE argInverted)
{
   Write(t271_sensor_data_index::T271_SENSOR_DATA_INVERTED,
         argInverted);

#if defined(T271_CTRE)
   if (TalonSRX_ != nullptr)
   {
      if (Read<TEAM271_INVERTED_STATE>(t271_sensor_data_index::T271_SENSOR_DATA_INVERTED) == TEAM271_INVERTED_STATE_INVERTED)
      {
         TalonSRX_->SetSensorPhase(true);
      }
      else
      {
         TalonSRX_->SetSensorPhase(false);
      }
   }
#endif
}

void Team271SensorCTRE::SetVelMeasPeriod(const T271_VelocityMeasPeriod argPeriod)
{
   Write(t271_sensor_ctre_data_index::T271_SENSOR_CTRE_DATA_VEL_MEASURE_PERIOD,
         argPeriod);

#if defined(T271_CTRE)
   if (TalonSRX_ != nullptr)
   {
      TalonSRX_->ConfigVelocityMeasurementPeriod(Read<VelocityMeasPeriod>(t271_sensor_ctre_data_index::T271_SENSOR_CTRE_DATA_VEL_MEASURE_PERIOD),
                                                 _StatusFrameRateTimeout);
   }
   else if (CANifier_ != nullptr)
   {
      CANifier_->ConfigVelocityMeasurementPeriod(Read<CANifierVelocityMeasPeriod>(t271_sensor_ctre_data_index::T271_SENSOR_CTRE_DATA_VEL_MEASURE_PERIOD),
                                                 _StatusFrameRateTimeout);
   }
#endif
}

void Team271SensorCTRE::SetVelMeasWindow(const int32_t argWindow)
{
   Write(t271_sensor_ctre_data_index::T271_SENSOR_CTRE_DATA_VEL_MEASURE_WINDOW,
         argWindow);

#if defined(T271_CTRE)
   if (TalonSRX_ != nullptr)
   {
      TalonSRX_->ConfigVelocityMeasurementWindow(Read<int32_t>(t271_sensor_ctre_data_index::T271_SENSOR_CTRE_DATA_VEL_MEASURE_WINDOW),
                                                 _StatusFrameRateTimeout);
   }
   else if (CANifier_ != nullptr)
   {
      CANifier_->ConfigVelocityMeasurementWindow(Read<int32_t>(t271_sensor_ctre_data_index::T271_SENSOR_CTRE_DATA_VEL_MEASURE_WINDOW),
                                                 _StatusFrameRateTimeout);
   }
#endif
}

void Team271SensorCTRE::SetVelMeas(const T271_VelocityMeasPeriod argPeriod,
                                   const uint32_t argWindow)
{
   SetVelMeasPeriod(argPeriod);
   SetVelMeasWindow(argWindow);
}

/*
 *
 * Robot
 *
 */
void Team271SensorCTRE::PreRobotPeriodic(const bool argIsParent)
{
   const TEAM271_SENSOR_TYPE tmpSensorType = Read<TEAM271_SENSOR_TYPE>(t271_sensor_data_index::T271_SENSOR_DATA_TYPE);

   /*
    * Base Call
    * Skip Sensor Call
    */
   Team271Base::PreRobotPeriodic();

   /*
    * Store Previous Connected Status
    */
   Set(t271_sensor_data_index::T271_SENSOR_DATA_CONNECTED_PREV,
       t271_sensor_data_index::T271_SENSOR_DATA_CONNECTED);

   if (Team271Robot::CompareTime(TimeSensorStatusLast_,
                                 kSensorCheckRate) == 1)
   {
      /*
       * If this is a Pulse Width Encoded Sensor we can check if it's actually connected
       */
      if ((tmpSensorType == TEAM271_SENSOR_TYPE_PULSE_WIDTH_ENCODED_POSITION) || (tmpSensorType == TEAM271_SENSOR_TYPE_MAG_ABS))
      {
         /*
          * Check if there is a valid Master Controller or valid CANifier
          * If the period is 0
          * The sensor is unconnected
          */
#if defined(T271_CTRE)
         if (((TalonSRX_ == nullptr) || (SensorCollection_ == nullptr)) && (CANifier_ == nullptr))
         {
            Write(t271_sensor_data_index::T271_SENSOR_DATA_CONNECTED,
                  0);
         }
         else if (CANifier_ != nullptr)
         {
            double tmpPulseWidthAndPeriod[2] = {0,
                                                0};
            CANifier_->GetPWMInput(CANifier::PWMChannel::PWMChannel0,
                                   tmpPulseWidthAndPeriod);

            if (tmpPulseWidthAndPeriod[0] == 0)
            {
               Write(t271_sensor_data_index::T271_SENSOR_DATA_CONNECTED,
                     0);
            }
         }
         else if (SensorCollection_->GetPulseWidthRiseToRiseUs() == 0)
         {
            Write(t271_sensor_data_index::T271_SENSOR_DATA_CONNECTED,
                  0);
         }
         else
         {
            Write(t271_sensor_data_index::T271_SENSOR_DATA_CONNECTED,
                  1);
         }
#endif
      }
      else
      {
         Write(t271_sensor_data_index::T271_SENSOR_DATA_CONNECTED,
               1);
      }

      if (Read<uint8_t>(t271_sensor_data_index::T271_SENSOR_DATA_CONNECTED) != Read<uint8_t>(t271_sensor_data_index::T271_SENSOR_DATA_CONNECTED))
      {
         if (Read<uint8_t>(t271_sensor_data_index::T271_SENSOR_DATA_CONNECTED) == 1)
         {
            LOG_NOTICE("%s - Sensor Connected",
                       GetName().c_str());
         }
         else
         {
            LOG_ERROR("%s - Sensor Unconnected",
                      GetName().c_str());
         }
      }
   }

   /*
    * Update all Positions and Rates
    */
   if (T271_OPTION_CHECK_SET_ANY(tmpSensorType,
                                 (TEAM271_SENSOR_TYPE_QUAD_ENCODER | TEAM271_SENSOR_TYPE_ANALOG | TEAM271_SENSOR_TYPE_PULSE_WIDTH_ENCODED_POSITION)))
   {
      if (Team271Robot::CompareTime(TimeSensorPositionUpdateLast_,
                                    kSensorPositionUpdateRate) == 1)
      {
         UpdatePositions();
      }

      if (Team271Robot::CompareTime(TimeSensorRateUpdateLast_,
                                    kSensorRateUpdateRate) == 1)
      {
         UpdateRates();
      }
   }

   if (T271_OPTION_CHECK_SET_ANY(tmpSensorType,
                                      (TEAM271_SENSOR_TYPE_LIMIT | TEAM271_SENSOR_TYPE_LIMIT_FWD | TEAM271_SENSOR_TYPE_LIMIT_REV |
                                            TEAM271_SENSOR_TYPE_LIMIT_SW | TEAM271_SENSOR_TYPE_LIMIT_FWD_SW | TEAM271_SENSOR_TYPE_LIMIT_REV_SW)))
   {
      if (Team271Robot::CompareTime(TimeSensorSwitchUpdateLast_,
                                    kSensorSwitchUpdateRate) == 1)
      {
         UpdateSwitches();
      }
   }
}

void Team271SensorCTRE::DisabledInit(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Sensor::DisabledInit();

   /*
    * Set Position to 0
    */
   /*SetPosition(0);*/
}

/*
 *
 * Sensor Functions
 *
 */
void Team271SensorCTRE::UpdateSwitches(void)
{
#if defined(T271_CTRE)
   uint8_t tmpIsValid = 0;
   static uint8_t tmpWasValid = 0;

   if ((TalonSRX_ != nullptr) && (SensorCollection_ != nullptr))
   {
      tmpIsValid = 1;

      if (SensorCollection_->IsFwdLimitSwitchClosed() == 1)
      {
         SetLimitFwd(TEAM271_SENSOR_LIMIT_SW_STATE_CLOSED);
      }
      else
      {
         SetLimitFwd(TEAM271_SENSOR_LIMIT_SW_STATE_OPEN);
      }

      if (SensorCollection_->IsRevLimitSwitchClosed() == 1)
      {
         SetLimitRev(TEAM271_SENSOR_LIMIT_SW_STATE_CLOSED);
      }
      else
      {
         SetLimitRev(TEAM271_SENSOR_LIMIT_SW_STATE_OPEN);
      }
   }
   else if (CANifier_ != nullptr)
   {
      tmpIsValid = 1;

      if (CANifier_->GetGeneralInput(CANifier::GeneralPin::LIMF) == 1)
      {
         SetLimitFwd(TEAM271_SENSOR_LIMIT_SW_STATE_CLOSED);
      }
      else
      {
         SetLimitFwd(TEAM271_SENSOR_LIMIT_SW_STATE_OPEN);
      }

      if (CANifier_->GetGeneralInput(CANifier::GeneralPin::LIMR) == 1)
      {
         SetLimitRev(TEAM271_SENSOR_LIMIT_SW_STATE_CLOSED);
      }
      else
      {
         SetLimitRev(TEAM271_SENSOR_LIMIT_SW_STATE_OPEN);
      }
   }
   else
   {
      if (tmpWasValid == 1)
      {
         LOG_ERROR("%s - No CTRE SRX Sensor",
                   GetName().c_str());
      }

      tmpWasValid = 0;
   }

   tmpWasValid = tmpIsValid;
#endif
}

void Team271SensorCTRE::UpdatePositions(const float argConversion)
{
#if defined(T271_CTRE)
   uint8_t tmpIsValid = 0;
   static uint8_t tmpWasValid = 0;

   if (TalonSRX_ != nullptr)
   {
      tmpIsValid = 1;

      /*tmpPosition = TalonSRX_->GetSelectedSensorPosition( 0 ) / ( kSRXCountsPerRev * 4.0 ) * argConversion;*/
      /*tmpPosition = TalonSRX_->GetSelectedSensorPosition( 0 );*/
      Team271Sensor::SetPosition(TalonSRX_->GetSelectedSensorPosition(0) * argConversion);
   }
   else if (CANifier_ != nullptr)
   {
      tmpIsValid = 1;

#if 0
      double pulseWidthAndPeriod[2];
      CANifier_->GetPWMInput(CANifier::PWMChannel::PWMChannel0,
                             pulseWidthAndPeriod);

      Team271Sensor::SetPosition( pulseWidthAndPeriod[0] * argConversion );
#else
      Team271Sensor::SetPosition(CANifier_->GetQuadraturePosition() * argConversion);
#endif
   }
   else
   {
      if (tmpWasValid == 1)
      {
         LOG_ERROR("%s - No CTRE Sensor",
                   GetName().c_str());
      }

      tmpWasValid = 0;
   }

   tmpWasValid = tmpIsValid;
#endif
}

void Team271SensorCTRE::UpdateRates(const float argConversion)
{
#if defined(T271_CTRE)
   uint8_t tmpIsValid = 0;
   static uint8_t tmpWasValid = 0;

   if (TalonSRX_ != nullptr)
   {
      tmpIsValid = 1;

      /*tmpRate = ( TalonSRX_->GetSelectedSensorVelocity( 0 ) / ( kSRXCountsPerRev * 4.0 ) ) * 10.0 * argConversion;*/
      /*tmpRate = TalonSRX_->GetSelectedSensorVelocity( 0 ) * argConversion * 0.1;*/
      /*tmpRate = TalonSRX_->GetSelectedSensorVelocity( 0 );*/
      //Team271Sensor::SetRate( TalonSRX_->GetSelectedSensorVelocity( 0 ) * argConversion );
      Team271Sensor::SetRate(TalonSRX_->GetSelectedSensorVelocity(0) * argConversion);
   }
   else if (CANifier_ != nullptr)
   {
      tmpIsValid = 1;

      /*Team271Sensor::SetPosition( CANifier_->GetQuadratureVelocity() * argConversion );*/
   }
   else
   {
      if (tmpWasValid == 1)
      {
         LOG_ERROR("%s - No CTRE Sensor",
                   GetName().c_str());
      }

      tmpWasValid = 0;
   }

   tmpWasValid = tmpIsValid;
#endif
}

#endif

