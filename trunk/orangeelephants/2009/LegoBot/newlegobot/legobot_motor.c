/**
	\file legobot_motor.h
	\date Feb 14, 2009
	\author Mark Allen Vismonte
	\brief Mobility functions for LegoBot
	
	This file contains methods that the legobot uses for moving purposes.
*/

#include "legobot_motor.h"
#include "math.c"

/** \brief Turns a number of degrees
	\param degrees The amount of degrees to turn.
*/
void turn(float degrees)
{
	long ticks = (long)(TICKS_PER_DEGREE * degrees);
	if (degrees > 0.0)
		printf("Turning left\n");
	else
		printf("Turning right\n");
	mrp(L_MOTOR,MAX_SPEED,-ticks);
	mrp(R_MOTOR,MAX_SPEED,ticks);
	bmd_motors();
}

/** \brief Moves a certain distance in mm
	\param speed -MAX_SPEED to MAX_SPEED in ticks/s.
	\param distance The amount of mm (+-) to be moved.
*/
void move_direct_distance(int speed, float distance)
{
	mrp(L_MOTOR, speed, distance * TICKS_PER_MM);
	mrp(R_MOTOR, speed, distance * TICKS_PER_MM);
	bmd_motors();
}

/** \brief Moves a certain distance in mm.
	\param distance The amount of distance to move in mm.
*/
void move_distance(float distance)
{
	long ticks = (long)(f_abs(distance * TICKS_PER_MM));//starting using abs value from math.h
	//ticks = ticks > 0? ticks: -ticks;
	printf("ticks = %d\n",(int)ticks);
	int x = ticks/TICKS_PER_ITERATION, y = ticks % TICKS_PER_ITERATION, i,
	leftGoal = get_motor_position_counter(0) + TICKS_PER_ITERATION
	, rightGoal = get_motor_position_counter(3) + TICKS_PER_ITERATION;
	printf("x=%d, y=%d\n", x, y);
	printf("Moving Distance: %d \n", (int)ticks);
	for (i = 0; i < x; i++, leftGoal += TICKS_PER_ITERATION, rightGoal += TICKS_PER_ITERATION)
	{
		if (distance > 0)
		{
			mrp(L_MOTOR, MAX_SPEED, TICKS_PER_ITERATION);
			mrp(R_MOTOR, MAX_SPEED, TICKS_PER_ITERATION);
		}
		else
		{
			mrp(L_MOTOR, MAX_SPEED, -TICKS_PER_ITERATION);
			mrp(R_MOTOR, MAX_SPEED, -TICKS_PER_ITERATION);
		}
		bmd_motors();
		printf("i=%d\n",i);
	}
	if (distance > 0)
	{
		mrp(L_MOTOR, MAX_SPEED, y);
		mrp(R_MOTOR, MAX_SPEED, y);
	}
	else
	{
		mrp(L_MOTOR, MAX_SPEED, -y);
		mrp(R_MOTOR, MAX_SPEED, -y);
	}
	bmd_motors();
}

/** \brief Moves the LegoBot in an arc.
	\param leftArc true if we are arching left, false if we are arching right
	\param outerRadius The radius from the center of the circle to the outer wheel
	\param speed The speed at which the outer wheel turns
	\param move_distance The distance the the outer wheel will travel
*/
void turn_arc(boolean leftArc, float outerRadius, int speed, float move_distance)
{
	if (outerRadius < LEGOBOT_DIAMETER)
	{
		printf("Outer Radius must be greater than %d\n", LEGOBOT_DIAMETER);
		return;
	}
	float ratio = (outerRadius - LEGOBOT_DIAMETER)/(outerRadius);
	printf("Arcing Ratio =%f\n",ratio);
	float smallerDistance = move_distance * ratio;
	int	smallerVelocity = (int)(speed * ratio);
	if (leftArc)
	{
		mrp(L_MOTOR, smallerVelocity, (long)(smallerDistance * TICKS_PER_MM));
		mrp(R_MOTOR, speed, (long)(move_distance * TICKS_PER_MM));
	}
	else
	{
		mrp(L_MOTOR, speed, move_distance * TICKS_PER_MM);
		mrp(R_MOTOR, smallerVelocity, (long)(smallerDistance * TICKS_PER_MM));
	}
	bmd_motors();
}

/** \brief Moves the LegoBot in arc for the specified degrees.
	\param leftArc true if we are arching left, false if we are arching right
	\param outerRadius The radius from the center of the circle to the outer wheel
	\param speed The speed at which the outer wheel turns
	\param degrees The amount of the degrees of the circle that the legobot will move
*/
void turn_arc_degrees(boolean leftArc, float outerRadius, int speed, float degrees)
{
	turn_arc(leftArc, outerRadius, speed, arc_length(degrees, outerRadius));
}

/** \brief Moves the Legobot in an arc @ a specified velocity and outer radius
	Theoretically makes a circle with the radius of outerRadius using the
	Ratio calculated by (outerRadius - LEGOBOT_DIAMETER)/(outerRadius)
	The method calls move(speed, speed) instead of move distance because
	The function is meant to just arc until the user doesn't want it to
	\param leftArc true if we are arching left, false if we are arching right
	\param outerRadius The radius from the center of the circle to the outer wheel
	\param outerSpeed The speed at which the outer wheel turns
*/
void turn_arc_at_velocity(boolean leftArc, float outerRadius, int outerSpeed)
{
	if (outerRadius < LEGOBOT_DIAMETER)
	{
		printf("Outer Radius must be greater than %d\n", LEGOBOT_DIAMETER);
		return;
	}
	float ratio = (outerRadius - LEGOBOT_DIAMETER)/(outerRadius);
	printf("Ratio=%d\n");
	if (leftArc)
		move ((int)(outerSpeed * ratio), outerSpeed);
	else
		move (outerSpeed, (int)(ratio * outerSpeed));
}


/** \brief Moves the motors 
	\param velocityL Left motor velocity
	\param velocityR Right motor velocity
*/
void move(int velocityL, int velocityR)
{
	mav(L_MOTOR, velocityL);
	mav(R_MOTOR, velocityR);
}

/** \brief Turns off the motors
*/
void turn_off()
{
	move(0, 0);
}

/** \brief Blocks both motors until their are done
*/
void bmd_motors()
{
	bmd(L_MOTOR);
	bmd(R_MOTOR);
}

/** \brief Locks the arms into position.
*/
void lock_arms()
{
	printf("Locking Arms\n");
	enable_servos();
	set_servo_position(FRONT_ARM, 0);
	set_servo_position(BACK_ARM, 0);
}

/** \brief Releases the locking pins to drop the arms.
*/
void release_arms()
{
	printf("Releasing Arms\n");
	set_servo_position(FRONT_ARM,1350);
	set_servo_position(BACK_ARM,1760);
	msleep(1500L);
	//disable_servos();
}

/** \brief Freezes the motors.
	
	A method that can be used to freeze a motor
	First set global boolean doIce = true
	Next, start_process(ice)
	When you want it to stop blocking, set doIce equal to false
	Then kill the process
*/
void ice()
{
	int leftStart = get_motor_position_counter(L_MOTOR), rightStart = get_motor_position_counter(R_MOTOR);
	while (doIce)
	{
		if (i_abs(get_motor_position_counter(L_MOTOR) - leftStart) > 15)
			mtp(L_MOTOR, MAX_SPEED, leftStart);
		if (i_abs(get_motor_position_counter(R_MOTOR) - rightStart) > 15)
			mtp(R_MOTOR, MAX_SPEED, rightStart);
	}
}
