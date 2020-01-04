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

#if defined(T271_PWM_ENABLE)

t271_pwm_data_index::t271_pwm_data_index(void)
{
   Names_[T271_PWM_DATA_CHANNEL] = "T271_PWM_DATA_CHANNEL";

   Names_[T271_PWM_DATA_INVERTED] = "T271_PWM_DATA_INVERTED";

   Names_[T271_PWM_DATA_NEUTRAL_DEADBAND] = "T271_PWM_DATA_NEUTRAL_DEADBAND";
}

Team271PWM::Team271PWM(Team271Base* const argParent,
                       const uint32_t argChannel)
      : Team271Base(argParent,
                    to_string(argChannel),
                    t271_pwm_data_index::T271_DATA_COUNT)
{
#if defined( T271_IO_ENABLE )
   int32_t tmpStatus = 0;
#endif

   LOG_TRACE("%s - Constructor Start",
             GetName().c_str());

   /*
    * Store Parameters
    */
   Write(t271_pwm_data_index::T271_PWM_DATA_CHANNEL,
         argChannel);

   if (argChannel >= kNumPWMChannels)
   {
      LOG_ERROR("%s - Couldn't Open Channel %d",
                GetName().c_str(),
                argChannel);
   }
   else
   {
#if defined( T271_IO_ENABLE )
      Team271IO::getInstance().PWM_InitializePort(argChannel,
                                                  &tmpStatus);
#endif

      /* Defaults to allow an always valid config. */
      SetConfig(2.0,
                1.501,
                1.5,
                1.499,
                1.0);

      SetPeriodScale(3);

      Set(0);

#if defined( T271_IO_ENABLE )
      Team271IO::getInstance().PWM_SetEliminateDeadband(argChannel,
                                                        0);
#endif

      LatchZero();
   }

   LOG_TRACE("%s - Constructor End",
             GetName().c_str());
}

Team271PWM::~Team271PWM(void)
{
#if defined( T271_IO_ENABLE )
   int32_t tmpStatus = 0;
#endif

   Set(0);

#if defined( T271_IO_ENABLE )
   Team271IO::getInstance().PWM_FreePort(Read<uint32_t>(t271_pwm_data_index::T271_PWM_DATA_CHANNEL),
                                         &tmpStatus);
#endif
}

/*
 *
 * Getters
 *
 */
const string Team271PWM::GetClassName(void) const
{
   return "Team271PWM";
}

/*
 *
 * Setters
 *
 */
void Team271PWM::SetInverted(const TEAM271_INVERTED_STATE argInverted)
{
   Write(t271_pwm_data_index::T271_PWM_DATA_INVERTED,
         argInverted);
}

void Team271PWM::SetConfig(const double argMax,
                           const double argDeadbandMax,
                           const double argCenter,
                           const double argDeadbandMin,
                           const double argMin)
{
#if defined( T271_IO_ENABLE )
   int32_t tmpStatus = 0;

   Team271IO::getInstance().PWM_SetConfig(Read<uint32_t>(t271_pwm_data_index::T271_PWM_DATA_CHANNEL),
                                          argMax,
                                          argDeadbandMax,
                                          argCenter,
                                          argDeadbandMin,
                                          argMin,
                                          &tmpStatus);
#endif
}

void Team271PWM::SetPeriodScale(const uint32_t argScale)
{
#if defined( T271_IO_ENABLE )
   int32_t tmpStatus = 0;

   Team271IO::getInstance().PWM_SetPeriodScale(Read<uint32_t>(t271_pwm_data_index::T271_PWM_DATA_CHANNEL),
                                               argScale,
                                               &tmpStatus);
#endif
}

void Team271PWM::SetNeutralDeadband(const float argDeadband)
{
   Write(t271_pwm_data_index::T271_PWM_DATA_NEUTRAL_DEADBAND,
         argDeadband);
}

/*
 *
 * Output Functions
 *
 */
void Team271PWM::LatchZero(void)
{
#if defined( T271_IO_ENABLE )
   int32_t tmpStatus = 0;

   Team271IO::getInstance().PWM_LatchPWMZero(Read<uint32_t>(t271_pwm_data_index::T271_PWM_DATA_CHANNEL),
                                             &tmpStatus);
#endif
}

void Team271PWM::Set(const double argSet)
{
#if defined( T271_IO_ENABLE )
   int32_t tmpStatus = 0;
   double tmpSet = argSet;

   float tmpDeadband = Read<float>(t271_pwm_data_index::T271_PWM_DATA_NEUTRAL_DEADBAND);

   if (Read<TEAM271_INVERTED_STATE>(t271_pwm_data_index::T271_PWM_DATA_INVERTED) == TEAM271_INVERTED_STATE_INVERTED)
   {
      tmpSet *= -1.0;
   }

   if (fabs(tmpSet) < tmpDeadband)
   {
      tmpSet = 0;
   }

   Team271IO::getInstance().PWM_SetSpeed(Read<uint32_t>(t271_pwm_data_index::T271_PWM_DATA_CHANNEL),
                                         tmpSet,
                                         &tmpStatus);
#endif
}

#endif

