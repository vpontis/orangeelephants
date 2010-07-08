/**
        \file legobot_motor.c
        \date 4/12/2010
        \author Prithvi Undavalli
        \brief Mobility functions for LegoBot
        
        This file contains methods that the legobot uses for moving purposes.
*/

#include "boolean.h"
#include "legobot_motor.h"
#include "legobot_constants.h"
#include "math.c"

/** \brief Moves the Legobot for the distance in a straight line using an mrp
    command.
    \param distance to be travelled in cm.
    \param speed Speed to travel at in ticks per second.
*/
void moveToDistance(double distance, int speed)
{
	mrp(L_MOTOR, speed,cmToTicks(distance));
	mrp(R_MOTOR, speed,cmToTicks(distance));
	bmdMotors();
}

/** \brief Moves the Legobot for the distance in a arc defined
	 by varying motor velocities, using an mrp command.
    \param distance Distance to be travelled in cm.
    \param speedL in ticks per second to turn the left motor.
	\param speedR in ticks.
*/
void moveToDistanceTurn(double distance, int speedL, int speedR) 
{
	mrp(L_MOTOR,speedL,cmToTicks(distance));
	mrp(R_MOTOR,speedR,cmToTicks(distance));
	bmdMotors();
}

/** \brief Old arcing function for sweeping items off of Karel Island.
    \param leftArc True if left arc is being done, False if right arc
    \param outerRadius The outer radius of the virtual circle in cm
	\param speed The speed in ticks per second
	\param move_distance Distance value to determine how much to arc
	\todo switch to turnArc, recallibrate, and delete function
	 Moves the Legobot in an arc for Karel Island to
	 knock of items. The Legobot drives on the inside
	 of a virtual circle defined by outerRadius. 
*/
void turn_arc_sweep(boolean leftArc, float outerRadius, int speed, float move_distance)
{	
	if (outerRadius < 170)
	{
		printf("Outer Radius must be greater than %d\n", LEGOBOT_DIAMETER);
		return;
	}
	float ratio = (outerRadius - 170)/(outerRadius);
	printf("Arcing Ratio =%f\n",ratio);
	float smallerDistance = move_distance * ratio;
	int	smallerVelocity = (int)(speed * ratio);
	if (leftArc)
	{
		mrp(L_MOTOR, smallerVelocity, (long)(((smallerDistance / WHEEL_CIRCUMFERENCE ) * TICKS_PER_REV)));
		mrp(R_MOTOR, speed, (long)(((move_distance / WHEEL_CIRCUMFERENCE ) * TICKS_PER_REV)));
	}
	else
	{
		mrp(L_MOTOR, speed, (long)(((move_distance / WHEEL_CIRCUMFERENCE ) * TICKS_PER_REV)));
		mrp(R_MOTOR, smallerVelocity, (long)(((smallerDistance / WHEEL_CIRCUMFERENCE ) * TICKS_PER_REV)));
	}
	bmd(L_MOTOR);
	bmd(R_MOTOR);
}

/** \brief Turns the legobot a certain amount of degrees using 
	mrp commands for each wheel. Robot turns in place. 
	\param angle Angle at which the robot will turn, positive is CW,
	negative is CCW
*/
void turn(double angle)
{
	static double BotCircumference = 53.4; //BOT CIRCUMFERENCE
	double turnCM = d_abs((angle/360.0) * 53.4);
	int ticksToMove = (int) (( turnCM / WHEEL_CIRCUMFERENCE ) * TICKS_PER_REV);
	
	if(angle<0)
	{
		mrp(L_MOTOR, 500, -ticksToMove);
		mrp(R_MOTOR, 500, ticksToMove);
	}
	else
	{
		mrp(L_MOTOR, 500, ticksToMove);
		mrp(R_MOTOR, 500, -ticksToMove);
	}
	bmdMotors();
}


/** \brief Turns the legobot a certain amount around a single point 
	at a slow speed. 
	\param angle Angle at which the robot will turn, positive is CW,
	negative is CCW
*/
void turnSlow(double angle)
{
    const double BOT_WHEELBASE = 12.0; 
	const double BOT_CIRCUM = 3.14159 * BOT_WHEELBASE; //BOT TURN ARC CIRCUMFERENCE
	double turnCM = d_abs((angle/360.0) * BOT_CIRCUM);
	int ticksToMove = (int) (( turnCM / WHEEL_CIRCUMFERENCE ) * TICKS_PER_REV);
	
	if(angle<0)
	{
		mrp(L_MOTOR, SLOW_SPEED, -ticksToMove);
		mrp(R_MOTOR, SLOW_SPEED, ticksToMove);
	}
	else
	{
		mrp(L_MOTOR, SLOW_SPEED, ticksToMove);
		mrp(R_MOTOR, SLOW_SPEED, -ticksToMove);
	}
	bmdMotors();
}
/** \brief Stops the legobot using the mav command.
*/
void stopMovement()
{
	mav(L_MOTOR, 0);
	mav(R_MOTOR, 0);
}

/** \brief Moves the Legobot in a straight line using the
		   mav command
	\param velocity Speed which legobot moves, can be negative
		    between 0-1000
*/
void moveStraight(int velocity)
{
	mav(L_MOTOR, velocity);
	mav(R_MOTOR, velocity);
}

/** \brief Turns legobot in an arc using the mrp command
	\param leftArc True if going left, false if going right
	\param outerRadius Sets outer radius of the arc in centimeters
	\param outerSpeed Speed of outside wheel between 0-1000
	\param amountDegrees Tells the robot how much of the circle to
			   turn in degrees
*/
void turnArc(boolean leftArc, float outerRadius,float outerSpeed, float amountDegrees)
{
	float ratio = (outerRadius - LEGOBOT_DIAMETER)/(outerRadius);
	float outerCircumference = 2 * PI * outerRadius * (1/WHEEL_CIRCUMFERENCE);
	float innerCircumference = outerCircumference * ratio;
	float innerSpeed = outerSpeed * ratio; 
	
	if(leftArc)
	{
		mrp(L_MOTOR, innerSpeed, innerCircumference*TICKS_PER_REV*(amountDegrees/360.0));
		mrp(R_MOTOR, outerSpeed, outerCircumference*TICKS_PER_REV*(amountDegrees/360.0));
	}
	else
	{
		mrp(R_MOTOR, innerSpeed, innerCircumference*TICKS_PER_REV*(amountDegrees/360.0));
		mrp(L_MOTOR, outerSpeed, outerCircumference*TICKS_PER_REV*(amountDegrees/360.0));
	}
	bmdMotors();
}

/** \brief Moves servo to a position between 0 and 2048
	\param servo The port of servo
	\param pos The desired position
	\param speed The desired speed of servo from 1 to 1000?
	\todo Find the maximum speed
	
	Works by moving the servo in small intervals. Default
	set_servo_position() does not work for big movements. 
	Range of servo is 0 degrees to 270 degrees.
*/
void moveServoPosition(int servo, int pos, int speed)
{
	const float dSleep = .05;
	int jumpSize = abs(speed * abs(pos - get_servo_position(servo))) / 300;

	int curr = get_servo_position(servo);
	int change = pos > get_servo_position(servo) ? jumpSize : -jumpSize;
	
	//timeout
	int initPos = get_servo_position(servo);
	float initT = seconds();
	float timeOut=initT+dSleep*abs(initPos - pos)/((float)jumpSize)+.2; // .2 = leeway 
	
	for(curr = get_servo_position(servo); 
		((change < 0 &&  curr > pos) || (change > 0 && curr < pos)) && seconds()<timeOut;
			curr = curr + change) {
		set_servo_position(servo,curr);
		sleep(dSleep);
	}
	if(curr<pos)
		printf("Timeout - Servo:%d, CurrPos:%d, TargetPos:%d\n",servo,get_servo_position(servo),pos);
	sleep(.05);
}


/** \brief Converts centimeters to ticks, used for mrp or mtp commands
	\param cmDistance input cm distance that needs to be converted to ticks
*/
int cmToTicks(float cmDistance)
{
    return (int) (( cmDistance / WHEEL_CIRCUMFERENCE ) * TICKS_PER_REV);               
}

/** \brief Blocks program until wheel motors are done with their operation
	\pre Motors are not at 0 velocity.
	\post Motors are at 0 velocity.
*/
void bmdMotors()	{
	bmd(L_MOTOR);
	bmd(R_MOTOR);	
}

/** \brief Opens the duck grabbing claw
*/
void clawOpen()	{
	set_servo_position(CLAW_SERVO, 1100);
	//moveServoPosition(CLAW_SERVO, 1200,100);
}

/** \brief Close the duck frabbing claw
*/
void clawClose()	{
	set_servo_position(CLAW_SERVO, 1);	
	//moveServoPosition(CLAW_SERVO, 1, 100);
}

/**  \brief Lowers arm to lowest position to pull back ducks from the 
	  clean duck center.
*/
void lowerArm() {
	mtp(ARM_MOTOR, TILT_SPEED, ARM_DOWN + MOTOR_OFFSET);
}

/**  \brief Raises arm to highest position.
*/
void raiseArm() {
	mtp(ARM_MOTOR, TILT_SPEED, ARM_UP + MOTOR_OFFSET);
}

/**  \brief Sets arm to lowest position able to go over PVC
*/
void highNeutralArm() {
	mtp(ARM_MOTOR, TILT_SPEED, ARM_HIGH_NEUTRAL + MOTOR_OFFSET);
}

/**  \brief Lowes arm to grab the ducks.
*/
void duckGrabArm() {
	mtp(ARM_MOTOR, TILT_SPEED, ARM_DUCK_GRAB + MOTOR_OFFSET);
}

/**  \brief Sets arm to neutral position slowly
*/
void neutralArmSlow() {
	mtp(ARM_MOTOR, TILT_SPEED/2, ARM_NEUTRAL + MOTOR_OFFSET);
}

/**  \brief Sets arm to neutral position 
*/
void neutralArm() {
	mtp(ARM_MOTOR, TILT_SPEED, ARM_NEUTRAL + MOTOR_OFFSET);
}

/** \brief Drives the legobot into the wall until a color is found.

	Includes a timeout so that if the color is not found the Legobot
	will back up and correct itself. Used primarily for orange. 
		\param colorModel Orange is 0. Green is 2.
		\param speed Speed at which the legobot will be driving while looking.
		\param numBlobSightings How many blobs it needs to see to trigger. 
		\param delay Time to wait in each while loop. Usually .05. 
		\param distOut Amount of centimeters to go before cancelling looking for. 
		\param cmBackup Centimeters to backup if line is not found. 
*/
void lookForColor(int colorModel, int speed, int numBlobSightings,  float distOut, int cmBackup)	{

	track_update(); 
	moveStraight(speed);
	int blobCounter = 0;
	/*//Can be used for time out instead of distance out. 
	float startTime = seconds();
	float elapsedTime = 0;
	*/
	int rInitMotorPosit = get_motor_position_counter(R_MOTOR); //motors cannot be going backwards
	int lInitMotorPosit = get_motor_position_counter(L_MOTOR);
	int lElapseMotorPosit = 0;
	int rElapseMotorPosit = 0;
	int elapsedDist = 0;
	while(blobCounter < numBlobSightings) {
		if(track_count(colorModel) >= 1) {
			blobCounter++;
		}
		if(elapsedDist > cmToTicks(distOut)){
			printf("Green line not detected, function timed out. /n");
			moveToDistance(-cmBackup,speed);
			stopMovement();
			break;
		}
		track_update();
		rElapseMotorPosit = get_motor_position_counter(R_MOTOR) - rInitMotorPosit;
		lElapseMotorPosit = get_motor_position_counter(L_MOTOR) - lInitMotorPosit;
		elapsedDist = rElapseMotorPosit < lElapseMotorPosit ? rElapseMotorPosit : lElapseMotorPosit;
		sleep(0.05);
	}
	stopMovement();
	return;
}
