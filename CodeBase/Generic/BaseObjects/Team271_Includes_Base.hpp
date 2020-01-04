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

/*
 *
 * Base
 *
 */
#include "Generic\BaseObjects\Team271_Base.hpp"

/*
 *
 * Base -> Components
 *
 */
#include "Generic\BaseObjects\Components\Team271_IO.hpp"
#include "Generic\BaseObjects\Components\Team271_PWM.hpp"
#include "Generic\BaseObjects\Components\Team271_I2C.hpp"
#include "Generic\BaseObjects\Components\Team271_SPI.hpp"

#include "Generic\BaseObjects\Components\Team271_PDP.hpp"
#include "Generic\BaseObjects\Components\Team271_PCM.hpp"

#include "Generic\BaseObjects\Components\Team271_Motor.hpp"
#include "Generic\BaseObjects\Components\Team271_Solenoid.hpp"

/*
 *
 * Base -> Sensors
 *
 */
#if defined(ENABLE_VISION)
#  include "Vision\Team271_GripPipeline.hpp"
#  include "Vision\Team271_CameraServer.hpp"
#  include "Vision\Team271_Vision.hpp"
#endif

#if defined(T271_SENSOR_ENABLE)
#  include "Generic\BaseObjects\Sensors\Team271_Sensor.hpp"

#  include "Generic\BaseObjects\Sensors\Team271_SensorCTRE.hpp"

#  if defined(T271_IMU_ENABLE)
#     include "Generic\BaseObjects\Sensors\Team271_IMU.hpp"

#  if defined(T271_EM7180_ENABLE)
#     include "Generic\BaseObjects\Sensors\Team271_EM7180.hpp"
#  endif

#  if defined(T271_NAVX_ENABLE)
#     include "Generic\BaseObjects\Sensors\Team271_NavX.hpp"
#  endif

#  if defined(T271_PIGEON_ENABLE)
#     include "Generic\BaseObjects\Sensors\Team271_Pigeon.hpp"
#  endif

#  endif
#endif

/*
 *
 * Base -> Sub Systems
 *
 */

#include "Generic\BaseObjects\SubSystems\Team271_Robot.hpp"
#include "Generic\BaseObjects\SubSystems\Team271_Shifter.hpp"
#include "Generic\BaseObjects\SubSystems\Team271_Transmission.hpp"

/*
 *
 * Base -> Sub Systems -> Auto -> Auto Actions
 *
 */
#include "Generic\BaseObjects\SubSystems\Auto\Team271_AutoAction.hpp"

/*
 * Base -> Sub Systems -> Auto
 */
#include "Generic\BaseObjects\SubSystems\Auto\Team271_AutoActionList.hpp"
#include "Generic\BaseObjects\SubSystems\Auto\Team271_AutoMode.hpp"
#include "Generic\BaseObjects\SubSystems\Auto\Team271_Auto.hpp"

/*
 *
 * Managers
 *
 */
#include "Generic\BaseObjects\Team271_BaseManager.hpp"
