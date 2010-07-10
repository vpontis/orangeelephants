#ifndef CREATE_MOTOR_H
#define CREATE_MOTOR_H
//create_motor.h
//created on 1-26-2009

#include "create_constants.h"
#define go(speed) create_drive_straight(speed)

void forward(int);
void backward(int); 
void stop(void);
void turn(int);
void turn_CW(int);
void turn_CCW(int);
void turn_Right(void);
void turn_Left(void);
void accelerate(int,int,float);
void accel_Speed(int,int,float);
void move_Dist(float,int,int);
int i_abs(int);
float f_abs(float);
float circle_circumference(float);
void turnSpeed(int,float);
void turn_d(float);
#endif
