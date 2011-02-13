#include "createFunctions.h"
#include "createConstants.h"

/**
accel(int initSpeed, int finalSpeed)
Accelerates or decelerates the robot from one speed to the next in 20 incremental speeds. 
Robot continues on driving straight at finalSpeed.
*/
void accel(int initSpeed, int finalSpeed)
{
	int speed = initSpeed;
	int increm = (finalSpeed-initSpeed)/20;
	
	float time = abs((finalSpeed-initSpeed)/2500);//delay is .1 sec for accel from 0-500
	
	if(speed<finalSpeed)//if you are accelerating
	{
		while(speed<finalSpeed)
		{
			speed += increm; 
			create_drive_straight(speed);
			sleep(time);
		}
	}
	else//if you are decelerating
	{
		while(speed>finalSpeed)
		{
			speed += increm; 
			create_drive_straight(speed);
			sleep(time);
		}
	}
	
	create_drive_straight(finalSpeed);
}

void createDrive(int finalSpeed)
{
	int initSpeed = get_create_requested_velocity(.1);
	
	accel(initSpeed, finalSpeed);
}

void createInitialize()
{
	int conVal = create_connect();
	if(conVal == 0){
		printf("Connection success. Setting to full mode...");
	}
	else{
		printf("Connection failed.");
	}
	create_full();
}

/** \brief Moves the robot a distance at a constant speed

	Does not work well for very short distances.
	\param distance Desired distance in mm
	\param speed Desired speed in ??
*/
void moveToDistance(int distance, int speed) 
{ 
	int slowDownDist = speed*STOP_DISTANCE_RATIO; //Calculates the stopping distance based on speed
	
	//so it doesn't go in the wrong way with a short distance and fast speed
	//Needs testing/refinement
	if((slowDownDist > abs(distance))){ 
		slowDownDist = 0;
	}
	
	set_create_distance(0); 
	
	//Testing Code
	//printf("The total distance is %2.2d \n", distance - slowDownDist);
	//printf("The slowDownDist is %2.2d \n", slowDownDist);
	
	if(get_create_distance(.1) < distance) {   
		createDrive(speed);
        while (get_create_distance(.1) < (distance-slowDownDist)) {
                sleep(0.05);
        }
		create_stop();
     }
	 else{ 
		 //backwards
		 createDrive(-speed);
		 while (get_create_distance(.1) > (distance+slowDownDist)) {
                sleep(0.05);
        }
		create_stop();
	}
		 
}

//Moves the claw to pinch the blocks up until it hits the sensor
void moveClawUp(){
	
	mav(ARM_MOTOR_PORT, ARM_UP_VELOCITY);
	while (digital(ARM_TOUCH_PORT) == 0) //keep moving up until the touch sensor is triggered
	{
		sleep(0.1);
	}
	mav(ARM_MOTOR_PORT,0);
	clear_motor_position_counter(0);
}

//Moves the claw down a certain distance
void moveClawDown(int nDistance) {
	clear_motor_position_counter(0);
	mav(ARM_MOTOR_PORT, ARM_DOWN_VELOCITY);
	
	while(get_motor_position_counter(0) >= nDistance) {
		sleep(0.1);
	}
	mav(ARM_MOTOR_PORT,0);	
}


//picks up two blocks and lifts them to a height of two blocks then lets them go and puts the claw back down
void stackBlocks() { 

	set_servo_position(CLAW_PORT,CLAW_OPEN_POS); //790 = default value to clench
	sleep(.5);  //pause before clench 
	
	
	slowCloseClaw();
	sleep(1); //pause in between moving and clench
	
	moveClawUp();
	moveClawDown(ARM_PARTIAL_DOWN);
	
	sleep(1); 
	slowReleaseClaw();
	sleep(1); 

	moveClawDown(ARM_POS_DOWN - ARM_PARTIAL_DOWN); //Test this value. needs to go all the awy down. 
}



void slowReleaseClaw()
{	
	int clawPos = get_servo_position(CLAW_PORT); 
	int clawPosIncrement = CLAW_OPEN_POS/10; 
	
	while (clawPos < (CLAW_OPEN_POS - clawPosIncrement)) {//to prevent the claw from going too far
		set_servo_position(CLAW_PORT, clawPos); 
		clawPos += clawPosIncrement; 
		sleep(.05); 
	}
	
	set_servo_position(CLAW_PORT, CLAW_OPEN_POS);
}

void slowCloseClaw()
{	
	int clawPos = get_servo_position(CLAW_PORT); 
	int clawPosIncrement = clawPos/10; 
	
	while (clawPos >= clawPosIncrement) {//so to stop it from giving a negative servo value
                set_servo_position(CLAW_PORT, clawPos); 
                clawPos -= clawPosIncrement; 
                sleep(.1); 
    }
    set_servo_position(CLAW_PORT, 0);
}

void pickUpBlocks()
{
	slowCloseClaw();
	moveClawUp();
}

void turn(float deg, int vel)   {//turn a given amout using gc_angle
        deg = -1 * deg;
        float a=(float)(deg+(deg*0.09/360.0 - 0.14)*deg/2);
		sleep(.05);
        set_create_total_angle(0);
        if (a > 0) {
                create_spin_CCW(vel);
                while(get_create_total_angle(.1) < a) {
                        sleep(.05);
                }
        }
        else {
                create_spin_CW(vel);
                while(get_create_total_angle(.1) > a) {
                        sleep(.05);
                }
        }
        create_stop();  
}
