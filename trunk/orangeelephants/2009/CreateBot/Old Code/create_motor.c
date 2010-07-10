//create_motor.c
//motor functions
//Created on 01-24-2009

//JJ added Create functions 1/24/09

//#include "create_constants.h"
#include "create_constants.h"
#include "create_motor.h"
#define go(speed) create_drive_straight(speed)

//CREATE FUNCTIONS

/**
* Used with the Create
* Drives Forward with a certain speed
* Speed - the speed in ints
*/
void forward(int speed) {
    go(speed);
}

void backward(int speed) 
{
	create_drive_direct(speed, speed);
}

/**
* Used with the Create to stop
*/
void stop() {
    create_stop();
}

//turns the specific amount of degrees using create sensors
void turn(int degrees)
{
	//printf("Angle in turn method is:%n\n", degrees);
	if(degrees < 0.0)
		turn_CCW(-degrees);
	else
		turn_CW(-degrees);
}

/**
* Turns the create a certain amount of degrees
* Degrees - the amount of degrees for the create to turn
*/
void turn_CW(int degrees) {	
    int lastDegree = 0;
	if(!SENSOR_PROCESS) {
		gc_total_angle = 0;
        create_sensor_update();		
		create_spin_CW(TURN_SPEED);
        while(gc_total_angle > degrees) {            
            create_sensor_update();
			if(lastDegree != gc_total_angle)
				printf("The angle is:%d\n", gc_total_angle);
			lastDegree = gc_total_angle;
			}
		stop();
        }
	else {
		printf("Worked Angle going is:%d\n", degrees);
		gc_total_angle = 0;
		create_spin_CW(TURN_SPEED);
		while(gc_total_angle > degrees) 
		{					
            if(lastDegree != gc_total_angle)
				printf("The angle is:%d\n", gc_total_angle);
			lastDegree = gc_total_angle;
		}
		stop();
		printf("The angle is:%d\n", gc_total_angle);
	}
}

/**
* Turns the create a certain amount of degrees
* Degrees - the amount of degrees for the create to turn
*/
void turn_CCW(int degrees) {
    int lastDegree = 0;
	printf("Entering turn_CCW method\n");
	if(!SENSOR_PROCESS) 
	{
		printf("Entering conditional\n");
		gc_total_angle = 0;
        create_sensor_update();		
		printf("gc_total_angle is:%d\n", gc_total_angle);
		create_spin_CCW(TURN_SPEED);
		printf("gc_total_angle is:%d\n", gc_total_angle);
        while(gc_total_angle < degrees) 
		{
            create_sensor_update();
			if(lastDegree != gc_total_angle)
				printf("The angle is:%d\n", gc_total_angle);
			lastDegree = gc_total_angle;
		}
		stop();
    }
	else {
		printf("Worked\nAngle going to is:%d\n", degrees);
		gc_total_angle = 0;
		create_spin_CCW(TURN_SPEED);
		while(gc_total_angle < degrees) 
		{					
            if(lastDegree != gc_total_angle)
				printf("The angle is:%d\n", gc_total_angle);
			lastDegree = gc_total_angle;
		}
		stop();
		printf("The angle is:%d\n", gc_total_angle);
	}
	printf("Exiting turn_CCW method\n");
}

/**
* Used for the create to turn an exact 90 degrees to the right
* Calls the turn method turn(RIGHT_ANGLE);
*/
void turn_Right() 
{
    turn(RIGHT_ANGLE);
}

void turn_Left() 
{	printf("Angle is:%d\n", -RIGHT_ANGLE);
	turn(-RIGHT_ANGLE);
}

void accelerate(int motorVelocity, int finalVelocity, float time)
{
    int deltaVelocity = finalVelocity - motorVelocity; //change in velocity
    int avgAccel = (int)((float)(i_abs(deltaVelocity)) / time); //change in speed per second
    
    if (deltaVelocity > 0)
      {
        while(motorVelocity <= finalVelocity)
          {
            motorVelocity += (avgAccel/10);
            if(motorVelocity > finalVelocity)
              motorVelocity = finalVelocity + 1; //this accounts for the <= in while loop
            //set speed for bot to move at.
            create_drive_straight(motorVelocity);
            sleep(0.1);
        }
    }
    
    else if (deltaVelocity < 0)
      {
        while(motorVelocity >= finalVelocity)
          {
            motorVelocity -= (avgAccel/10);
            if(motorVelocity < finalVelocity)
              motorVelocity = finalVelocity - 1;
            //set speed for bot to move at.
            create_drive_straight(motorVelocity);
            sleep(0.1);			 
        }
    }
}

void accel_Turning(int initSpeed, int finalSpeed, float time)
{
	
}

//distance in cm, init speed in mm/s, final speed in mm/s
void move_Dist(float distance, int initSpeed, int finalSpeed)
{
    int avgSpeedMM = (finalSpeed + initSpeed)/2; //mm/s
    int avgSpeedCM = avgSpeedMM / 10; //cm/s
    float time = distance / (float)avgSpeedCM; //cm / cm/s
    
    if (distance < 0.)
      {
        finalSpeed *= -1;
        initSpeed *= -1;
        time *= -1.;
    }
    
    accelerate(initSpeed, finalSpeed, time / 2.);
    accelerate(finalSpeed, initSpeed, time / 2.);
}

int i_abs(int i)
{
	if(i < 0)
		return -i;
	else
		return i;
}

float f_abs(float n)
{
    if(n < 0.0)
      return -n;
    else
      return n;
}

float circle_circumference(float r)
{ 
    return 2.0*PI*r;
}

// Turns the iCreate to d degrees
void turn_d(float d)
{ 
    turnSpeed(SPEED, d);
}

// Turns the iCreate to d degrees at speed s
void turnSpeed(int s, float d)
{
    float dist = TURN_SCALAR * (f_abs(d) / 360.0 * circle_circumference(WHEEL));
    float t = 10.0 * dist / (float)s;
    
    if (d > 0.0)
      {
        create_drive_direct(-s, s);
    }
    
    else
      {
        create_drive_direct(s, -s); 
    }
    
    sleep(t);
    create_stop();
}
