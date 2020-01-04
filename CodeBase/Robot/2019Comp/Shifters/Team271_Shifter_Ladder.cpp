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

#if defined( T271_SHIFTER_ENABLE )

/*
 *
 * Team271Shifter_LadderSpeed
 *
 */
Team271Shifter_LadderSpeed::Team271Shifter_LadderSpeed( Team271Base* const argParent )
      : Team271Shifter( argParent,
                        "Ladder Speed" )
{

}

Team271Shifter_LadderSpeed::~Team271Shifter_LadderSpeed( void )
{

}

/*
 *
 * Getters
 *
 */
const string Team271Shifter_LadderSpeed::GetClassName( void ) const
{
   return "Team271Shifter_LadderSpeed";
}

const string Team271Shifter_LadderSpeed::GetGearName( const eGear argGear ) const
{
   string tmpReturnValue = "Invalid";

   if( argGear >= TEAM271_GEAR_COUNT )
   {
      LOG_ERROR( "%s - Invalid Gear Index",
                 GetName().c_str(),
                 argGear );
   }
   else if( argGear == TEAM271_GEAR_1 )
   {
      tmpReturnValue = "Low";
   }
   else if( argGear == TEAM271_GEAR_2 )
   {
      tmpReturnValue = "High";
   }

   return tmpReturnValue;
}

bool Team271Shifter_LadderSpeed::GetSolState(const eGear argGear,
                                             const uint32_t argIndex) const
{
   const bool tmpSolState[TEAM271_GEAR_COUNT][TEAM271_GEAR_COUNT] = { { true,
                                                                        false,
                                                                        false,
                                                                        false },
                                                                      { false,
                                                                        true,
                                                                        false,
                                                                        false },
                                                                      { false,
                                                                        false,
                                                                        false,
                                                                        false },
                                                                      { false,
                                                                        false,
                                                                        false,
                                                                        false } };

   bool tmpReturn = false;

   if( argGear >= TEAM271_GEAR_COUNT )
   {
      LOG_ERROR( "%s - Invalid Gear Index",
                 GetName().c_str(),
                 argGear );
   }
   else if( argIndex >= TEAM271_GEAR_COUNT )
   {
      LOG_ERROR( "%s - Invalid Sol Index",
                 GetName().c_str(),
                 argGear );
   }
   else
   {
      tmpReturn = tmpSolState[argGear][argIndex];
   }

   return tmpReturn;
}

/*
 *
 * Base
 *
 */
void Team271Shifter_LadderSpeed::Init( void )
{
   /*
    * Low Gear
    */
   SolTransShifter_[LADDER_LOW] = Team271BaseManager::InstanceAdd( new Team271Solenoid( this,
                                                                                        GetGearName( (eGear)LADDER_LOW ),
                                                                                        PCM_LADDER_SPEED,
                                                                                        SOL_LADDER_SPEED_1 ) );

   /*
    * High Gear
    */
   SolTransShifter_[LADDER_HIGH] = Team271BaseManager::InstanceAdd( new Team271Solenoid( this,
                                                                                         GetGearName( (eGear)LADDER_HIGH ),
                                                                                         PCM_LADDER_SPEED,
                                                                                         SOL_LADDER_SPEED_2 ) );

   SetGear( (eGear)LADDER_HIGH );
}

/*
 *
 * Team271Shifter_LadderLock
 *
 */
Team271Shifter_LadderLock::Team271Shifter_LadderLock( Team271Base* const argParent )
      : Team271Shifter( argParent,
                        "Ladder Lock" )
{

}

Team271Shifter_LadderLock::~Team271Shifter_LadderLock( void )
{

}

/*
 *
 * Getters
 *
 */
const string Team271Shifter_LadderLock::GetClassName( void ) const
{
   return "Team271Shifter_LadderLock";
}

const string Team271Shifter_LadderLock::GetGearName( const eGear argGear ) const
{
   string tmpReturnValue = "Invalid";

   if( argGear >= TEAM271_GEAR_COUNT )
   {
      LOG_ERROR( "%s - Invalid Gear Index",
                 GetName().c_str(),
                 argGear );
   }
   else if( argGear == TEAM271_GEAR_1 )
   {
      tmpReturnValue = "Lock Off";
   }
   else if( argGear == TEAM271_GEAR_2 )
   {
      tmpReturnValue = "Lock On";
   }

   return tmpReturnValue;
}

bool Team271Shifter_LadderLock::GetSolState(const eGear argGear,
                                            const uint32_t argIndex) const
{
   const bool tmpSolState[TEAM271_GEAR_COUNT][TEAM271_GEAR_COUNT] = { { true,
                                                                        false,
                                                                        false,
                                                                        false },
                                                                      { false,
                                                                        true,
                                                                        false,
                                                                        false },
                                                                      { false,
                                                                        false,
                                                                        false,
                                                                        false },
                                                                      { false,
                                                                        false,
                                                                        false,
                                                                        false } };

   bool tmpReturn = false;

   if( argGear >= TEAM271_GEAR_COUNT )
   {
      LOG_ERROR( "%s - Invalid Gear Index",
                 GetName().c_str(),
                 argGear );
   }
   else if( argIndex >= TEAM271_GEAR_COUNT )
   {
      LOG_ERROR( "%s - Invalid Sol Index",
                 GetName().c_str(),
                 argGear );
   }
   else
   {
      tmpReturn = tmpSolState[argGear][argIndex];
   }

   return tmpReturn;
}

/*
 *
 * Base
 *
 */
void Team271Shifter_LadderLock::Init( void )
{
   /*
    * Lock Off
    */
   SolTransShifter_[LADDER_LOCK_OFF] = Team271BaseManager::InstanceAdd( new Team271Solenoid( this,
                                                                                             GetGearName( (eGear)LADDER_LOCK_OFF ),
                                                                                             PCM_LADDER_LOCK,
                                                                                             SOL_LADDER_LOCK_1 ) );

   /*
    * Lock On
    */
   SolTransShifter_[LADDER_LOCK_ON] = Team271BaseManager::InstanceAdd( new Team271Solenoid( this,
                                                                                            GetGearName( (eGear)LADDER_LOCK_ON ),
                                                                                            PCM_LADDER_LOCK,
                                                                                            SOL_LADDER_LOCK_2 ) );

   SetGear( (eGear)LADDER_LOCK_OFF );
}
#endif
