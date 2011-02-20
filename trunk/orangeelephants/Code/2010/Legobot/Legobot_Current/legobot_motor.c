#include "boolean.h"
#include "legobot_motor.h"
#include "math.c"
void moveToDistance(double distance, int speed)
	{
		static double ticksPerRev = 1020.4; //Number of motor ticks in one revolution
		static double circumference = 25.6; //Circumference in cm of 81.6x38R Lego wheels
		
		int ticksToMove = (int) (( distance / circumference ) * ticksPerRev);
		mrp(L_MOTOR,speed,ticksToMove);
		mrp(R_MOTOR,speed,ticksToMove);
		bmd(L_MOTOR);
		bmd(R_MOTOR);
		
		return;
	}
	
void moveToDistanceTurn(double distance, int speedL, int speedR)
	{
		static double ticksPerRev = 1020.4; //Number of motor ticks in one revolution
		static double circumference = 25.6; //Circumference in cm of 81.6x38R Lego wheels
		
		int ticksToMove = (int) (( distance / circumference ) * ticksPerRev);
		mrp(L_MOTOR,speedL,ticksToMove);
		mrp(R_MOTOR,speedR,ticksToMove);
		bmd(L_MOTOR);
		bmd(R_MOTOR);
		
		return;
	}
void turn_arc(boolean leftArc, float outerRadius, int speed, float move_distance)
{
	static double ticksPerRev = 1020.4; //Number of motor ticks in one revolution
	static double circumference = 25.6; //Circumference in cm of 81.6x38R Lego wheels
	
	
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
		mrp(L_MOTOR, smallerVelocity, (long)(((smallerDistance / circumference ) * ticksPerRev)));
		mrp(R_MOTOR, speed, (long)(((move_distance / circumference ) * ticksPerRev)));
	}
	else
	{
		mrp(L_MOTOR, speed, (long)(((move_distance / circumference ) * ticksPerRev)));
		mrp(R_MOTOR, smallerVelocity, (long)(((smallerDistance / circumference ) * ticksPerRev)));
	}
	bmd(L_MOTOR);
	bmd(R_MOTOR);
}
void turn_arc_sweep(boolean leftArc, float outerRadius, int speed, float move_distance)
{
	static double ticksPerRev = 1020.4; //Number of motor ticks in one revolution
	static double circumference = 25.6; //Circumference in cm of 81.6x38R Lego wheels
	
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
		mrp(L_MOTOR, smallerVelocity, (long)(((smallerDistance / circumference ) * ticksPerRev)));
		mrp(R_MOTOR, speed, (long)(((move_distance / circumference ) * ticksPerRev)));
	}
	else
	{
		mrp(L_MOTOR, speed, (long)(((move_distance / circumference ) * ticksPerRev)));
		mrp(R_MOTOR, smallerVelocity, (long)(((smallerDistance / circumference ) * ticksPerRev)));
	}
	bmd(L_MOTOR);
	bmd(R_MOTOR);
}
 void turn_arc_degrees(boolean leftArc, float outerRadius, int speed, float degrees)
{
        turn_arc(leftArc, outerRadius, speed, arc_length(degrees, outerRadius));
}


void turn(double angle)
{
	static double BotCircumference = 53.4; //BOT CIRCUMFERENCE
	static double ticksPerRev = 1020.4; //Number of motor ticks in one revolution
	static double circumference = 25.6; //Circumference in cm of 81.6x38R Lego wheels
	double turnCM = d_abs((angle/360.0) * 53.4);
	int ticksToMove = (int) (( turnCM / circumference ) * ticksPerRev);
	
		
	if(angle<0)
	{
		mrp(L_MOTOR, 500, -ticksToMove);
		mrp(R_MOTOR, 500, ticksToMove);
	}
	else{
		mrp(L_MOTOR, 500, ticksToMove);
		mrp(R_MOTOR, 500, -ticksToMove);
		
		}
	bmd(L_MOTOR);
	bmd(R_MOTOR);
	
}

void accel(int init_velocity, int final_velocity, double time)
{
	
	static double step_amount = 100.0;
	double step_vel_size = ((double)(final_velocity - init_velocity))/step_amount;
	double step_time_size = time/step_amount;
	int curr_vel = init_velocity;
	int step_num = 0;
	
	mav(L_MOTOR, curr_vel);
	mav(R_MOTOR, curr_vel);
	while(step_num <= step_amount)
		{
			sleep(step_time_size);
			curr_vel += step_vel_size;
			mav(L_MOTOR, curr_vel);
			mav(R_MOTOR, curr_vel);
			step_num++;
		}
	
	return;
}

void stopMovement()
	{
		mav(L_MOTOR, 0);
		mav(R_MOTOR, 0);
	}
void moveStraight(int velocity)
	{
		mav(L_MOTOR, velocity);
		mav(R_MOTOR, velocity);
	}
int cmToTicks(float cmDistance)
	{
		static double ticksPerRev = 1020.4; //Number of motor ticks in one revolution
		static double circumference = 25.6; //Circumference in cm of 81.6x38R Lego wheels
		
		return (int) (( cmDistance / circumference ) * ticksPerRev);
		
	}

void turnArc(boolean leftArc, float outerRadius,float outerSpeed, float amountDegrees)
{
	float Pi = 3.14159;
	float wheelCircumference = 25.6;
	float ticksPerRev = 1020.4;
	float ratio = (outerRadius - 17)/(outerRadius);
	float outerCircumference = 2 * Pi * outerRadius * (1/wheelCircumference);
	float innerCircumference = outerCircumference * ratio;
	float innerSpeed = outerSpeed * ratio; 
	
	if(leftArc)
	{
		mrp(L_MOTOR, innerSpeed, innerCircumference*ticksPerRev*(amountDegrees/360.0));
		mrp(R_MOTOR, outerSpeed, outerCircumference*ticksPerRev*(amountDegrees/360.0));
	}
	else
	{
		mrp(R_MOTOR, innerSpeed, innerCircumference*ticksPerRev*(amountDegrees/360.0));
		mrp(L_MOTOR, outerSpeed, outerCircumference*ticksPerRev*(amountDegrees/360.0));
		
	}
	/*
		outerRadius = R
		outerRadius/innerRadius = (R-17cm)/R = circle ratio
		circumference of outer circle = 2PiR
		circumference of inner circle = 2PiR*(circle ratio)
		establish an arbitrary velocity for outer wheel, say 600
		inner wheel velocity = 600 * (circle ratio)
		if you want to only go part of a circle do the following:
			degrees of circle you want to go = D
			D/360=the number of centimeters you tell the outer circle to go<--percent by both 60/360 for both
		ratio of velocity determines curvature of arc
		the centimeters determines the length of the arc
	*/
	bmd(L_MOTOR);
	bmd(R_MOTOR);
}
