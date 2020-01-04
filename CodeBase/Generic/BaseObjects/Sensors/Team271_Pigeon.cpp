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

#if defined(T271_PIGEON_ENABLE)

Team271Pigeon::Team271Pigeon(Team271Base* const argParent,
                             uint32_t argCANAddress)
      : Team271IMU(argParent,
                   "Pigeon",
                   t271_sensor_pigeon_data_index::T271_DATA_COUNT,
                   argCANAddress)
{
   LOG_TRACE("%s - Constructor Start",
             GetName().c_str());

   Write(t271_sensor_pigeon_data_index::T271_SENSOR_PIGEON_DATA_STATE,
         TEAM271_IMU_PIGEON_STATE_RESET);

#if defined(T271_CTRE)
   PigeonIMU_ = new PigeonIMU(argCANAddress);
#endif

   LOG_TRACE("%s - Constructor End",
             GetName().c_str());
}

Team271Pigeon::~Team271Pigeon(void)
{

}

/*
 *
 * Getters
 *
 */
const string Team271Pigeon::GetClassName(void) const
{
   return "Team271Pigeon";
}

/*
 *
 * Robot
 *
 */
void Team271Pigeon::PreRobotPeriodic(const bool argIsParent)
{
   Write(t271_sensor_data_index::T271_SENSOR_DATA_CONNECTED,
         ThreadSensorConnected_.load());

   Write(t271_sensor_data_index::T271_SENSOR_DATA_INITIALIZED,
         ThreadSensorInitialized_.load());

   Write(t271_sensor_data_index::T271_SENSOR_DATA_ERROR,
         ThreadSensorError_.load());

   ThreadDeclination_.store(Read<float>(t271_sensor_imu_data_index::T271_SENSOR_IMU_DATA_DECLINATION));

   ThreadYawZeroOffset_.store(Read<float>(t271_sensor_imu_data_index::T271_SENSOR_IMU_DATA_YAW_ZERO_OFFSET));

   /*
    * Base Call
    */
   Team271IMU::PreRobotPeriodic();

#if defined(T271_CTRE)
   if (PigeonIMU_->GetState() == PigeonIMU::PigeonState::NoComm)
   {
      PigeonState_.store(TEAM271_IMU_PIGEON_STATE_RESET);

      ThreadSensorConnected_.store(0);
      ThreadSensorInitialized_.store(0);
      ThreadSensorError_.store(0);
   }
   else if (PigeonIMU_->GetState() == PigeonIMU::PigeonState::Initializing)
   {
      ThreadSensorConnected_.store(1);
      ThreadSensorInitialized_.store(0);
   }
   else if (PigeonIMU_->GetState() == PigeonIMU::PigeonState::Ready)
   {
      ThreadSensorConnected_.store(1);
      ThreadSensorInitialized_.store(1);

      /*
       * Reset State
       */
      if (PigeonState_.load() == TEAM271_IMU_PIGEON_STATE_RESET)
      {
         PigeonState_.store(TEAM271_IMU_PIGEON_STATE_INIT);
      }

      /*
       * Init State
       */
      if (PigeonState_.load() == TEAM271_IMU_PIGEON_STATE_INIT)
      {
#if 0
         tmpStatus = PigeonIMU_->SetCompassDeclination( ThreadDeclination_.load(),
                                                        _StatusFrameRateTimeout );

         if( tmpStatus == 0 )
         {
            PigeonState_.store( TEAM271_IMU_PIGEON_STATE_CAL );
         }
#endif
         PigeonState_.store(TEAM271_IMU_PIGEON_STATE_CAL);
      }

      /*
       * Calibration State
       */
      if (PigeonState_.load() == TEAM271_IMU_PIGEON_STATE_CAL)
      {
         /*
          * Store the Start Time
          */
         UpdateTimeStart_ = Team271Robot::GetTime();

         PigeonState_.store(TEAM271_IMU_PIGEON_STATE_NORMAL);
      }

      /*
       * Normal State
       */
      if (PigeonState_.load() == TEAM271_IMU_PIGEON_STATE_NORMAL)
      {
         /*
          * Check Loop Rate for EEPROM Reset and Detect
          */
         if (Team271Robot::CompareTime(UpdateTimeStart_,
                                       0.005f) == 1)
         {
            double wxyz[4];
            PigeonIMU_->Get6dQuaternion(wxyz);

            ThreadQW_ = wxyz[0];
            ThreadQX_ = wxyz[1];
            ThreadQY_ = wxyz[2];
            ThreadQZ_ = wxyz[3];

            double ypr[3];
            PigeonIMU_->GetYawPitchRoll(ypr);

            ThreadYaw_.store(ypr[0]);
            ThreadPitch_.store(ypr[1]);
            ThreadRoll_.store(ypr[2]);

            double tiltAngles[3];
            PigeonIMU_->GetAccelerometerAngles(tiltAngles);

            ThreadAX_.store(tiltAngles[0]);
            ThreadAY_.store(tiltAngles[1]);
            ThreadAZ_.store(tiltAngles[2]);

            double xyz_dps[3];
            PigeonIMU_->GetRawGyro(xyz_dps);

            ThreadGX_.store(xyz_dps[0]);
            ThreadGY_.store(xyz_dps[1]);
            ThreadGZ_.store(xyz_dps[2]);
         }
      }
   }
   else if (PigeonIMU_->GetState() == PigeonIMU::PigeonState::UserCalibration)
   {

   }
#endif
}

/*
 *
 * Sensor Functions
 *
 */
void Team271Pigeon::UpdateRates(const float argConversion)
{
   /*
    * Grab the latest values from the IMU Thread
    */
   SetQW(ThreadQW_);
   SetQX(ThreadQX_);
   SetQY(ThreadQY_);
   SetQZ(ThreadQZ_);

   SetRoll(ThreadRoll_);
   SetPitch(ThreadPitch_);
   SetYaw(ThreadYaw_);

   SetAccelX(ThreadAX_);
   SetAccelY(ThreadAY_);
   SetAccelZ(ThreadAZ_);

   SetGyroX(ThreadGX_);
   SetGyroY(ThreadGY_);
   SetGyroZ(ThreadGZ_);
}

#endif
