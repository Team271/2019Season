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

#if defined(T271_HERDER_ENABLE)

Team271Herder::Team271Herder(void)
      : Team271Base(nullptr,
                    "Herder",
                    t271_herder_data_index::T271_DATA_COUNT)
{
   LOG_TRACE("%s - Constructor Start",
         GetName().c_str() );

   LOG_TRACE("%s - Constructor End",
         GetName().c_str() );
}

Team271Herder::~Team271Herder(void)
{

}

/*
 *
 * Getters
 *
 */
const string Team271Herder::GetClassName(void) const
{
   return "Team271Herder";
}

/*
 *
 * Setters
 *
 */
void Team271Herder::SetHerderGrabState(const t271_herder_grab_state_t argState)
{
   Write(t271_herder_data_index::T271_HERDER_DATA_GRAB_STATE,
         argState);
}

void Team271Herder::SetHerderWheelState(const t271_herder_wheels_state_t argState)
{
   Write(t271_herder_data_index::T271_HERDER_DATA_WHEELS_STATE,
         argState);
}

/*
 *
 * Base
 *
 */
void Team271Herder::Init(void)
{
   Team271Motor* tmpMasterMotor = nullptr;
   Team271Motor* tmpSlaveMotor = nullptr;

   /*
    * Create Herder Driver Transmission
    *
    * Add it to the Child List
    */
   _TransHerderDriver = Team271BaseManager::InstanceAdd(new Team271Transmission(this,
                                                                                "Driver Side"));

   if (_TransHerderDriver != nullptr)
   {
      /*
       * Add the motors
       */
      tmpMasterMotor = _TransHerderDriver->AddMotor("HerderDriver",
                                                    TEAM271_MOTOR_CONTROLLER_TYPE_SPARK_MAX_PWM,
                                                    HERDER_DRIVER_MOTOR);
      tmpMasterMotor->SetInvertedOutput(TEAM271_INVERTED_STATE_INVERTED);
      tmpMasterMotor->SetNeutralDeadband(0.05f);

      _TransHerderDriver->SetControlMode(TEAM271_CONTROL_MODE_PERCENT_OUTPUT);
   }

#if 0
   /*
    * Create Herder Passenger Transmission
    *
    * Add it to the Child List
    */
   _TransHerderPassenger = Team271BaseManager::InstanceAdd( new Team271Transmission( this,
               "Passenger Side" ) );

   if( _TransHerderPassenger != nullptr )
   {
      /*
       * Add the motors
       */
      tmpSlaveMotor = _TransHerderPassenger->AddMotor( "HerderPassenger",
            TEAM271_MOTOR_CONTROLLER_TYPE_SPARK_MAX_PWM,
            HERDER_PASSENGER_MOTOR );
      tmpSlaveMotor->SetNeutralMode( TEAM271_NEUTRAL_MODE_BRAKE );
   }
#endif

   /*
    * Initialize Herder Position
    */
   _HerderClawClose = Team271BaseManager::InstanceAdd(new Team271Solenoid(this,
                                                                          "Herder Close",
                                                                          PCM_HERDER_GRAB,
                                                                          SOL_HERDER_GRAB_1));

   _HerderClawOpen = Team271BaseManager::InstanceAdd(new Team271Solenoid(this,
                                                                         "Herder Open",
                                                                         PCM_HERDER_GRAB,
                                                                         SOL_HERDER_GRAB_2));
}

/*
 *
 * Robot
 *
 */
void Team271Herder::RobotInit(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::RobotInit();

   /*
    * Setup Herder
    */
   Write(t271_herder_data_index::T271_HERDER_DATA_GRAB_STATE,
         T271_HERDER_GRAB_CLOSE);

   Write(t271_herder_data_index::T271_HERDER_DATA_WHEELS_STATE,
         T271_HERDER_WHEELS_OFF);

   Write(t271_herder_data_index::T271_HERDER_DATA_WHEELS_VALUE,
         0.0f);
}

void Team271Herder::PreRobotPeriodic(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::PreRobotPeriodic();

   HerderGrabStatePrev_ = Read<t271_herder_grab_state_t>(t271_herder_data_index::T271_HERDER_DATA_GRAB_STATE);
   HerderWheelsStatePrev_ = Read<t271_herder_wheels_state_t>(t271_herder_data_index::T271_HERDER_DATA_WHEELS_STATE);
}

void Team271Herder::PostRobotPeriodic(const bool argIsParent)
{
   /*
    *
    * Handle Herder Open/Close
    *
    */
   if (Read<t271_herder_grab_state_t>(t271_herder_data_index::T271_HERDER_DATA_GRAB_STATE) == T271_HERDER_GRAB_OPEN)
   {
      /*
       * Open
       */
      if (_HerderClawClose != nullptr)
      {
         _HerderClawClose->SetOutput(TEAM271_SOLENOID_STATE_OFF);
      }
      if (_HerderClawOpen != nullptr)
      {
         _HerderClawOpen->SetOutput(TEAM271_SOLENOID_STATE_ON);
      }
   }
   else
   {
      /*
       * Close
       */
      if (_HerderClawClose != nullptr)
      {
         _HerderClawClose->SetOutput(TEAM271_SOLENOID_STATE_ON);
      }
      if (_HerderClawOpen != nullptr)
      {
         _HerderClawOpen->SetOutput(TEAM271_SOLENOID_STATE_OFF);
      }
   }

   /*
    *
    * Handle Herder Wheels
    *
    */
#if 0
   if( Read<t271_herder_wheels_state_t>( t271_herder_data_index::T271_HERDER_DATA_WHEELS_STATE ) == T271_HERDER_WHEELS_OFF )
   {
      if( _TransHerderDriver != nullptr )
      {
         _TransHerderDriver->SetOutput( 0 );
      }
#if 0
      if( _TransHerderPassenger != nullptr )
      {
         _TransHerderPassenger->SetOutput( 0 );
      }
#endif
   }
   else if( Read<t271_herder_wheels_state_t>( t271_herder_data_index::T271_HERDER_DATA_WHEELS_STATE ) == T271_HERDER_WHEELS_IN )
   {
      if( _TransHerderDriver != nullptr )
      {
         _TransHerderDriver->SetOutput( -0.5 );
      }
#if 0
      if( _TransHerderPassenger != nullptr )
      {
         _TransHerderPassenger->SetOutput( 1 );
      }
#endif
   }
   else if( Read<t271_herder_wheels_state_t>( t271_herder_data_index::T271_HERDER_DATA_WHEELS_STATE ) == T271_HERDER_WHEELS_OUT )
   {
      if( _TransHerderDriver != nullptr )
      {
         _TransHerderDriver->SetOutput( 0.5 );
      }
#if 0
      if( _TransHerderPassenger != nullptr )
      {
         _TransHerderPassenger->SetOutput( -1 );
      }
#endif
   }
   else if( Read<t271_herder_wheels_state_t>( t271_herder_data_index::T271_HERDER_DATA_WHEELS_STATE ) == T271_HERDER_WHEELS_OUT_AUTO )
   {
      if( _TransHerderDriver != nullptr )
      {
         _TransHerderDriver->SetOutput( 0.4 );
      }
#if 0
      if( _TransHerderPassenger != nullptr )
      {
         _TransHerderPassenger->SetOutput( -0.4 );
      }
#endif
   }
#endif

   if (_TransHerderDriver != nullptr)
   {
      float tmpValue = Read<float>(t271_herder_data_index::T271_HERDER_DATA_WHEELS_VALUE);

      _TransHerderDriver->SetOutput(tmpValue,
                                    1.0f,
                                    0);
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
void Team271Herder::DisabledInit(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::DisabledInit();

   /*
    * Setup Herder
    */
   Write(t271_herder_data_index::T271_HERDER_DATA_GRAB_STATE,
         T271_HERDER_GRAB_CLOSE);

   Write(t271_herder_data_index::T271_HERDER_DATA_WHEELS_STATE,
         T271_HERDER_WHEELS_OFF);

   Write(t271_herder_data_index::T271_HERDER_DATA_WHEELS_VALUE,
         0.0f);
}

void Team271Herder::AutonomousInit(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::AutonomousInit();

   /*
    * Setup Herder
    */
   Write(t271_herder_data_index::T271_HERDER_DATA_GRAB_STATE,
         T271_HERDER_GRAB_OPEN);

   Write(t271_herder_data_index::T271_HERDER_DATA_WHEELS_STATE,
         T271_HERDER_WHEELS_OFF);

   Write(t271_herder_data_index::T271_HERDER_DATA_WHEELS_VALUE,
         0.0f);
}

void Team271Herder::TeleopInit(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::TeleopInit();

   /*
    * Setup Herder
    */
   Write(t271_herder_data_index::T271_HERDER_DATA_GRAB_STATE,
         T271_HERDER_GRAB_OPEN);

   Write(t271_herder_data_index::T271_HERDER_DATA_WHEELS_STATE,
         T271_HERDER_WHEELS_OFF);

   Write(t271_herder_data_index::T271_HERDER_DATA_WHEELS_VALUE,
         0.0f);
}

/*
 *
 * Robot State
 *
 */
void Team271Herder::UpdateInput(const bool argIsParent)
{
   /*
    * Base Call
    */
   Team271Base::UpdateInput();

   /*
    * Check if we have new Driver Station Data
    */
#if defined(T271_INPUT_ENABLE)
   if(Team271Input::InstanceGetButtonState(eOperatorLeft,
                                           eOperatorLeftButtonHerderIn))
   {
      Write(t271_herder_data_index::T271_HERDER_DATA_WHEELS_VALUE,
            -0.9f );
   }
   else if(Team271Input::InstanceGetButtonState(eOperatorLeft,
                                                eOperatorLeftButtonHerderOut))
   {
      Write(t271_herder_data_index::T271_HERDER_DATA_WHEELS_VALUE,
            1.0f );
   }
   else
   {
      Write(t271_herder_data_index::T271_HERDER_DATA_WHEELS_VALUE,
            0.0f );
   }

   /*
    * Open Hatch
    */
   if (Team271Input::InstanceGetButtonState(eDriverLeft,
                                            eDriverButtonOpenHatch) != Team271Input::InstanceGetButtonStatePrev(eDriverLeft,
                                                                                           eDriverButtonOpenHatch))
   {
      if (Team271Input::InstanceGetButtonState(eDriverLeft,
                                               eDriverButtonOpenHatch) != 0)
      {
         SetHerderGrabState(T271_HERDER_GRAB_OPEN);
      }
   }

   /*
    * Close Hatch
    */
   if (Team271Input::InstanceGetButtonState(eDriverLeft,
                                            eDriverButtonCloseHatch) != Team271Input::InstanceGetButtonStatePrev(eDriverLeft,
                                                                                                                 eDriverButtonCloseHatch))
   {
      if (Team271Input::InstanceGetButtonState(eDriverLeft,
                                               eDriverButtonCloseHatch) != 0)
      {
         SetHerderGrabState(T271_HERDER_GRAB_CLOSE);
      }
   }
#endif
}

#endif

