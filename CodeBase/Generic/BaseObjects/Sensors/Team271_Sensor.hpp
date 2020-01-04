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

#ifndef TEAM271_SENSOR_H_
#define TEAM271_SENSOR_H_

#if defined( T271_SENSOR_ENABLE )

typedef enum : uint32_t
{
   TEAM271_SENSOR_TYPE_NONE                              = (0),

   /*
    * Basic Sensors
    */
   TEAM271_SENSOR_TYPE_QUAD_ENCODER                      = (1 << 0),
   TEAM271_SENSOR_TYPE_ANALOG                            = (1 << 1),
   TEAM271_SENSOR_TYPE_PULSE_WIDTH_ENCODED_POSITION      = (1 << 2),

   TEAM271_SENSOR_TYPE_LIMIT                             = (1 << 3),
   TEAM271_SENSOR_TYPE_LIMIT_FWD                         = (1 << 4),
   TEAM271_SENSOR_TYPE_LIMIT_REV                         = (1 << 5),

   TEAM271_SENSOR_TYPE_LIMIT_SW                          = (1 << 6),
   TEAM271_SENSOR_TYPE_LIMIT_FWD_SW                      = (1 << 7),
   TEAM271_SENSOR_TYPE_LIMIT_REV_SW                      = (1 << 8),

   /*
    * Sensor Sum/Difference
    */
   TEAM271_SENSOR_TYPE_SENSOR_SUM                        = (1 << 9),
   TEAM271_SENSOR_TYPE_SENSOR_DIFFERENCE                 = (1 << 10),

   /*
    * Remote Sensors
    */
   TEAM271_SENSOR_TYPE_REMOTE_0                          = (1 << 11),
   TEAM271_SENSOR_TYPE_REMOTE_1                          = (1 << 12),

   /*
    * Other
    */
   TEAM271_SENSOR_TYPE_ACCEL                             = (1 << 13),
   TEAM271_SENSOR_TYPE_GYRO                              = (1 << 14),
   TEAM271_SENSOR_TYPE_MAG                               = (1 << 15),
   TEAM271_SENSOR_TYPE_IMU                               = (1 << 16),

   /*
    * CTRE Mag Encoder
    */
   TEAM271_SENSOR_TYPE_MAG_ABS = TEAM271_SENSOR_TYPE_PULSE_WIDTH_ENCODED_POSITION,
   TEAM271_SENSOR_TYPE_MAG_REL = TEAM271_SENSOR_TYPE_QUAD_ENCODER
}TEAM271_SENSOR_TYPE;

typedef enum : uint8_t
{
   TEAM271_SENSOR_LIMIT_SW_STATE_NONE,

   /*
    * Basic Sensors
    */
   TEAM271_SENSOR_LIMIT_SW_STATE_OPEN,
   TEAM271_SENSOR_LIMIT_SW_STATE_CLOSED,

   TEAM271_SENSOR_LIMIT_SW_STATE_COUNT
}TEAM271_SENSOR_LIMIT_SW_STATE;

typedef enum : uint8_t
{
   TEAM271_SENSOR_SETTINGS_NONE = 0,

   /*
    * For an Analog Sensor
    * If set then the readings wrap around
    */
   TEAM271_SENSOR_SETTINGS_CONTINUOUS = ( 1 << 0 ),

   /*
    * Limit Switched
    */
   TEAM271_SENSOR_SETTINGS_NORMALLY_OPEN = ( 1 << 1 ),
   TEAM271_SENSOR_SETTINGS_NORMALLY_CLOSED = ( 1 << 2 ),

   TEAM271_SENSOR_SETTINGS_COUNT
}TEAM271_SENSOR_SETTINGS;

/*
 *
 * Shared Network Data
 *
 */
class t271_sensor_data_index : public t271_base_data_index
{
public:
   typedef enum : uint8_t
   {
      /*
       * Sensor Settings
       */
      T271_SENSOR_DATA_TYPE = t271_base_data_index::T271_DATA_COUNT,

      T271_SENSOR_DATA_SETTINGS,

      T271_SENSOR_DATA_INVERTED,

      T271_SENSOR_DATA_ARGUMENT_A,
      T271_SENSOR_DATA_ARGUMENT_B,
      T271_SENSOR_DATA_ARGUMENT_C,

      /*
       * Basic Comms
       */
      T271_SENSOR_DATA_COM_PORT,
      T271_SENSOR_DATA_COM_ADDRESS,

      /*
       * Sensor Status
       */
      T271_SENSOR_DATA_CONNECTED,
      T271_SENSOR_DATA_CONNECTED_PREV,
      T271_SENSOR_DATA_INITIALIZED,
      T271_SENSOR_DATA_ERROR,

      /*
       * Sensor Position
       */
      T271_SENSOR_DATA_POSITION,
      T271_SENSOR_DATA_POSITION_X,
      T271_SENSOR_DATA_POSITION_Y,
      T271_SENSOR_DATA_POSITION_Z,

      /*
       * Sensor Rate
       */
      T271_SENSOR_DATA_RATE,
      T271_SENSOR_DATA_RATE_X,
      T271_SENSOR_DATA_RATE_Y,
      T271_SENSOR_DATA_RATE_Z,

      /*
       * Sensor Switches
       */
      T271_SENSOR_DATA_LIMIT_FWD,
      T271_SENSOR_DATA_LIMIT_REV,

      T271_DATA_COUNT,
   } t271_sensor_data_index_t;
};

class Team271Sensor : public Team271Base
{
protected:
   /*
    *
    * Constants
    *
    */
   static constexpr float kSensorSwitchUpdateRate = 0.050f;
   static constexpr float kSensorPositionUpdateRate = 0.010f;
   static constexpr float kSensorRateUpdateRate = 0.010f;

   /*
    *
    * Variables
    *
    */
   float TimeSensorSwitchUpdateLast_ = 0;
   float TimeSensorPositionUpdateLast_ = 0;
   float TimeSensorRateUpdateLast_ = 0;

public:
   /*
    *
    * Constructor/Destructor
    *
    */
   Team271Sensor(Team271Base* const argParent,
                 const string& argSensorName,
                 const uint8_t argMessageCount = t271_sensor_data_index::T271_DATA_COUNT,
                 const TEAM271_SENSOR_TYPE argSensorType = TEAM271_SENSOR_TYPE_NONE,
                 const TEAM271_INVERTED_STATE argSensorInverted = TEAM271_INVERTED_STATE_NOT_INVERTED,
                 const TEAM271_SENSOR_SETTINGS argSensorSettings = TEAM271_SENSOR_SETTINGS_NONE,
                 const float argArgumentA = 0);

   virtual ~Team271Sensor( void );

   /*
    *
    * Getters
    *
    */
   const string GetClassName( void ) const override;

   /* Comms */
   uint32_t GetComPort( void ) const;
   uint32_t GetComAddress( void ) const;

   /* Position */
   virtual float GetPosition( const float argConversion = 1.0f ) const;

   virtual float GetPositionX( const float argConversion = 1.0f ) const;

   virtual float GetPositionY( const float argConversion = 1.0f ) const;

   virtual float GetPositionZ( const float argConversion = 1.0f ) const;

   /* Rate */
   virtual float GetRate( const float argConversion = 1.0f ) const;

   virtual float GetRateX( const float argConversion = 1.0f ) const;

   virtual float GetRateY( const float argConversion = 1.0f ) const;

   virtual float GetRateZ( const float argConversion = 1.0f ) const;

   /* Switches */
   virtual TEAM271_SENSOR_LIMIT_SW_STATE GetLimitSWFwd( void ) const;

   virtual TEAM271_SENSOR_LIMIT_SW_STATE GetLimitSWRev( void ) const;

   /*
    *
    * Setters
    *
    */

   /* Position */
   virtual void SetPosition( const float argPosition );

   virtual void SetPositionX( const float argPosition );

   virtual void SetPositionY( const float argPosition );

   virtual void SetPositionZ( const float argPosition );

   /* Rate */
   virtual void SetRate( const float argRate );

   virtual void SetRateX( const float argRate );

   virtual void SetRateY( const float argRate );

   virtual void SetRateZ( const float argRate );

   /* Switches */
   virtual void SetLimitFwd( const TEAM271_SENSOR_LIMIT_SW_STATE argState );

   virtual void SetLimitRev( const TEAM271_SENSOR_LIMIT_SW_STATE argState );

   /*
    *
    * Robot Init
    *
    */
   void PreRobotPeriodic( const bool argIsParent = false ) override;

   /*
    *
    * Sensor Functions
    *
    */
private:
   virtual void UpdateSwitches( void );
   virtual void UpdatePositions( const float argConversion = 1.0f );
   virtual void UpdateRates( const float argConversion = 1.0f );
};

#endif

#endif /* TEAM271_TRANSMISSION_H_ */
