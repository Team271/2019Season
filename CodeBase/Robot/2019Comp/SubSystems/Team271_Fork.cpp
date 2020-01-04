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

#if defined( T271_FORK_ENABLE )

#define FORK_LIMIT_DOWN     (315)
#define FORK_LIMIT_UP       (1350)

#define FORK_LIMIT_DELTA    (FORK_LIMIT_UP - FORK_LIMIT_DOWN)

Team271Fork::Team271Fork( void )
      : Team271Base( nullptr,
                     "Fork",
                     t271_fork_data_index::T271_DATA_COUNT )
{
   LOG_TRACE( "%s - Constructor Start",
         GetName().c_str() );

   LOG_TRACE( "%s - Constructor End",
         GetName().c_str() );
}

Team271Fork::~Team271Fork( void )
{

}

/*
 *
 * Getters
 *
 */
const string Team271Fork::GetClassName( void ) const
{
   return "Team271Fork";
}

float Team271Fork::GetSetpoint( void ) const
{
   return Read<float>( t271_fork_data_index::T271_FORK_DATA_VALUE );
}

float Team271Fork::GetOperatorForkAxisY( void ) const
{
   /*
    * Get Fork Input
    */
#if defined(T271_INPUT_ENABLE)
   return Team271Input::Instance().GetAxis( eOperatorLeft,
                                            eOperatorLeftAxisArm ) * -1.0;
#else
   return 0;
#endif
}

/*
 *
 * Setters
 *
 */
void Team271Fork::SetSetpoint( const float argSetpoint )
{
   Write( t271_fork_data_index::T271_FORK_DATA_VALUE,
          argSetpoint );
}

/*
 *
 * Base
 *
 */
void Team271Fork::Init( void )
{
   Team271Motor* tmpMasterMotor = nullptr;
   Team271Motor* tmpSlaveMotor = nullptr;

   /*
    * Create Fork Transmission
    *
    * Add it to the Child List
    */
   _TransFork = Team271BaseManager::InstanceAdd( new Team271Transmission( this,
                                                                         "Fork" ) );

   if( _TransFork != nullptr )
   {
      /*
       * Add the motors
       */
      tmpMasterMotor = _TransFork->AddMotor( "Fork 1",
                                            TEAM271_MOTOR_CONTROLLER_TYPE_SPARK_MAX_PWM,
                                            FORK_ONE_MOTOR );

      /*tmpMasterMotor->SetInvertedOutput( TEAM271_INVERTED_STATE_INVERTED );*/
      tmpMasterMotor->SetInvertedOutput( TEAM271_INVERTED_STATE_NOT_INVERTED );
      tmpMasterMotor->SetNeutralMode( TEAM271_NEUTRAL_MODE_BRAKE );

      tmpMasterMotor->SetNeutralDeadband( 0.10f );

      tmpSlaveMotor = _TransFork->AddMotor( "Fork 2",
                                            TEAM271_MOTOR_CONTROLLER_TYPE_SPARK_MAX_PWM,
                                            FORK_TWO_MOTOR,
                                            tmpMasterMotor );

      /*
       * Setup Sensors
       */
#if 0
      _Encoder = new Team271SensorCTRE( _TransFork,
                                        "Team271Fork - Encoder",
                                        FORK_CANIFIER,
                                        TEAM271_SENSOR_TYPE_MAG_ABS,
                                        TEAM271_INVERTED_STATE_NOT_INVERTED,
                                        TEAM271_SENSOR_SETTINGS_NONE,
                                        0 );

      _TransFork->SetSensor( TEAM271_SENSOR_INDEX_ENCODER,
                            _Encoder );
#endif

      _TransFork->SetControlMode( TEAM271_CONTROL_MODE_PERCENT_OUTPUT );
   }
}

/*
 *
 * Robot
 *
 */
void Team271Fork::RobotInit( const bool argIsParent )
{
   /*
    * Base Call
    */
   Team271Base::RobotInit();

   /*
    * Zero Position
    */
   if( _TransFork != nullptr )
   {
      SetSetpoint( _TransFork->GetNeutralValue() );
   }
}

void Team271Fork::PreRobotPeriodic( const bool argIsParent )
{
   /*
    * Base Call
    */
   Team271Base::PreRobotPeriodic();

   ModePrev_ = Read<uint8_t>( t271_fork_data_index::T271_FORK_DATA_MODE );
}

void Team271Fork::PostRobotPeriodic( const bool argIsParent )
{
   uint32_t tmpCanMove = 0;

   //const int32_t tmpLowerLimit = FORK_LIMIT_DOWN;
   //const int32_t tmpUpperLimit = FORK_LIMIT_UP;

   //const int32_t tmpLowerLimit = 0;
   //const int32_t tmpUpperLimit = FORK_LIMIT_DELTA;

   /*
    * Fork
    */
   if( _TransFork != nullptr )
   {
      /*
       * Apply the Fork Value
       */
//      if( _Encoder != nullptr )
//      {
//         if( _Encoder->GetPosition() > tmpLowerLimit && tmpFork < 0 )
//         {
//            tmpCanMove = 1;
//         }
//         else if( _Encoder->GetPosition() < tmpUpperLimit && tmpFork > 0 )
//         {
//            tmpCanMove = 1;
//         }
//      }
//      else
//      {
//         /*
//          * Fail Safe Always Move
//          */
//         tmpCanMove = 1;
//      }
      tmpCanMove = 1;

#if defined(T271_INPUT_ENABLE)
      if( Team271Input::InstanceGetDSOState() == TEAM271_DSO_STATE_ACTIVE )
      {
         tmpCanMove = 1;
      }
#endif

      if( tmpCanMove == 0 )
      {
         SetSetpoint( _TransFork->GetNeutralValue() );
      }

      _TransFork->SetOutput( GetSetpoint() );
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
void Team271Fork::DisabledInit( const bool argIsParent )
{
   /*
    * Base Call
    */
   Team271Base::DisabledInit();

   /*
    * Stop Driving
    */
   if( _TransFork != nullptr )
   {
      SetSetpoint( _TransFork->GetNeutralValue() );
   }
}

void Team271Fork::AutonomousInit( const bool argIsParent )
{
   /*
    * Base Call
    */
   Team271Base::AutonomousInit();

   /*
    * Stop Driving
    */
   if( _TransFork != nullptr )
   {
      SetSetpoint( _TransFork->GetNeutralValue() );
   }
}

void Team271Fork::TeleopInit( const bool argIsParent )
{
   /*
    * Base Call
    */
   Team271Base::TeleopInit();

   /*
    * Stop Driving
    */
   if( _TransFork != nullptr )
   {
      SetSetpoint( _TransFork->GetNeutralValue() );
   }
}

void Team271Fork::TeleopPeriodic( const bool argIsParent )
{
   /*
    * Set Drive Values
    */
   SetSetpoint( _InputForkValue.load() );
}

void Team271Fork::TestInit( const bool argIsParent )
{
   /*
    * Base Call
    */
   Team271Base::TestInit();

   /*
    * Stop Driving
    */
   if( _TransFork != nullptr )
   {
      SetSetpoint( _TransFork->GetNeutralValue() );
   }
}

/*
 *
 * Robot State
 *
 */
void Team271Fork::UpdateInput( const bool argIsParent )
{
   /*
    * Base Call
    */
   Team271Base::UpdateInput();

   /*
    * Store the Previous Value
    */
   _InputForkValuePrev.store( _InputForkValue.load() );

   /*
    * Normal Throttle Drive
    */
   const float tmpForkY = GetOperatorForkAxisY() * 0.7;

   /*
    * Deadband and Deadband Scaling
    */
   float tmpForkYDeadScale = 0;
   float tmpForkXDeadScale = 0;

   ApplyRadialDeadZone( tmpForkXDeadScale,
                        tmpForkYDeadScale,
                        0,
                        tmpForkY,
                        FORK_DEADZONE_LOW,
                        FORK_DEADZONE_HIGH );

   /*
    * Apply a scaling factor for the different Gears
    */
   float tmpScaleFactor = 1.0f;

   /*
    * Calculate the new Value
    * Cube the Input, scale to Max Value
    */
   _InputForkValue.store( tmpScaleFactor * ( tmpForkYDeadScale * tmpForkYDeadScale * tmpForkYDeadScale ) + ( FORK_INPUT_MAX_SCALE - tmpScaleFactor ) * tmpForkYDeadScale );

   /*
    * Reset Zero
    */
   /*
    if( Input_->GetButtonState( eOperatorRight,
    7 ) != Input_->GetButtonStatePrev( eOperatorRight,
    7 ) )
    {
    if( Input_->GetButtonState( eOperatorRight,
    8 ) != 0 && Input_->GetButtonState( eOperatorRight,
    8 ) != 0 )
    {
    if( _TransFork != nullptr )
    {
    _TransFork->SetPosition( 0 );
    }
    }
    }
    */
}

#endif
