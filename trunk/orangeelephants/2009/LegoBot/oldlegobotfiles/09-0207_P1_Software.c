/*
* 09-0207_P1_Software.c
* Created by Mark Vismonte of Torrey Pines Botball 2009 on 2/1/09.
* Copyright 2009 Torrey Pines Botball. All rights reserved.
*
* This program uses the on screen buttons on firmware version 0.8
* to test the drive of the motors and the turning capability of 
* back wheel mounted on a servo.  The servo allows the robot to
* turn with out overdriving one of the motors.  This program was
* used to get the positions.  For example, we adjusted the back
* servo until it was perfectly center and recorded the value on
* the screen.  
*/

//Motor Ports
#define R_WHEEL 1
#define L_WHEEL 3 

//Servo Ports
#define BACK_WHEEL 4 

//Back wheel increment
#define INCREMENT 50

//Function definitions
void initMotors(void);
void disableMotors(void);
void moveMotorsAt(int leftVelocity, int rightVelocity);
void turnWheel(int servoPosition);
int getWheelPosition();

/**
* The main function loops until the b button is pressed
* The robot acts depending on if right, left, or up
* are pressed.  The program can be exited by pressing B
*/
int main()
{
int success = 0;
printf("Running Drive test\n");
initMotors();
turnWheel(success);
//Runs until the b button is pressed
while (!b_button())
	{
	//Turns right by adding 50 to the current position
	if (right_button())
		{
		turnWheel(getWheelPosition() + INCREMENT);
		printf("Right Button pressed, Current Servo Position: %d\n",
			getWheelPosition());
		}
	//Turns left by subtracting 50 from the current position
	if (left_button())
		{
		turnWheel(getWheelPosition() - INCREMENT);
		printf("Left Button pressed, Current Servo Position: %d\n",
			getWheelPosition());
		}
	/* Drives for 5 seconds to determine arc length and radius
	*  of the desired turn and also to test how straight the
	*  robot is driving to define the middle position	
	*/
	if (up_button())
		{
		printf("Up Button pressed, Driving forward for %d seconds\n", 5);
		moveMotorsAt(150, 150);
		msleep(5000L);
		moveMotorsAt(0,0);
		printf("Done Driving\n");
		}
	}
printf("B Button pressed, Program terminated\n");
disableMotors();
return success;
}

/**
Initializes the servos
*/
void initMotors()
{
printf("Initializing Motors\n");
enable_servos();
}

/**
Disables all the motors and servos
*/
void disableMotors()
{
printf("Disabling Motors\n");
ao();
disable_servos();
}

/**
A function used to mav both motors at the same time
int leftVelocity - the velocity of the left motor
int rightVelocity - the velocity of the right motor
*/
void moveMotorsAt(int leftVelocity, int rightVelocity)
{
printf("Driving Wheels: Left @ %d && Right %d\n",leftVelocity,rightVelocity);
if (leftVelocity >= -1000 && leftVelocity <= 1000 && 
	rightVelocity >= -1000 && rightVelocity <= 1000)
	{
	mav(R_WHEEL, rightVelocity);
	mav(L_WHEEL, leftVelocity);
	}
else
	printf("Velocity out of bounds");
}

/**
Turns the servo to a certain position
int servoPosition - the position on which to turn the servo wheel to.  The bounds
are between 0 and 2047
*/
void turnWheel(int servoPosition)
{
//First checks to see if in bounds
if (servoPosition <= 2047 && servoPosition >= 0)
	{
	//Sets the Back wheel position and prints out the position
	set_servo_position(BACK_WHEEL, servoPosition);
	printf("Back Wheel set to position: (%d)\n",servoPosition);
	}
//Prints out a statement telling it that its not in bounds
else
	printf("Servo position out of bounds\n");
}

/**
Returns the current position of the back wheel
*/
int getWheelPosition()
{
return get_servo_position(BACK_WHEEL);
}
