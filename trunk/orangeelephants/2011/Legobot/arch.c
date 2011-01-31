#include "math.c"
#include "boolean.h"
#include "legobot_constants.h"
#include "legobot_motor.h"

void turn_arc_sweep(boolean leftArc, float outerRadius, int speed, float move_distance);


int main() 
{
	printf("Victor");
	
}

/*Function definitions go below.*/

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
