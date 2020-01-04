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

#ifndef TEAM271_INPUT_H_
#define TEAM271_INPUT_H_

#define INPUT_DSO_WAIT_COUNT           ( 128 )

#define DSO_INIT_STATE                 ( TEAM271_DSO_STATE_INACTIVE )

static constexpr uint32_t kMaxJoystickAxes = 12;
static constexpr uint32_t kMaxJoystickPOVs = 12;
static constexpr uint32_t kMaxJoystickButtons = 15;
static constexpr uint32_t kMaxJoysticks = 6;

enum eInputJoystickPOV
{
   eInputJoystickPOVUp     = 0,
   eInputJoystickPOVRight  = 90,
   eInputJoystickPOVDown   = 180,
   eInputJoystickPOVLeft   = 270,
   eInputJoystickPOVMax
};

/*
 * Input USB Port Numbers
 *
 * ASSIGN All Input USB Ports Here
 * This can be a Joystick, Gamepad, Xbox Controller, Etc.
 */
enum eInputIndex
{
   eDriverLeft       = 0,
   eDriverRight      = 1,
   eOperatorLeft     = 2,
   eInputIndexMax
};

/*
 * PS4 Controller Button Index
 *
 * PS4:
 * Square(Left)   0
 * Cross          1
 * Circle(Right)  2
 * Triangle       3
 * Left Bumper    4
 * Right Bumper   5
 * Left Trigger   6
 * Right Trigger  7
 * Share(Left)    8
 * Option(Right)  9
 * Left Stick     10
 * Right Stick    11
 * PS             12
 * Trackpad       13
 */
enum ePS4Buttons
{
   PS4Button_Square        = 0,
   PS4Button_Cross         = 1,
   PS4Button_Circle        = 2,
   PS4Button_Triangle      = 3,
   PS4Button_LeftBumper    = 4,
   PS4Button_RightBumper   = 5,
   PS4Button_LeftTrigger   = 6,
   PS4Button_RightTrigger  = 7,
   PS4Button_Share         = 8,
   PS4Button_Option        = 9,
   PS4Button_LeftStick     = 10,
   PS4Button_RightStick    = 11,
   PS4Button_PS            = 12,
   PS4Button_Trackpad      = 13,
};

/*
 * PS4 Controller POV Index
 *
 * PS4:
 * Square(Left)   0
 * Cross          1
 * Circle(Right)  2
 * Triangle       3
 * Left Bumper    4
 * Right Bumper   5
 * Left Trigger   6
 * Right Trigger  7
 * Share(Left)    8
 * Option(Right)  9
 * Left Stick     10
 * Right Stick    11
 * PS             12
 * Trackpad       13
 */
enum ePS4POV
{
   ePS4POV_North        = 0,
   ePS4POV_NorthEast    = 45,
   ePS4POV_East         = 90,
   ePS4POV_SouthEast    = 135,
   ePS4POV_South        = 180,
   ePS4POV_SouthWest    = 225,
   ePS4POV_West         = 270,
   ePS4POV_NorthWest    = 315,
};

/*
 * PS4 Controller Axis Index
 *
 * Left X         0
 * Left Y         1
 * Right X        2
 * Left Trigger   3
 * Right Trigger  4
 * Right Y        5
 */
enum ePS4Axis
{
   PS4Axis_LeftX         = 0,
   PS4Axis_LeftY         = 1,
   PS4Axis_RightX        = 2,
   PS4Axis_LeftTrigger   = 3,
   PS4Axis_RightTrigger  = 4,
   PS4Axis_RightY        = 5,
};

#if defined(T271_INPUT_ENABLE)

/*
 *
 * Structures
 *
 */
typedef struct
{
   int16_t count;
   int16_t axes[kMaxJoystickAxes];
} T271_JoystickAxesInt;

typedef struct
{
   int16_t count;
   float axes[kMaxJoystickAxes];
} T271_JoystickAxes;

typedef struct
{
   int16_t count;
   int16_t povs[kMaxJoystickPOVs];
}T271_JoystickPOVs;

typedef struct
{
   uint32_t buttons;
   uint8_t count;
} T271_JoystickButtons;

typedef struct
{
   uint8_t isXbox;
   uint8_t type;
   char name[256];
   uint8_t axisCount;
   uint8_t axisTypes[kMaxJoystickAxes];
   uint8_t buttonCount;
   uint8_t povCount;
} T271_JoystickDescriptor;

/*
 *
 * Shared Network Data
 *
 */
class t271_input_data_index : public t271_network_data_index
{
public:
   typedef enum : uint8_t
   {
      T271_INPUT_DATA_DSO_STATE = t271_network_data_index::T271_DATA_COUNT,

      T271_INPUT_DATA_USER_BUTTON,
      T271_INPUT_DATA_USER_BUTTON_ACTION,

      T271_DATA_COUNT,
   } t271_input_data_index_t;
};

class Team271Input : public Team271NetworkObject
{
private:
   /*
    *
    * Variables
    *
    */
   atomic_flag UpdateFlag_ = ATOMIC_FLAG_INIT;

   T271_JoystickDescriptor _Desc[eInputIndexMax];

   T271_JoystickAxes _Axes[eInputIndexMax];
   T271_JoystickPOVs _Povs[eInputIndexMax];
   T271_JoystickButtons _Buttons[eInputIndexMax];

   T271_JoystickAxes _AxesPrev[eInputIndexMax];
   T271_JoystickPOVs _PovsPrev[eInputIndexMax];
   T271_JoystickButtons _ButtonsPrev[eInputIndexMax];

   /*
    * User Button
    */
   bool _InputUserButtonStatePrev = false;

   /*
    * Double Secret Override
    */
   TEAM271_DSO_STATE _DSOStatePrev = DSO_INIT_STATE;
   uint32_t _DSOToggleCnt = 0;

public:
   static Team271Input& Instance( void );

   static TEAM271_DSO_STATE InstanceGetDSOState( void );

   static double InstanceGetAxis( const eInputIndex newInputIndex,
                                  const uint32_t newAxis );

   static double InstanceGetAxisPrev( const eInputIndex newInputIndex,
                                      const uint32_t newAxis );

   static int32_t InstanceGetPOVState( const eInputIndex newInputIndex,
                                       const uint32_t newPOV );

   static int32_t InstanceGetPOVStatePrev( const eInputIndex newInputIndex,
                                           const uint32_t newPOV );

   static bool InstanceGetButtonState( const eInputIndex newInputIndex,
                                       const uint32_t newButton );

   static bool InstanceGetButtonStatePrev( const eInputIndex newInputIndex,
                                           const uint32_t newButton );

   Team271Input( void );
   ~Team271Input( void );

   Team271Input( Team271Input const& ) = delete;
   void operator=( Team271Input const& ) = delete;

   /*
    *
    * Getters
    *
    */
   uint32_t GetHasNewData( void ) const;

   bool IsUserButtonAction( void ) const;

   TEAM271_DSO_STATE GetDSOState( void ) const;

   double GetAxis( const eInputIndex newInputIndex,
                   const uint32_t newAxis ) const;

   double GetAxisPrev( const eInputIndex newInputIndex,
                       const uint32_t newAxis ) const;

   int32_t GetPOVState( const eInputIndex newInputIndex,
                        const uint32_t newPOV ) const;

   int32_t GetPOVStatePrev( const eInputIndex newInputIndex,
                            const uint32_t newPOV ) const;

   bool GetButtonState( const eInputIndex newInputIndex,
                        const uint32_t newButton ) const;

   bool GetButtonStatePrev( const eInputIndex newInputIndex,
                            const uint32_t newButton ) const;

   /*
    *
    * Setters
    *
    */
   void SetDSOState( const TEAM271_DSO_STATE argDSOState );

   /*
    *
    * Updates
    *
    */
   void UpdateInput( void );
};

#endif

#endif /* TEAM271_INPUT_H_ */
