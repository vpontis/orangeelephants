/**
legobot_motor.c
created 1/26/09
Mark Allen Vismonte
Creating a legobot motor file that sorts all the motor functions for the legobot
1/27/09 - Created all the function today
Redefined all the constants
12:00 pm
Made the deployBlockers() and withdrawBlockers() to be used
Commented the functions
1:05 pm
Starting to implement the turn methods
way to make it do turns in place, use moveMotorsAt(+velocity,-velocity), turn wheel
3:00 pm
Created a stopMotors() function
4:00 pm
Redefined ALL blocker constants because the motors were remounted and shifted.
1/29/09
Redefined and added BW Motor constants in order to add more precision for turning
1/30/09

*/

#include "legobot_motor.h"//includes its own header

#define BACK_WHEEL 4 //Servo port - The servo used for controlling the direction of the drive
#define R_WHEEL 1 // Motor port - The motor used for controlling the forward/backward drive of the robot
#define L_WHEEL 3 // Motor port - The motor used for controlling the forward/backward drive of the robot0
#define R_BLOCKER 1 // Servo port - The servo used for controlling the deployable right side blocker
#define L_BLOCKER 3 /*Servo port - The servo used for controlling the deployable left side blocker
The wheels are used for driving
The blocker motors are used for blocking and keeping the other robots from moving further
*/

#define BW_MID 850 //Back wheel mid position
#define BW_MAX_LEFT 50 //Back wheel max left position
#define BW_MID_LEFT 350 //Back wheel mid left position
#define BW_MIN_LEFT 600 //Back wheel min left position
#define BW_MAX_RIGHT 1650 //Back wheel max right position
#define BW_MID_RIGHT 1350 //Back wheel mid right position
#define BW_MIN_RIGHT 1100 //Back wheel min right position
/*tested and found that it is in the middle at position 978
//redefined the middle at 1000, it works alot better and tested it to go straight
//tested and found that it points to the right at position 0
//tested and found that it points to the left at position 1869
//Find position that will help it turn or find how to make it turns
//One way to make it turn is to turn the wheel to that certain position and overdrive one of the wheels
1/29/08
set_servo_position(4,0);
printf("Starting, Press B to exit\n");
while (!b_button())
	{
	if (left_button())
		{
		set_servo_position(4, get_servo_position(4) - 50);
		printf("Position @ %d\n", get_servo_position(4));
		}
	if (right_button())
		{
		set_servo_position(4, get_servo_position(4) + 50);
		printf("Position @ %d\n", get_servo_position(4));
		}	
	}
Used this method to use the console in order to move the BW Servo
This way i redefined constants because the motor was remounted again.
I also added points inbetween because the middle, max left, and max right, were all the extremes
These constants should us to control the robot's turning with more precision
*/



/*redefining constants
We shifted the motors so we have to redefine the servo constants
*/
#define R_BLOCKER_UP 1897 //redo
#define R_BLOCKER_DOWN 597 //start here
#define L_BLOCKER_UP 5 // tested and confirmed
#define L_BLOCKER_DOWN 1255 //to be confirmed
/*#define R_BLOCKER_UP 2047 //tested and confirmed at the highest
#define R_BLOCKER_DOWN 997 //tested, waiting for confirmation
#define L_BLOCKER_UP 0 //tested and confirmed to be the at the highest
#define L_BLOCKER_DOWN 855 /*tested, waiting for confirmation
We used a for loop and starting both blockers at the very top and lower them by 50 every 3000L ms
We printed out the values for all of the position and then observed when the blockers were now touching the ground
We recorded those values and assigned them to R_BLOCKER_DOWN and L_BLOCKER_DOWN
*/ 

#define TURNING_SPEED 200 //speed used when turn the bot

/**
Method used to turn the robot
Will use degrees as the method of turning
turns Right if turnRight is true, left if turnRight is false
*/
void turn(int degrees, boolean turnRight)
{
printf("Turning at %d degrees ", degrees);
if (turnRight)
	{
	//Needs to be fixed so that it can turn at a certain amount of degrees.
	//Right now it just turns the wheel and spins in circles
	//Same with turning left
	turnWheelMaxRight();
	moveMotorsAt(-TURNING_SPEED, TURNING_SPEED);
	printf("in the Right direction\n");
	//might use msleep(time) to wait for it to turn the amount of degrees
	}
else
	{
	turnWheelMaxLeft();
	moveMotorsAt(TURNING_SPEED, -TURNING_SPEED);
	printf("in the Left direction\n");
	//might use msleep(time) to wait for it to turn the amount of degrees
	}
turnWheelMiddle();//turns the back wheel back to the middle after its finished turning
printf("Finished turning\n");
}

/**
Lowers the blockers down to their set down position
*/
void deployBlockers()
{
setBlockerPosition(true, L_BLOCKER_DOWN);
setBlockerPosition(false, R_BLOCKER_DOWN);
}

/**
Raises the blockers up to their set up position
*/
void withdrawBlockers()
{
setBlockerPosition(true, L_BLOCKER_UP);
setBlockerPosition(false, R_BLOCKER_UP);
}

/**
Freezes the Blocker motors from falling
@Depreciated - now using servos for motors that drop down
Instead of using regular motors to deploy the blockers, we are now using two servos because they are more reliable
*/
void freezeBlockers()
{
//mrp(R_BLOCKER,0, 0L);
//mrp(L_BLOCKER,0,0L);
//freeze(R_BLOCKER);
//freeze(L_BLOCKER);
move_to_position(R_BLOCKER, 0 ,0L);
mtp(L_BLOCKER,0, 0L);
}


/**
Initialized the servos and raises the blockers to the top
*/
void initMotors()
{
printf("Initializing Motors\n");
enable_servos();
withdrawBlockers();
turnWheelMiddle();
}

/**
Disables all the motors and deploys the blockers
*/
void disableMotors()
{
printf("Disabling Motors\n");
ao();
turnWheelMiddle();
deployBlockers();
msleep(2000L);
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
A function used to call the moveMotorsAt method but with the same velocity
int velocity - the velocity at which both the motors move at
*/
void moveTogetherAt(int velocity)
{
moveMotorsAt(velocity,velocity);
}

/**
Stops the motors from moving
*/
void stopMotors()
{
moveTogetherAt(0);//moves them together at a value of 0, hence stopping it
}

/**
Turns the servo to a certain position
int servoPosition - the position on which to turn the servo wheel to.  The bounds
are between the BW_MAX_LEFT and the BW_MAX_RIGHT
*/
void turnWheel(int servoPosition)
{
//First checks to see if in bounds
if (servoPosition <= BW_MAX_RIGHT && servoPosition >= BW_MAX_LEFT)
	{
	set_servo_position(BACK_WHEEL, servoPosition);
	switch(servoPosition)//prints a statement depending on the position
		{
		case BW_MAX_RIGHT:
			printf("Back Wheel set to max left\n");
			break;
		case BW_MID:
			printf("Back Wheel set to the middle\n");
			break;
		case BW_MAX_LEFT:
			printf("Back Wheel set to max right\n");
			break;
		default:	
			printf("Back Wheel set to position: (%d)\n",servoPosition);
		}
	}
else//Prints out a statement telling it that its not in bounds
	printf("Servo position out of bounds\n");
}

/**
Turns the back wheel servo to the max left
*/
void turnWheelMaxLeft()
{
turnWheel(BW_MAX_LEFT);
}

/**
Turns the back wheel servo to the max right
*/
void turnWheelMaxRight()
{
turnWheel(BW_MAX_RIGHT);
}

/**
Turns the back wheel servo the middle
*/
void turnWheelMiddle()
{
turnWheel(BW_MID);
}

/**
A method used to set the position of the blockers
leftBlocker is true if the left side blocker is the one to be moved
it will be false if it is the right side blocker if it is the one to be moved
position is the position between 0 and 2047 that the servo will move to
*/
void setBlockerPosition(boolean leftBlocker, int position)
{
if (position >= 0 && position <= 2047)
	{
	if (leftBlocker)
		{
		set_servo_position(L_BLOCKER, position);
		printf("Left Blocker set to position: %d\n", position);
		}
	else
		{
		set_servo_position(R_BLOCKER, position);
		printf("Right Blocker set to position: %d\n", position);
		}
	}
else
	printf("Servo Position out of bounds\n");
}
