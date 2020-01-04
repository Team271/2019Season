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

#ifndef TEAM271_INCLUDES_H_
#define TEAM271_INCLUDES_H_

/*
 * Team 271
 */
#include "units/units.hpp"

#include "Team271_Config.hpp"

#include "frc/controller/PIDController.h"
#include "frc/controller/ProfiledPIDController.h"

/*
 * Standard Library
 */
#include <atomic>
#include <chrono>
#include <cmath>
#include <condition_variable>
#include <cstring>
#include <cstdlib>
#include <fcntl.h>
#include <float.h>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <signal.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <thread>

#define _USE_MATH_DEFINES
#include <math.h>

#if defined(__linux__)
#include <linux/spi/spidev.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#include <pthread.h>
#include <sys/ioctl.h>
#include <sys/prctl.h>
#include <unistd.h>
#endif

using namespace std;

/*
 * ZMQ
 */
#include "zmq.hpp"
#include "zmq_addon.hpp"
#include "zhelpers.hpp"
#include "zmsg.hpp"

using namespace zmq;

/*
 * WPI HAL
 */
#include <FRC_NetworkCommunication/FRCComm.h>
#include <FRC_NetworkCommunication/LoadOut.h>
#include <FRC_NetworkCommunication/CANSessionMux.h>
#include <FRC_NetworkCommunication/NetCommRPCProxy_Occur.h>

static_assert(sizeof(int32_t) >= sizeof(int),
      "FRC_NetworkComm status variable is larger than 32 bits");

#include <FRC_FPGA_ChipObject/RoboRIO_FRC_ChipObject_Aliases.h>
#include <FRC_FPGA_ChipObject/nRoboRIO_FPGANamespace/nInterfaceGlobals.h>
#include <FRC_FPGA_ChipObject/nRoboRIO_FPGANamespace/tAI.h>
#include <FRC_FPGA_ChipObject/nRoboRIO_FPGANamespace/tAO.h>
#include <FRC_FPGA_ChipObject/nRoboRIO_FPGANamespace/tAccel.h>
#include <FRC_FPGA_ChipObject/nRoboRIO_FPGANamespace/tAccumulator.h>
#include <FRC_FPGA_ChipObject/nRoboRIO_FPGANamespace/tAlarm.h>
#include <FRC_FPGA_ChipObject/nRoboRIO_FPGANamespace/tAnalogTrigger.h>
#include <FRC_FPGA_ChipObject/nRoboRIO_FPGANamespace/tBIST.h>
#include <FRC_FPGA_ChipObject/nRoboRIO_FPGANamespace/tCounter.h>
#include <FRC_FPGA_ChipObject/nRoboRIO_FPGANamespace/tDIO.h>
#include <FRC_FPGA_ChipObject/nRoboRIO_FPGANamespace/tDMA.h>
#include <FRC_FPGA_ChipObject/nRoboRIO_FPGANamespace/tEncoder.h>
#include <FRC_FPGA_ChipObject/nRoboRIO_FPGANamespace/tGlobal.h>
#include <FRC_FPGA_ChipObject/nRoboRIO_FPGANamespace/tInterrupt.h>
#include <FRC_FPGA_ChipObject/nRoboRIO_FPGANamespace/tPWM.h>
#include <FRC_FPGA_ChipObject/nRoboRIO_FPGANamespace/tPower.h>
#include <FRC_FPGA_ChipObject/nRoboRIO_FPGANamespace/tRelay.h>
#include <FRC_FPGA_ChipObject/nRoboRIO_FPGANamespace/tSPI.h>
#include <FRC_FPGA_ChipObject/nRoboRIO_FPGANamespace/tSysWatchdog.h>
#include <FRC_FPGA_ChipObject/tDMAChannelDescriptor.h>
#include <FRC_FPGA_ChipObject/tDMAManager.h>
#include <FRC_FPGA_ChipObject/tInterruptManager.h>
#include <FRC_FPGA_ChipObject/tSystem.h>
#include <FRC_FPGA_ChipObject/tSystemInterface.h>

namespace hal {
using namespace nFPGA;
using namespace nRoboRIO_FPGANamespace;
}  /* namespace hal */

/*
 * CTRE
 */
#if !defined(T271_DASHBOARD) && !defined(T271_SIM)
#include "ctre/Phoenix.h"
#endif

/*
 * Jaci
 */
#if !defined(T271_DASHBOARD) && !defined(T271_SIM)
#include "pathfinder.h"
#endif

/*
#include "Eigen\Core"

#include "controller\PeriodVariantKalmanFilterCoeffs.h"
#include "controller\PeriodVariantLoop.h"
#include "controller\PeriodVariantPlantCoeffs.h"
#include "controller\StateSpaceControllerCoeffs.h"
#include "controller\StateSpaceController.h"
#include "controller\StateSpaceLoop.h"
#include "controller\StateSpaceObserver.h"
#include "controller\StateSpacePlant.h"
#include "controller\StateSpacePlantCoeffs.h"

#include "Subsystems\DrivetrainCoeffs.h"
#include "Subsystems\DrivetrainController.h"
*/

/*
 * Team 271
 */
#include "Team271_HW_DEF.hpp"

#include "Team271_Constants.hpp"

/*
 *
 * Generic
 *
 */
#include "Generic\Team271_Includes_Generic.hpp"

/*
 *
 * Robot
 *
 */
#include "Robot\2019Comp\Team271_InputMap.hpp"

#include "Robot\2019Comp\Shifters\Team271_Shifter_Drive.hpp"
#include "Robot\2019Comp\Shifters\Team271_Shifter_Ladder.hpp"

#include "Robot\2019Comp\SubSystems\Team271_Drive.hpp"
#include "Robot\2019Comp\SubSystems\Team271_Ladder.hpp"
#include "Robot\2019Comp\SubSystems\Team271_Arm.hpp"
#include "Robot\2019Comp\SubSystems\Team271_Herder.hpp"
#include "Robot\2019Comp\SubSystems\Team271_Fork.hpp"

/*
 * Robot -> Auto Actions
 */
#include "Robot\2019Comp\Auto\AutoActions\Team271_AutoActionDrive.hpp"
#include "Robot\2019Comp\Auto\AutoActions\Team271_AutoActionDriveGame.hpp"
#include "Robot\2019Comp\Auto\AutoActions\Team271_AutoActionLadder.hpp"

/*
 *
 * UI
 *
 */
#if defined(T271_DASHBOARD) || defined(T271_SIM)
#include "UI\Team271_Includes_UI.hpp"
#endif

/*
 *
 * Threads
 *
 */
#if !defined(T271_DASHBOARD) && !defined(T271_SIM)
#include "Threads\Team271_Includes_Threads.hpp"
#endif

/*
 *
 * Network
 *
 */
#include "Network\Team271_Publisher_Robot.hpp"

/*
 *
 * Globals
 *
 */
#include "Team271_Globals.hpp"

/*
 *
 * Main
 *
 */

#include "Team271_MainLoop.hpp"
#include "main.h"

#endif /* TEAM271_INCLUDES_H_ */
