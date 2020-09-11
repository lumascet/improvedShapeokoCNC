/*
 * settings_shapeoko2.h - Shapeoko2 500mm table
 * This file is part of the g2core project
 *
 * Copyright (c) 2010 - 2018 Alden S. Hart, Jr.
 *
 * This file ("the software") is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2 as published by the
 * Free Software Foundation. You should have received a copy of the GNU General Public
 * License, version 2 along with the software.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, you may use this file as part of a software library without
 * restriction. Specifically, if other files instantiate templates or use macros or
 * inline functions from this file, or you compile this file and link it with  other
 * files to produce an executable, this file does not by itself cause the resulting
 * executable to be covered by the GNU General Public License. This exception does not
 * however invalidate any other reasons why the executable file might be covered by the
 * GNU General Public License.
 *
 * THE SOFTWARE IS DISTRIBUTED IN THE HOPE THAT IT WILL BE USEFUL, BUT WITHOUT ANY
 * WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
 * SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/***********************************************************************/
/**** Shapeoko2 500mm profile ******************************************/
/***********************************************************************/

// ***> NOTE: The init message must be a single line with no CRs or LFs
#define INIT_MESSAGE "Initializing configs to ShapeokoMOD"

//**** GLOBAL / GENERAL SETTINGS ******************************************************

#define JUNCTION_INTEGRATION_TIME   0.75     // cornering - between 0.10 and 2.00 (higher is faster)
#define CHORDAL_TOLERANCE           0.01    // chordal accuracy for arc drawing (in mm)

#define SOFT_LIMIT_ENABLE           1       // 0=off, 1=on
#define HARD_LIMIT_ENABLE           1       // 0=off, 1=on
#define SAFETY_INTERLOCK_ENABLE     1       // 0=off, 1=on

#define SPINDLE_POLARITY            1
#define SPINDLE_ENABLE_POLARITY     1                       // 0=active low, 1=active high
#define SPINDLE_DIR_POLARITY        0                       // 0=clockwise is low, 1=clockwise is high
#define SPINDLE_PAUSE_ON_HOLD       true
#define SPINDLE_SPINUP_DELAY        1.0
#define SPINDLE_SPEED_MIN           0.0
#define SPINDLE_SPEED_MAX           24000.0
#define SPINDLE_SPEED_CHANGE_PER_MS 7.0

#define SPINDLE_ENABLE_OUTPUT_NUMBER 	12
#define SPINDLE_DIRECTION_OUTPUT_NUMBER 13
#define SPINDLE_PWM_NUMBER 		11

#define LASER_MIN_S 0
#define LASER_MAX_S 0
#define LASER_PULSE_DURATION 0
#define LASER_MIN_PPM 0
#define LASER_MAX_PPM 0

#define HAS_LASER 0
#define LASER_TOOL 0
#define BASE_KINEMATICS 1
#define LASER_FIRE_PIN_NUMBER 0

#define P1_PWM_FREQUENCY                10000					// in Hz
#define P1_CW_SPEED_LO                  0		    		// in RPM (arbitrary units)
#define P1_CW_SPEED_HI                  24000
#define P1_CW_PHASE_LO                  0			  	// phase [0..1]
#define P1_CW_PHASE_HI                  1
#define P1_CCW_SPEED_LO                 0
#define P1_CCW_SPEED_HI                 24000
#define P1_CCW_PHASE_LO                 0
#define P1_CCW_PHASE_HI                 1
#define P1_PWM_PHASE_OFF                0.0

#define ESC_BOOT_TIME               5000    // how long the ESC takes to boot, in milliseconds
#define ESC_LOCKOUT_TIME            900     // how long the interlock needs to be engaged before killing power... actually 1s, but be conservative

#define COOLANT_MIST_POLARITY       1       // 0=active low, 1=active high
#define COOLANT_FLOOD_POLARITY      1       // 0=active low, 1=active high
#define COOLANT_PAUSE_ON_HOLD       true

#define FEEDHOLD_Z_LIFT             -1       // mm to lift Z on feedhold, or -1 to go to Z-max
#define PROBE_REPORT_ENABLE         true

#define MANUAL_FEEDRATE_OVERRIDE_ENABLE false
// Switch definitions for interlock & E-stop
#define ENABLE_INTERLOCK_AND_ESTOP
#define INTERLOCK_SWITCH_INPUT          4   // DI4
#define ESTOP_SWITCH_INPUT              2   // DI2
#undef PAUSE_DWELL_TIME
#define PAUSE_DWELL_TIME                1.5 //after unpausing and turning the spindle on, dwell for 1.5s

// Communications and reporting settings

#define USB_SERIAL_PORTS_EXPOSED    1                   // Valid options are 1 or 2, only!

#define COMM_MODE                   AUTO_MODE           // one of: TEXT_MODE, JSON_MODE
#define XIO_ENABLE_FLOW_CONTROL     FLOW_CONTROL_RTS    // FLOW_CONTROL_OFF, FLOW_CONTROL_RTS

#define TEXT_VERBOSITY              TV_VERBOSE          // one of: TV_SILENT, TV_VERBOSE
#define JSON_VERBOSITY              JV_MESSAGES         // one of: JV_SILENT, JV_FOOTER, JV_CONFIGS, JV_MESSAGES, JV_LINENUM, JV_VERBOSE
#define QUEUE_REPORT_VERBOSITY      QR_OFF           // one of: QR_OFF, QR_SINGLE, QR_TRIPLE

#define STATUS_REPORT_VERBOSITY     SR_FILTERED         // one of: SR_OFF, SR_FILTERED, SR_VERBOSE
#define STATUS_REPORT_MIN_MS        100                 // milliseconds - enforces a viable minimum
#define STATUS_REPORT_INTERVAL_MS   250                 // milliseconds - set $SV=0 to disable
#define STATUS_REPORT_DEFAULTS      "mpox", "mpoy", "mpoz", \
                                    "posx", "posy", "posz", \
                                    "ofsx", "ofsy", "ofsz", \
																		"homx", "homy", "homz", \
                                    "unit", "stat", "coor", "momo", "dist", \
                                    "home", "mots", "plan", "line", "path", \
                                    "frmo", "prbe", "safe", "estp", "spc", \
                                    "hold", "macs", "cycs", "sps", "vel" , "sso", "mfo"


//#define STATUS_REPORT_DEFAULTS "line","posx","posy","posz","posa","feed","vel","unit","coor","dist","admo","frmo","momo","stat"
//#define STATUS_REPORT_DEFAULTS "line","mpox","mpoy","mpoz","posx","posy","posz","feed","vel","momo","stat","ofsx","ofsy","ofsz" ,"dist","unit", "homz","homy","homx", "_ts1","_cs1","_es1","_xs1","_fe1", "admo","frmo"

// Alternate SRs that report in drawable units
//#define STATUS_REPORT_DEFAULTS "line","vel","mpox","mpoy","mpoz","mpoa","coor","ofsa","ofsx","ofsy","ofsz","unit","stat","homz","homy","homx","momo"
//#define STATUS_REPORT_DEFAULTS "_ts1","_cs1","_es1","_xs1","_fe1","line","posx","posy","posz","vel","stat"

// Gcode startup defaults
#define GCODE_DEFAULT_UNITS MILLIMETERS     // MILLIMETERS or INCHES
#define GCODE_DEFAULT_PLANE CANON_PLANE_XY  // CANON_PLANE_XY, CANON_PLANE_XZ, or CANON_PLANE_YZ
#define GCODE_DEFAULT_COORD_SYSTEM G54      // G54, G55, G56, G57, G58 or G59
#define GCODE_DEFAULT_PATH_CONTROL PATH_CONTINUOUS
#define GCODE_DEFAULT_DISTANCE_MODE ABSOLUTE_DISTANCE_MODE

// *** motor settings ************************************************************************************
#define MOTOR_POWER_MODE            MOTOR_POWERED_ONLY_WHEN_MOVING
#define MOTOR_POWER_TIMEOUT         2.00                    // motor power timeout in seconds
#define STEP_ANGLE					1.8
#define TRAVEL_PER_REV_XY			40
#define TRAVEL_PER_REV_Z			1.25

#define M1_MOTOR_MAP                AXIS_X_EXTERNAL         // 1ma
#define M1_STEP_ANGLE               STEP_ANGLE              // 1sa
#define M1_TRAVEL_PER_REV           TRAVEL_PER_REV_XY       // 1tr
#define M1_MICROSTEPS               8                       // 1mi  1,2,4,8,16,32
#define M1_POLARITY                 1                       // 1po  0=normal, 1=reversed
#define M1_POWER_MODE               MOTOR_POWER_MODE        // 1pm  See enum cmMotorPowerMode in stepper.h
#define M1_POWER_LEVEL              1
#define M1_ENABLE_POLARITY          IO_ACTIVE_HIGH           // {1ep:  IO_ACTIVE_LOW or IO_ACTIVE_HIGH

#define M2_MOTOR_MAP                AXIS_Y_EXTERNAL
#define M2_STEP_ANGLE               STEP_ANGLE
#define M2_TRAVEL_PER_REV           TRAVEL_PER_REV_XY
#define M2_MICROSTEPS               8
#define M2_POLARITY                 1
#define M2_POWER_MODE               MOTOR_POWER_MODE        
#define M2_POWER_LEVEL              1
#define M2_ENABLE_POLARITY          IO_ACTIVE_HIGH
	
#define M3_MOTOR_MAP                AXIS_Y_EXTERNAL
#define M3_STEP_ANGLE               STEP_ANGLE
#define M3_TRAVEL_PER_REV           TRAVEL_PER_REV_XY
#define M3_MICROSTEPS               8
#define M3_POLARITY                 1
#define M3_POWER_MODE               MOTOR_POWER_MODE        
#define M3_POWER_LEVEL              1
#define M3_ENABLE_POLARITY          IO_ACTIVE_HIGH

#define M4_MOTOR_MAP                AXIS_Z_EXTERNAL
#define M4_STEP_ANGLE               STEP_ANGLE
#define M4_TRAVEL_PER_REV           TRAVEL_PER_REV_Z
#define M4_MICROSTEPS               8
#define M4_POLARITY                 0
#define M4_POWER_MODE               MOTOR_POWER_MODE        
#define M4_POWER_LEVEL              1
#define M4_ENABLE_POLARITY          IO_ACTIVE_HIGH

// *** axis settings **********************************************************************************

#define TRAVEL_RATIO				    (TRAVEL_PER_REV_Z/TRAVEL_PER_REV_XY)
#define VELOCITY_HOMING_RATIO		0.8
#define VELOCITY_LATCH_RATIO		0.2
#define JERK_MAX_XY             7000
#define JERK_MAX_Z              50
#define JERK_HIGH_SPEED_XY      JERK_MAX_XY * 2
#define JERK_HIGH_SPEED_Z       JERK_MAX_Z * 2
#define VELOCITY_XY					    5000
#define VELOCITY_Z					    800
#define LATCH_BACKOFF				    4 
#define ZERO_BACKOFF				    4

#define X_AXIS_MODE                 AXIS_STANDARD								// xam  see canonical_machine.h cmAxisMode for valid values
#define X_VELOCITY_MAX              VELOCITY_XY									// xvm  G0 max velocity in mm/min
#define X_FEEDRATE_MAX              X_VELOCITY_MAX								// xfr  G1 max feed rate in mm/min
#define X_TRAVEL_MIN                0											// xtn  minimum travel for soft limits
#define X_TRAVEL_MAX                280											// xtm  travel between switches or crashes
#define X_JERK_MAX                  JERK_MAX_XY									// xjm  jerk * 1,000,000
#define X_JERK_HIGH_SPEED           JERK_HIGH_SPEED_XY									// xjh  Jerk used during homing operations
#define X_HOMING_INPUT              1											// xhi  input used for homing or 0 to disable
#define X_HOMING_DIRECTION          0											// xhd  0=search moves negative, 1= search moves positive
#define X_SEARCH_VELOCITY           (X_VELOCITY_MAX * VELOCITY_HOMING_RATIO)    // xsv  minus means move to minimum switch
#define X_LATCH_VELOCITY            (X_VELOCITY_MAX * VELOCITY_LATCH_RATIO)     // xlv  mm/min Homing speed during latch phase (drive off switch)
#define X_LATCH_BACKOFF             LATCH_BACKOFF								// xlb  mm Maximum distance to back off switch during latch phase (drive off switch)
#define X_ZERO_BACKOFF              ZERO_BACKOFF								// xzb  mm Offset from switch for zero in absolute coordinates

#define Y_AXIS_MODE                 AXIS_STANDARD
#define Y_VELOCITY_MAX              VELOCITY_XY
#define Y_FEEDRATE_MAX              Y_VELOCITY_MAX
#define Y_TRAVEL_MIN                0
#define Y_TRAVEL_MAX                280
#define Y_JERK_MAX                  JERK_MAX_XY
#define Y_JERK_HIGH_SPEED           JERK_HIGH_SPEED_XY
#define Y_HOMING_INPUT              4			//ymax
#define Y_HOMING_DIRECTION          1
#define Y_SEARCH_VELOCITY           (Y_VELOCITY_MAX * VELOCITY_HOMING_RATIO)
#define Y_LATCH_VELOCITY            (Y_VELOCITY_MAX * VELOCITY_LATCH_RATIO)
#define Y_LATCH_BACKOFF             LATCH_BACKOFF
#define Y_ZERO_BACKOFF              ZERO_BACKOFF

#define Z_AXIS_MODE                 AXIS_STANDARD
#define Z_VELOCITY_MAX              VELOCITY_Z
#define Z_FEEDRATE_MAX              Z_VELOCITY_MAX
#define Z_TRAVEL_MAX                0
#define Z_TRAVEL_MIN                -90
#define Z_JERK_MAX                  JERK_MAX_Z
#define Z_JERK_HIGH_SPEED           JERK_HIGH_SPEED_Z
#define Z_HOMING_INPUT              6			//zmax
#define Z_HOMING_DIRECTION          1
#define Z_SEARCH_VELOCITY           (Z_VELOCITY_MAX * VELOCITY_HOMING_RATIO)
#define Z_LATCH_VELOCITY            (Z_VELOCITY_MAX * VELOCITY_LATCH_RATIO)
#define Z_LATCH_BACKOFF             LATCH_BACKOFF
#define Z_ZERO_BACKOFF              ZERO_BACKOFF

//*** Input / output settings ***
/*
    IO_POLARITY_DISABLED
    IO_ACTIVE_LOW    aka NORMALLY_OPEN
    IO_ACTIVE_HIGH   aka NORMALLY_CLOSED

    INPUT_ACTION_NONE
    INPUT_ACTION_STOP
    INPUT_ACTION_FAST_STOP
    INPUT_ACTION_HALT
    INPUT_ACTION_RESET

    INPUT_FUNCTION_NONE
    INPUT_FUNCTION_LIMIT
    INPUT_FUNCTION_INTERLOCK
    INPUT_FUNCTION_SHUTDOWN
    INPUT_FUNCTION_PANIC
*/

#define PROBING_INPUT               5

// Xmin on v9 board                 // X homing - see X axis setup
#define DI1_ENABLED                 IO_ENABLED
#define DI1_POLARITY                IO_ACTIVE_HIGH      // Normally Closed
#define DI1_ACTION                  INPUT_ACTION_LIMIT

// Xmax                             // External ESTOP
#define DI2_ENABLED                 IO_ENABLED
#define DI2_POLARITY                IO_ACTIVE_HIGH
#define DI2_ACTION                  INPUT_ACTION_NONE   // SHUTDOWN handled by E-Stop handler

// Ymin                             // Y homing - see Y axis setup
#define DI3_ENABLED                 IO_ENABLED
#define DI3_POLARITY                IO_ACTIVE_HIGH
#define DI3_ACTION                  INPUT_ACTION_NONE

// Ymax                             // Safety interlock
#define DI4_ENABLED                 IO_ENABLED
#define DI4_POLARITY                IO_ACTIVE_HIGH
#define DI4_ACTION                  INPUT_ACTION_LIMIT   // (hold is performed by Interlock function)

// Zmin                             // Z probe
#define DI5_ENABLED                 IO_ENABLED
#define DI5_POLARITY                IO_ACTIVE_HIGH       
#define DI5_ACTION                  INPUT_ACTION_NONE

// Zmax                             // Z homing - see Z axis for setup
#define DI6_ENABLED                 IO_ENABLED
#define DI6_POLARITY                IO_ACTIVE_HIGH
#define DI6_ACTION                  INPUT_ACTION_LIMIT

// Amin                             // Version pin - board type
#define DI7_ENABLED                 IO_DISABLED
#define DI7_POLARITY                IO_ACTIVE_LOW
#define DI7_ACTION                  INPUT_ACTION_NONE

// Amax                             // Version pin - board type
#define DI8_ENABLED                 IO_DISABLED
#define DI8_POLARITY                IO_ACTIVE_LOW
#define DI8_ACTION                  INPUT_ACTION_NONE

// Safety line w/HW timer           // Version pin - board type
#define DI9_ENABLED                 IO_DISABLED
#define DI9_POLARITY                IO_ACTIVE_LOW
#define DI9_ACTION                  INPUT_ACTION_NONE
#define DI9_EXTERNAL_NUMBER         10

// Silk marked as "CS2"             // Version pin - machine type
#define DI10_ENABLED                 IO_ENABLED
#define DI10_POLARITY                IO_ACTIVE_LOW
#define DI10_ACTION                  INPUT_ACTION_NONE
#define DI10_EXTERNAL_NUMBER         9

// *** PWM SPINDLE CONTROL ***
//Header Bed FET
#ifndef DO11_ENABLED
#define DO11_ENABLED                IO_ENABLED
#endif
#ifndef DO11_POLARITY
#define DO11_POLARITY               IO_ACTIVE_LOW
#endif
#ifndef DO11_EXTERNAL_NUMBER
#define DO11_EXTERNAL_NUMBER         11
#endif



