/*
create_joystick_constants.h
Eric Liu
Header for create_joystick.c
*/

#ifndef create_joystick_h
#define create_joystick_h

#define LEFT_BTN  (dPadPortMap[1])

#define RIGHT_BTN  (dPadPortMap[0])

#define UP_BTN  (dPadPortMap[2])

#define DOWN_BTN  (dPadPortMap[3])

#define ARM_UP_BTN  (dPadPortMap[4])

#define ARM_DOWN_BTN  (dPadPortMap[5])

#define SWEEP_UP_BTN  (dPadPortMap[6])

#define SWEEP_DOWN_BTN  (dPadPortMap[7])

#define LB  (digital(LEFT_BTN))

#define RB  (digital(RIGHT_BTN))

#define UB  (digital(UP_BTN))

#define DB  (digital(DOWN_BTN))

#define AUB  (digital(ARM_UP_BTN))

#define ADB  (digital(ARM_DOWN_BTN))

#define SUB  (digital(SWEEP_UP_BTN))

#define SDB  (digital(SWEEP_DOWN_BTN))


#define NUM_SENS 8

#define CREATE_SPEED 250

#define ARM_SPEED 750


int dPadPortMap[NUM_SENS] = {8,9,10,11,12,13,14,15};

#endif
