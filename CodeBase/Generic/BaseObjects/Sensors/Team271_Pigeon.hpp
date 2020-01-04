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

#ifndef TEAM271_PIGEON_H_
#define TEAM271_PIGEON_H_

#if defined(T271_PIGEON_ENABLE)

typedef enum : uint8_t
{
   TEAM271_IMU_PIGEON_STATE_RESET = 0,

   TEAM271_IMU_PIGEON_STATE_INIT,

   TEAM271_IMU_PIGEON_STATE_CAL,

   TEAM271_IMU_PIGEON_STATE_NORMAL,

   TEAM271_IMU_PIGEON_STATE_COUNT
}TEAM271_IMU_PIGEON_STATE;

/*
 *
 * Shared Network Data
 *
 */
class t271_sensor_pigeon_data_index : public t271_sensor_imu_data_index
{
public:
   typedef enum : uint8_t
   {
      T271_SENSOR_PIGEON_DATA_STATE = t271_sensor_imu_data_index::T271_DATA_COUNT,

      T271_DATA_COUNT,
   } t271_sensor_pigeon_data_index_t;
};

class Team271Pigeon : public Team271IMU
{
protected:
   /*
    *
    * Constants
    *
    */

   /*
    *
    * Variables
    *
    */
#if defined(T271_CTRE)
   PigeonIMU* PigeonIMU_ = nullptr;
#endif

   atomic<TEAM271_IMU_PIGEON_STATE> PigeonState_ = { TEAM271_IMU_PIGEON_STATE_RESET };

   /*
    * Sensor
    */
   atomic<uint8_t> ThreadSensorConnected_ = { 0 };
   atomic<uint8_t> ThreadSensorInitialized_ = { 0 };
   atomic<uint8_t> ThreadSensorError_ = { 0 };

   atomic<float> ThreadRoll_ = { 0 };
   atomic<float> ThreadPitch_ = { 0 };
   atomic<float> ThreadYaw_ = { 0 };
   atomic<float> ThreadDeclination_ = { 0 };
   atomic<float> ThreadYawZeroOffset_ = { 0 };

   atomic<float> ThreadQW_ = { 0 };
   atomic<float> ThreadQX_ = { 0 };
   atomic<float> ThreadQY_ = { 0 };
   atomic<float> ThreadQZ_ = { 0 };

   atomic<float> ThreadAX_ = { 0 };
   atomic<float> ThreadAY_ = { 0 };
   atomic<float> ThreadAZ_ = { 0 };

   atomic<float> ThreadGX_ = { 0 };
   atomic<float> ThreadGY_ = { 0 };
   atomic<float> ThreadGZ_ = { 0 };

public:
   /*
    *
    * Constructor/Destructor
    *
    */
   Team271Pigeon( Team271Base* const argParent,
                  uint32_t argCANAddress );

   virtual ~Team271Pigeon( void );

   /*
    *
    * Getters
    *
    */
   const string GetClassName( void ) const override;

   /*
    *
    * Robot
    *
    */
   void PreRobotPeriodic( const bool argIsParent = false );

   /*
    *
    * Sensor Functions
    *
    */
   void UpdateRates( const float argConversion );
};

#endif

#endif /* TEAM271_GYRO_H_ */
