/** \file controller.h
	\brief Contains code for using the controller for the create.			
			
	This is not a class.
*/
#ifndef controller_h
#define controller_h

/** \def LEFTDETACH 
	\brief Defines the port of the left claw.	
	
	The port to which the left claw servo should be attached to.
*/
#define LEFTDETACH 3

/** \def RIGHTDETACH 
	\brief Defines the port of the right claw.
*/
#define RIGHTDETACH 1

/** \def TOUCH_LEVER
	\brief Defines the touch level
*/
#define TOUCH_LEVER (digital(4))

/** \def JOYPAD_UP 
	\brief Defines joypad up
*/
#define JOYPAD_UP  (digital(0))

/** \def JOYPAD_RIGHT
	\brief Defines joypad right
*/
#define JOYPAD_RIGHT  (digital(3))

/** \def JOYPAD_DOWN 
	\brief Defines joypad down
*/
#define JOYPAD_DOWN  (digital(2))

/** \def JOYPAD_LEFT
	\brief Defines joypad left
*/
#define JOYPAD_LEFT  (digital(1))

/** \def SPEED_C
	\brief The speed for the crate when running the controller.
*/
#define SPEED_C 500

	
/** \fn int run_Control(void)
	\brief This runs the loop to make the controller function.
 */
int run_Control(void);

/** \fn void turnOff(void)
	\brief Turns off the create motors.
	
	Calls \ref stop method from create_motor.c
*/
void turnOff(void);
#endif
