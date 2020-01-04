/*
 *    FRC Team 271's 2019 Pre Season Code
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

#ifndef TEAM271_INPUTMAP_H_
#define TEAM271_INPUTMAP_H_

enum eDriverInputButtonIndex
{
   eDriverButtonDriveQuickTurn   = PS4Button_LeftBumper,

   eDriverButtonDriveLowGear     = PS4Button_Cross,
   eDriverButtonDriveHighGear    = PS4Button_Circle,

   eDriverButtonOpenHatch        = PS4Button_LeftTrigger,
   eDriverButtonCloseHatch       = PS4Button_RightTrigger,

   eDriverButtonDSO1             = PS4Button_Share,
   eDriverButtonDSO2             = PS4Button_Option,
};

enum eDriverInputAxisIndex
{
   eDriverAxisDriveDriverX       = PS4Axis_LeftX,
   eDriverAxisDriveDriverY       = PS4Axis_LeftY,

   eDriverAxisDrivePassnegerX    = PS4Axis_RightX,
   eDriverAxisDrivePassnegerY    = PS4Axis_RightY,
};

enum eOperatorLeftInputAxisIndex
{
   eOperatorLeftAxisLadder          = PS4Axis_LeftY,

   eOperatorLeftAxisArm             = PS4Axis_RightY,

   eOperatorLeftAxisFork            = PS4Axis_LeftX,

   eOperatorLeftAxisElevationDown   = PS4Axis_RightTrigger,
   eOperatorLeftAxisElevationUp     = PS4Axis_LeftTrigger,
};

enum eOperatorLeftInputButtonIndex
{
   eOperatorLeftButtonLadderLowGear    = PS4Button_RightBumper,
   eOperatorLeftButtonLadderHighGear   = PS4Button_LeftTrigger,

   eOperatorLeftButtonBreakOff         = PS4Button_Circle,
   eOperatorLeftButtonBreakOn          = PS4Button_Triangle,

   eOperatorLeftButtonHerderIn         = PS4Button_RightBumper,
   eOperatorLeftButtonHerderOut        = PS4Button_LeftBumper,

   eOperatorLeftButtonDSOEnter         = PS4Button_Share,
   eOperatorLeftButtonDSOExit          = PS4Button_Option,
};

#endif /* TEAM271_INCLUDES_H_ */
