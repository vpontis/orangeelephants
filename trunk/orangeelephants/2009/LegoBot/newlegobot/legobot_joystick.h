/*
legobot_joystick.h
Created 2/14/09
Mark Allen Vismonte
A header file for the legobot_joystick.c file
*/

#ifndef legobot_joystick_h
#define legobot_joystick_h

/** \brief Defines up on our joystick.
*/
#define JOYPAD_UP  (digital(0))

/** \brief Defines right on our joystick.
*/
#define JOYPAD_RIGHT  (digital(1))

/** \brief Defines down on our joystick.
*/
#define JOYPAD_DOWN  (digital(2))

/** \brief Defines left on our joystick.
*/
#define JOYPAD_LEFT  (digital(3))

/** \brief Speed used for the joystick, in ticks per second.
*/
#define JOYSTICK_SPEED 1000

#define TTT 1

#define TTF 2

#define TFT 3

#define TFF 4

#define FTT 5

#define FTF 6

#define FFT 7

#define FFF 8

//Go to slope definitions
#define RAMP_DEPART_SPEED 1000
#define BLACK_LINE_SEARCH_OUTER_VELOCITY 650
#define BLACK_LINE_FOLLOWING_CORRECTION_VELOCITY 200
#define BLACK_LINE_FOLLOWING_STRAIGHT_VELOCITY 650


//declaration for all the tests methods
int do_joystick(void);
int do_square_dance(void);
int do_distance_test(void);
int do_turn_test(void);
int do_servo_position_test(void);
int drop_arms(void);
int do_arc_test(void);
int go_to_slope(void);
int do_black_line_follow_test(void);
int test_freeze(void);
int black_value_test(void);
int black_line_searching_and_following(void);
int current_state(boolean currentValues[]);
int competition_runner(int(*func)(), int lightPort);

//Declaration for the main method
int run_joystick(void);


#endif
