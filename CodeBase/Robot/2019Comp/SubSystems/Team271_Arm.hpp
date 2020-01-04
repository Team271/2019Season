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

#ifndef TEAM271_ARM_H_
#define TEAM271_ARM_H_

#if defined( T271_ARM_ENABLE )

#define ARM_DEADZONE_LOW      ( 0.05f )
#define ARM_DEADZONE_HIGH     ( 0.05f )

#define ARM_INPUT_MAX_SCALE   ( 1.000f )

#define ARM_SCALE_LOW         ( 1.0f )
#define ARM_SCALE_HIGH        ( 1.0f )

typedef enum : uint8_t
{
   /*
    * Mode
    */
   T271_ARM_MODE_MANUAL,

   T271_ARM_MODE_PID,

   T271_ARM_MODE_COUNT,
} t271_arm_mode_t;

/*
 *
 * Shared Network Data
 *
 */
class t271_arm_data_index : public t271_base_data_index
{
public:
   typedef enum : uint8_t
   {
      /*
       * Mode
       */
      T271_ARM_DATA_MODE = t271_base_data_index::T271_DATA_COUNT,

      T271_ARM_DATA_CAN_MOVE,
      T271_ARM_DATA_VALUE,

      T271_ARM_DATA_INPUT,
      T271_ARM_DATA_INPUT_PREV,

      T271_ARM_DATA_SETPOINT,
      T271_ARM_DATA_POSITION,
      T271_ARM_DATA_ERROR,

      T271_ARM_DATA_P,
      T271_ARM_DATA_I,
      T271_ARM_DATA_D,
      T271_ARM_DATA_F,

      T271_DATA_COUNT,
   } t271_arm_data_index_t;
};

class Team271Arm : public Team271Base
{
protected:
   /*
    * Transmissions
    */
   Team271Transmission* _TransArm = nullptr;

   /*
    * Sensors
    */
   Team271SensorCTRE* _Encoder = nullptr;

   /*
    *
    * Variables
    *
    */
   t271_arm_mode_t ModePrev_ = T271_ARM_MODE_MANUAL;

public:
   Team271Arm( void );

   virtual ~Team271Arm( void );

   /*
    *
    * Getters
    *
    */
   const string GetClassName( void ) const override;

   float GetSetpoint( void ) const;

   float GetOperatorArmAxisY( void ) const;

   /*
    *
    * Setters
    *
    */
   void SetSetpoint( const float argSetpoint );

   /*
    *
    * Base
    *
    */
   void Init( void ) override;

   /*
    *
    * Robot
    *
    */
   void RobotInit( const bool argIsParent = false ) override;

   void PreRobotPeriodic( const bool argIsParent = false ) override;

   void PostRobotPeriodic( const bool argIsParent = false ) override;

   /*
    *
    * Disabled
    *
    */
   void DisabledInit( const bool argIsParent = false ) override;

   /*
    *
    * Autonomous
    *
    */
   void AutonomousInit( const bool argIsParent = false ) override;

   /*
    *
    * Teleop
    *
    */
   void TeleopInit( const bool argIsParent = false ) override;
   void TeleopPeriodic( const bool argIsParent = false ) override;

   /*
    *
    * Test
    *
    */
   void TestInit( const bool argIsParent = false ) override;

   /*
    *
    * Robot State
    *
    */
   void UpdateInput( const bool argIsParent = false ) override;
};

#endif

#endif /* TEAM271_ARM_H_ */
