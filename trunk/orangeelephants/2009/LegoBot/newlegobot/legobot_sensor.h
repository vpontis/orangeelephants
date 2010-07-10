#ifndef legobot_motor
#define legobot_motor

#include "boolean.h"

/** \brief Amount of times to read sensors.
*/
#define READ_TIMES 10

/** \brief Minimum reading to denote a black line for Top Hat IR sensors.
*/
#define BLACK_READING_MIN 400

/** \brief Right IR port.
*/
#define R_IRSENSOR 8 //Analog Port 8

/** \brief Center IR port.
*/
#define C_IRSENSOR 9 // Redefine these

/** \brief Left IR port.
*/
#define L_IRSENSOR 10 //Analog Port 10

int read_analog(int port);

int get_right_ir_sensor(void);

int get_center_ir_sensor(void);

int get_left_ir_sensor(void);

boolean is_left_black(void);

boolean is_center_black(void);

boolean is_right_black(void);

boolean both_on_black_line(void);

boolean two_on_black_line(void);

void black_line_finder(void);

#endif
