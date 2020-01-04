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

#ifndef __T271HWDEF_H__
#define __T271HWDEF_H__

#if !defined(TRUE)
#define TRUE      (1)
#endif

#if !defined(FALSE)
#define FALSE     (0)
#endif

/* System voltage "Warning" level in volts */
#define VOLTAGE_WARNING    (8.0)

/* System voltage "Critical" level in volts (BrownOut @ 6.8V) */
#define VOLTAGE_CRITICAL   (7.0)

/***********************************/
/* Hardware Connection Definitions */
/***********************************/

#if defined( T271_COMP_ROBOT ) || defined( T271_DASHBOARD ) || defined( T271_SIM )
/*
 * Drive Motors
 */
/* Master: Has Encoder */
#  define FRONT_PASSENGER_MOTOR                 (2U)
/* Followers */
#  define MIDDLE_PASSENGER_MOTOR                (14U)
#  define REAR_PASSENGER_MOTOR                  (15U)

#  define PASSENGER_CANIFIER                    (15U)

/* Master: Has Encoder */
#  define FRONT_DRIVER_MOTOR                    (3U)
/* Followers */
#  define MIDDLE_DRIVER_MOTOR                   (13U)
#  define REAR_DRIVER_MOTOR                     (12U)

#  define DRIVER_CANIFIER                       (16U)

#  define PIGEON_IMU                            (20U)

/*
 * Ladder Motors
 */
/* Master: Has Encoder */
#  define LADDER_ONE_MOTOR                      (5U)
/* Followers */
#  define LADDER_TWO_MOTOR                      (6U)
#  define LADDER_THREE_MOTOR                    (4U)

#  define LADDER_CANIFIER                       (18U)

/*
 * Ladder Drive Motors
 */
#  define LADDER_DRIVE_DRIVER                   (8U)
#  define LADDER_DRIVE_PASSENGER                (9U)

/*
 *  Arm Motors
 */
/* Master: Has Encoder */
#  define ARM_ONE_MOTOR                         (11U)

#  define ARM_CANIFIER                          (17U)

/*
 *  Herder Motors
 */
#  define HERDER_DRIVER_MOTOR                   (10U)
/*#  define HERDER_PASSENGER_MOTOR                (16U)*/

/*
 *  Fork Motors
 */
/* Master: Has Encoder */
#  define FORK_ONE_MOTOR                        (0U)
/* Followers */
#  define FORK_TWO_MOTOR                        (1U)

#  define FORK_CANIFIER                         (19U)

/*
 *  Solenoids
 */
#  define PCM_TRANS_SPEED                 (0U)
#  define SOL_TRANS_SPEED_1               (0U)
#  define SOL_TRANS_SPEED_2               (1U)

#  define PCM_LADDER_SPEED                (0U)
#  define SOL_LADDER_SPEED_1              (4U)
#  define SOL_LADDER_SPEED_2              (5U)

#  define PCM_LADDER_LOCK                 (0U)
#  define SOL_LADDER_LOCK_1               (6U)
#  define SOL_LADDER_LOCK_2               (7U)

#  define PCM_HERDER_GRAB                 (0U)
#  define SOL_HERDER_GRAB_1               (2U)
#  define SOL_HERDER_GRAB_2               (3U)

#  define PCM_LIFT                        (0U)
#  define SOL_LIFT_1                      (8U)
#  define SOL_LIFT_2                      (9U)
#else

#endif

#endif /* __T271HWDEF_H__ */
