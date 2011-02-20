/** \file Create_motor.h
	\brief Mobility functions for the Create.
*/
#include "Create_constants.h"
#include "Create_motor.h"
#include "boolean.h"
#include "math.c"

//Create FUNCTIONS
/** \brief Moves a distance cm.

	Moves the float distance specified.
	To move in reverse you need to put in a negative distance.
	\param cm The distance to move.
*/
void move(float cm)
{
	if(cm < 0.0)
	{
		create_drive_straight(-SPEED);
	}
	else
	{
		create_drive_straight(SPEED);
	}
	printf("time1 %f\n", seconds());
	sleep(f_abs(cm*10.0)/(SPEED));//MM divided by MM per Second
	printf("time sleep %f\n",f_abs(cm*10.0)/SPEED);
	printf("time2 %f\n", seconds());
	stop();
}

/** \brief Moves the Create forward with our orientation

	Our Create is oriented in reverse direction so this function will move it
	forward according to that orientation. Does not accept negative distances. Call
	should be made to \ref move_backward to move in reverse. 
	\param cm The distance to be traveled forward.
*/
void move_forward(float cm)
{
	if(cm > 0.0)
		move(-cm);
	else
		printf("Error distance entered is negative");
}

/** \brief Moves the Create backward with our orientation.

	Our Create is oriented in reverse direction so this function will move it
	backward according to that orientation. Does not accept negative distances. Call
	should be made to \ref move_forward to move in forward direction. 
	\param cm The distance to be moved in reverse.
*/
void move_backward(float cm)
{
	if(cm > 0.0)
		move(cm);
	else
		printf("Error distance entered is negative\n");
}

/** \brief Moves the Create forward at specified speed.

	Drives forward with specified speed.
	\param speed The speed to move at. 
*/
void forward(int speed) 
{
    create_drive_direct(speed, speed);
}

/** \brief Moves the Create backward at specified speed.

	Drives backward with specified speed.
	\param speed The speed to move at.
*/
void backward(int speed) 
{
	create_drive_direct(-speed, -speed);
}

/** \brief Used to stop the Create's motors.
*/
void stop() 
{
    create_stop();
}

/** \brief Turns the specific amount of degrees using Create sensors.
	\param degrees The amount of degrees to turn
	\deprecated \ref turn_d or \ref turn_speed should be used in place of this due to accuracy.
*/
void turn(int degrees)
{
	//printf("Angle in turn method is:%n\n", degrees);
	if(degrees < 0.0)
		turn_ccw(-degrees);
	else
		turn_cw(-degrees);
}

/** \brief Turns the Create a certain amount of degrees
	\param degrees the amount of degrees for the Create to turn
	\deprecated Use \ref turn_d instead for better accuracy and precision.
	\see turn
*/
void turn_cw(int degrees) 
{	
    int lastDegree = 0;
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

/** \brief Turns Create counter clockwise
	
	Turns the Create a certain amount of degrees.
	\param degrees The amount of degrees for the Create to turn.
	\deprecated Use \ref turn_d instead for better accuracy and precision.
	\see turn
*/
void turn_ccw(int degrees) 
{
    int lastDegree = 0;
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
	printf("Exiting turn_ccw method\n");
}

/** \brief Turns the Create 90 degrees to the right

	Same as the call \code turn(RIGHT_ANGLE); \endcode
	\see create_constants.h
	\deprecated Use \ref turn_d instead for better accuracy and precision.
	\see turn
*/
void turn_right() 
{
    turn(RIGHT_ANGLE);
}

/** \brief Turns the Create 90 degrees to the left

	Same as the call \code turn(-RIGHT_ANGLE); \endcode
	\deprecated Use \ref turn_d instead for better accuracy and precision.
	\see create_constants.h
	\see turn
*/
void turn_left() 
{	printf("Angle is:%d\n", -RIGHT_ANGLE);
	turn(-RIGHT_ANGLE);
}

/** \brief Turns the Create an amount of degrees.

	Turns the Create at maximum speed a specific amount of degrees.
	\param d The amount of degrees to turn.
*/
void turn_d(float d)
{ 
    turn_speed(SPEED, d);
}

/** \brief Turns the Create to d degrees at speed s
	\param s The speed to turn the Create at.
	\param d The amount of degrees to turn the Create.
*/
void turn_speed(int s, float d)
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

/** \brief Moves the Create a specific distance using acceleration.

	<p>Distance in cm, init speed in mm/s, final speed in mm/s.
	Will accelerate up to finalSpeed and speed down to initSpeed over the 
	distance.</P>
*/
void move_dist(float distance, int initSpeed, int finalSpeed)
{
    int avgSpeedMM = (finalSpeed + initSpeed)/2; //mm/s
    int avgSpeedCM = avgSpeedMM / 10; //cm/s
    float time = distance / (float)avgSpeedCM; //cm / cm/s
    
    if (distance < 0.0)
		{
        finalSpeed *= -1;
        initSpeed *= -1;
        time *= -1.;
		}
    
    accelerate_straight(initSpeed, finalSpeed, time / 2.);
    accelerate_straight(finalSpeed, initSpeed, time / 2.);
}

/** \brief Turns the Create with acceleration a certain amount of degrees.
	\param degrees The amount of degrees to turn.
	\param initSpeed The inital speed.
	\param finalSpeed The final speed.
*/
void turn_angle(float degrees, int initSpeed, int finalSpeed)
{
	int avgSpeedMM = (finalSpeed + initSpeed)/2; //mm/s
	int avgSpeedCM = avgSpeedMM / 10; //cm/s
	float distance = 2.*3.14159*15.24*degrees/360.;
	float time = distance / (float)avgSpeedCM;
	int initSpeedL = initSpeed, initSpeedR = initSpeed;
	int finalSpeedL = finalSpeed, finalSpeedR = finalSpeed;
	
	if(degrees < 0.)
	{
		//turn with different directions in accerlerate method
		initSpeedL *= -1;
		finalSpeedL *= -1;
		time *= -1;
	}
	else
	{
		initSpeedR *= -1;
		finalSpeedR *= -1;
	}
	
	accelerate(initSpeedL, initSpeedR, finalSpeedL, finalSpeedR, time);
		
}

/** \brief Acceleration when only moving in a straight line.
	\param motorVelocity The initial velocity for both motors.
	\param finalVelocity The final velocity for both motors.
	\param time The time to accelerate for.
*/
void accelerate_straight(int motorVelocity, int finalVelocity, float time)
{
	accelerate(motorVelocity, motorVelocity, finalVelocity, finalVelocity, time);	
}

/** \brief Accelerates robot from initial velocity for each motor to final 
	velocity for each motor over the period of time specified.
	
	Starting from an initial velocity the robot will accelerate to the final velocity and
	cover half the distance then it will decelerate to the initial velocity covering the second half
	of the distance.
	\param motorVelocityL The initial left motor velocity.
	\param motorVelocityR The initial right motor velocity.
	\param finalVelocityL The final left motor velocity.
	\param finalVelocityR The final right motor velocity.
	\param time The period to accelerate/decelerate over.
*/
void accelerate(int motorVelocityL, int motorVelocityR, int finalVelocityL, int finalVelocityR,
 float time)
{
    int deltaVelocityL = finalVelocityL - motorVelocityL; //change in left velocity
	int deltaVelocityR = finalVelocityR - motorVelocityR; //change in right velocity
    int avgAccelL = (int)((float)(fabs(deltaVelocityL)) / time); //change in speed per sec
	int avgAccelR = (int)((float)(fabs(deltaVelocityR)) / time); //change in speed per sec

    if (deltaVelocityL > 0 && deltaVelocityR > 0)
      {
        while(motorVelocityL <= finalVelocityL && motorVelocityR <= finalVelocityR)
        {
            motorVelocityL += (avgAccelL/10);
			motorVelocityR += (avgAccelR/10);
            if(motorVelocityL > finalVelocityL && motorVelocityR > finalVelocityR)
            {
  				motorVelocityL = finalVelocityL + 1; //this accounts for the <= in while loop
				motorVelocityR = finalVelocityR + 1;
			}
            //set speed for bot to move at.
            create_drive_direct(motorVelocityL, motorVelocityR);
            sleep(0.1);
        }
    }    
    else if (deltaVelocityL < 0 && deltaVelocityR > 0)
    {
        while(motorVelocityL >= finalVelocityL && motorVelocityR <= finalVelocityR)
          {
            motorVelocityL -= (avgAccelL/10);
			motorVelocityR += (avgAccelR/10);
            if(motorVelocityL < finalVelocityL && motorVelocityR > finalVelocityR)
            {
  				motorVelocityL = finalVelocityL - 1;
				motorVelocityR = finalVelocityR + 1;
            }
			//set speed for bot to move at.
            create_drive_direct(motorVelocityL, motorVelocityR);
            sleep(0.1);
        }
    }
	else if (deltaVelocityL > 0 && deltaVelocityR < 0)
	{
		while(motorVelocityL <= finalVelocityL && motorVelocityR >= finalVelocityR)
          {
            motorVelocityL += (avgAccelL/10);
			motorVelocityR -= (avgAccelR/10);
            if(motorVelocityL > finalVelocityL && motorVelocityR < finalVelocityR)
            {
  				motorVelocityL = finalVelocityL + 1;
				motorVelocityR = finalVelocityR - 1;
            }
			//set speed for bot to move at.
            create_drive_direct(motorVelocityL, motorVelocityR);
            sleep(0.1);
        }
	}
	else if (deltaVelocityL < 0 && deltaVelocityR < 0)
	{
        while(motorVelocityL >= finalVelocityL && motorVelocityR >= finalVelocityR)
        {
            motorVelocityL -= (avgAccelL/10);
			motorVelocityR -= (avgAccelR/10);
            if(motorVelocityL < finalVelocityL && motorVelocityR < finalVelocityR)
            {
  				motorVelocityL = finalVelocityL - 1; //this accounts for the <= in while loop
				motorVelocityR = finalVelocityR - 1;
			}
            //set speed for bot to move at.
            create_drive_direct(motorVelocityL, motorVelocityR);
            sleep(0.1);
        }
	}
}

/** \brief Opens the claws on the Create.
*/
void release()
{
	set_servo_position(LEFTDETACH, 900);
	set_servo_position(RIGHTDETACH, 1630);
}

/** \brief Closes the claws on the Create.
*/
void grab()
{
	set_servo_position(LEFTDETACH, 1440);
	set_servo_position(RIGHTDETACH, 1200);
}

/** \brief Makes the Create arc

	<p>A method that makes the robot turn in an arc
	all measurements in mm or mm/s.</p>
	\param leftArc True if we are arching left, false if we are arching right
	\param outerRadius The radius from the center of the circle to the outer wheel
	\param speed The speed at which the outer wheel turns
	\param moveDistance The distance the the outer wheel will travel
*/
void turn_arc(boolean leftArc, float outerRadius, float speed, float moveDistance)
{
	float time = moveDistance/speed;
	printf("gctotaldistance = %d\n", gc_distance);
	if(moveDistance < 0.0)
	{
		time*=-1;
	}
	
	if (outerRadius < CREATE_RADIUS)
		{
			printf("Outer Radius must be greater than %d\n", CREATE_RADIUS);
			return;
		}
	float ratio = (outerRadius - CREATE_RADIUS)/(outerRadius);
	float smallerDistance = moveDistance * ratio, smallerVelocity = speed * ratio;
	
	if (leftArc)
		{
			create_drive_direct(smallerVelocity, speed);
		}
	else
		{
			create_drive_direct(speed, smallerVelocity);
		}
	sleep(time);
	printf("gctotaldistance = %d\n", gc_distance);
	stop();
}

/** \brief Turns an arc at the specified speed for the specified amount of degrees.

	Allows the use of the function \ref turn_arc, but using degrees instead of distance.
	\param leftArc true to arc left; false to arc right.
	\param outerRadius The outer radius of the arc.
	\param speed The speed of the arc.
	\param degrees The degrees to turn of the arc.
*/
void turn_arc_degrees(boolean leftArc, float outerRadius, float speed, float degrees)
{
	turn_arc(leftArc, outerRadius, speed, arc_length(degrees, outerRadius));
}
