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
void moveToDist(int distance, int speed) 
{ 
	int slowDownDist = speed*STOP_DISTANCE_RATIO; //Calculates the stopping distance based on speed
	
	//so it doesn't go in the wrong way with a short distance and fast speed
	if( slowDownDist > abs(distance)/2 ){ 
		slowDownDist = 0;
	}
	
	set_create_distance(0); 
	
	if(get_create_distance(.1) < distance) {   
		createDrive(speed);
		while (get_create_distance(.1) < (distance-slowDownDist)) {		}
		createDrive(0);
	}
	else	{ //backwards
		createDrive(-speed);
		while (get_create_distance(.1) > (distance+slowDownDist)) {		}
		createDrive(0);
	}
}


/** \brief Moves the robot a distance at a changing speed

	Does not work well for very short distances.
	\param distance Desired distance in mm
	\param initSpeed 
	\param finalSpeed 
*/

void moveToDistanceAccel(int distance, int initSpeed, int finalSpeed) 
{ 
	set_create_distance(0); 
	if(initSpeed == 0){
		if(distance < 0){
			initSpeed = -50;
		}
		else{
			initSpeed = 50;
		}
	}
	double numIncrements = 4.;
	double increment = (finalSpeed - initSpeed)/numIncrements;
	int currSpeed = initSpeed;
	double totalDistance = 0;
	createDrive(currSpeed);
	if(distance > 0) {
		while((totalDistance) < (distance/numIncrements)) {   // WHY divide by 4? DONT FUCKING KNOW.
			set_create_distance(0);
			while(get_create_distance(.1) < (distance/(numIncrements))){}
			totalDistance += (distance/(numIncrements));
			currSpeed += increment;
			createDrive(currSpeed);
		}
		
		totalDistance = 0;
		while((totalDistance) < (distance/numIncrements)) {   
			set_create_distance(0);
			while(get_create_distance(.1) < (distance/numIncrements)) {}
			totalDistance += (distance/(numIncrements));
			currSpeed -= increment;
			createDrive(currSpeed);
		}
		
	}
	else{
		while((totalDistance) > (distance/numIncrements)) { // WHY divide by 4? DONT FUCKING KNOW.
			//WTF I DON'T KNOW WHY THIS WORKS BUT IT DOES.
			set_create_distance(0);
			while(get_create_distance(.1) > (distance/numIncrements)) {}
			totalDistance += (distance/numIncrements);
			currSpeed += increment;
			createDrive(currSpeed);
		}
		totalDistance = 0;
		while((totalDistance) > (distance/numIncrements)) {   //WTF I DON'T KNOW WHY THIS WORKS BUT IT DOES
			set_create_distance(0);
			while(get_create_distance(.1) > (distance/numIncrements)) {}
			totalDistance += (distance/numIncrements);
			currSpeed -= increment;
			createDrive(currSpeed);
		}
	}
	create_stop();
	
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

void moveClaw(int position)	{
	mtp(ARM_MOTOR_PORT, ARM_DOWN_VELOCITY, position);
	bmd(ARM_MOTOR_PORT);
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
	int clawPosIncrement = CLAW_OPEN_POS/50; 
	
	while (clawPos < (CLAW_OPEN_POS - clawPosIncrement)) {//to prevent the claw from going too far
		set_servo_position(CLAW_PORT, clawPos); 
		clawPos += clawPosIncrement; 
		sleep(.1); 
	}
	
	set_servo_position(CLAW_PORT, CLAW_OPEN_POS);
}

void slowCloseClaw()
{	
	int clawPos = get_servo_position(CLAW_PORT); 
	int clawPosIncrement = clawPos/20; 
	
	while (clawPos >= clawPosIncrement) {//so to stop it from giving a negative servo value
		set_servo_position(CLAW_PORT, clawPos); 
		clawPos -= clawPosIncrement; 
		sleep(.1); 
	}
	set_servo_position(CLAW_PORT, 0);
}

void setClaw(int position)
{		
	int currPos = get_servo_position(CLAW_PORT);
	printf("Init servo position is %d.\n", currPos);
	int increment = abs(position-currPos)/10;
	printf("The increment is %d.\n", increment);
	
	int counter = 1;
	
	if(position < currPos)	{//to close the claw
		while(counter <= 10)	{
			currPos-=increment;
			set_servo_position(CLAW_PORT, currPos);
			sleep(.1);
			counter += 1;
		}
	}
	else if(position > currPos)	{//to open the claw
		while( counter <= 10){
			currPos += increment;
			set_servo_position(CLAW_PORT, currPos);
			sleep(.1);
			counter += 1;
		}
	}
	
	set_servo_position(CLAW_PORT, position);

	printf("Final servo posit is %d.\n", get_servo_position(CLAW_PORT));
}

void pickUpBlocks()
{
	slowCloseClaw();
	moveClawUp();
}

void turn(float deg, int vel)	{
	deg = -deg; 
	set_create_total_angle(0);
	if(deg > 0)	{
		//create_spin_CCW(vel);
		create_drive_direct(vel, -vel); //turns CCW
		while(get_create_total_angle(.05) < deg){}
	}
	else{	
		//create_spin_CW(vel);
		create_drive_direct(-vel, vel);
		while(get_create_total_angle(.05) > deg){}
	}
	create_stop();
}

void accelTurn(float deg, int vel)	{
	deg = -deg;
	set_create_total_angle(0);
	int finalVel = vel;
	int increment = vel/10;
	int currVel = 0;
	if(deg > 0)	{
		while(get_create_total_angle(.1) < (deg/2))	{
			while(currVel < (vel-increment))
			{
				create_spin_CCW(increment);
				increment += increment;
				sleep(.05);
			}
			create_spin_CW(vel);
		}
	}
	else	{
		while(get_create_total_angle(.1) > deg)	{
			while(currVel < (vel-increment))
			{
				create_spin_CW(increment);
				increment += increment;
				sleep(.05);
			}
			create_spin_CCW(vel);
		}
	}
	create_stop();
}

void smoothTurn(float deg, int finalVel)	{
	deg = -deg;
	set_create_total_angle(0);
	
	int increment = finalVel/10;
	int currVel = 40;
	if(deg > 0){
		//CCW: +deg, +vel
		while(get_create_total_angle(.1) < (0.5*deg))	{
			while(currVel < (finalVel-increment))
			{
				create_drive_direct(currVel, -currVel);
				currVel += increment;
				sleep(.2);
			}
			currVel = finalVel;
			create_drive_direct(currVel, -currVel);
		}
		while(get_create_total_angle(.1) < deg){
			while(currVel > increment)
			{
				create_drive_direct(currVel, -currVel);
				currVel -= increment;
				sleep(.2);
			}
			currVel = 0;
			create_drive_direct(currVel, -currVel);
		}
	}
	else{
		while(get_create_total_angle(.1) > (0.5*deg))	{
			while(currVel < (finalVel-increment))
			{
				create_drive_direct(-currVel, currVel);
				currVel += increment;
				sleep(.05);
			}
			currVel = finalVel;
			create_drive_direct(-currVel, currVel);
		}
		set_create_total_angle(0);
		while(get_create_total_angle(.1) > (0.5*deg)){
			while(currVel > increment)
			{
				create_drive_direct(-currVel, currVel);
				currVel -= increment;
				sleep(.05);
			}
			currVel = 0;
			create_drive_direct(-currVel, currVel);
		}
	}
	create_stop();
		
}

void moveToShort(int distance, int speed) 
{ 
	set_create_distance(0); 
	
	if(get_create_distance(.1) < distance) {   
		create_drive_direct(speed,speed);
		while (get_create_distance(.1) < (distance)) {		}
		create_stop();
	}
	else	{ //backwards
		create_drive_direct(-speed,-speed);
		while (get_create_distance(.1) > (distance)) {		}
		create_stop();
	}
}



