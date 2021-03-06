/**
** \file createMotor.c
** \brief Functions for controlling create movement. 
**
** Create movement methods 
**
*/


#include "createMotor.h"
#include "createConstants.h"


/** \brief Experimental acceleration function

	Accelerates or decelerates the robot from one speed to the next in 20 incremental speeds. 
	Robot continues on driving straight at finalSpeed.
	\param initSpeed Velocity to begin accelerating at
	\param finalSpeed Final velocity to accelerate to
*/
void accel(int initSpeed, int finalSpeed)
{
	initSpeed = -initSpeed;
	finalSpeed = -finalSpeed;
	int speed = initSpeed;
	int increm = (finalSpeed-initSpeed)/30;
	
	float time = abs((finalSpeed-initSpeed)/10000);//delay is .1 sec for accel from 0-500
	
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


/** \brief Accelerate from current speed to specified speed
	
	Utilizes the accel function and uses current speed as initSpeed.
	\param finalSpeed Final speed to accelerate to
*/
void createDrive(int finalSpeed)
{
	int initSpeed = get_create_requested_velocity(.1);
	
	accel(initSpeed, finalSpeed);
}


/** \brief Moves the robot a distance at a constant speed

	Does not work well for very short distances.
	\param distance Desired distance in mm
	\param speed Desired speed in mm/sec
*/
void moveToDist(int distance, int speed) 
{ 
	distance = -distance;
	set_create_distance(0); 
	
	if(distance > 0) {   
		create_drive_straight(speed);
		while (get_create_distance(.1) < distance) {}
	}
	else{ //backwards
		create_drive_straight(-speed);
		while (get_create_distance(.1) > distance) {}
	}
	create_stop();
}


/** \brief Moves the robot a distance at a changing speed

	Does not work well for very short distances.
	\param distance Desired distance in mm
	\param initSpeed 
	\param finalSpeed 
	\deprecated Requires refinement and is inaccurate. Use \ref accel or \ref moveToVictor
*/
void moveToDistAccel(int distance, int finalSpeed) 
{
	//Input velocity is ALWAYS positive
	distance = -distance;
	//double compRatio = finalSpeed/3000.;
	double totalDistance = 0;
	//distance = compRatio * distance;
	
	set_create_distance(0); 
	double numIncrements = 50.;
	double increment = finalSpeed/numIncrements;
	double currSpeed;
	
	
	if(distance > 0) {
		currSpeed = increment;
		create_drive_straight(currSpeed);
		while((totalDistance) < (distance/2)) {   
			set_create_distance(0);
			while(get_create_distance(.1) > (distance/(numIncrements))){}
			totalDistance += (distance/(numIncrements));
			currSpeed += increment;
			create_drive_straight(currSpeed);
			//sleep(delay);
		}
		
		totalDistance = 0;
		while((totalDistance) < (distance/2)) {   
			set_create_distance(0);
			while(get_create_distance(.1) > (distance/numIncrements)) {}
			totalDistance += (distance/(numIncrements));
			currSpeed -= increment;
			create_drive_straight(currSpeed);
			//sleep(delay);
		}
		
	}
	else{
		currSpeed = -increment;
		create_drive_straight(currSpeed);
		while((totalDistance) > (distance/2)) { 
			set_create_distance(0);
			while(get_create_distance(.1) > (distance/numIncrements)) {}
			totalDistance += (distance/numIncrements);
			currSpeed -= increment;
			create_drive_straight(currSpeed);
			//sleep(delay);
		}
		
		totalDistance = 0;
		while((totalDistance) > (distance/2)) {  
			set_create_distance(0);
			while(get_create_distance(.1) > (distance/numIncrements)) {}
			totalDistance += (distance/numIncrements);
			currSpeed += increment;
			create_drive_straight(currSpeed);
			//sleep(delay);
		}
	}
	create_stop();
	
}


/** \brief Function to turn the create a specified degree.
	\param deg Relative degrees to turn. Positive is CW
	\param vel Speed to turn at. Always positive.
*/
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


/** \brief Smooth turn function to turn a specified degree. 
	Create will accelerate to finalVel at totaltime/2 and then decelerate to 0. 
	Optimized at deg = 90, vel = 200.  
	\param deg Relative degrees to turn. Positive is CW
	\param vel Speed to turn at. Always positive.
	\todo Testing needed at other values.
*/
void smoothTurn(float deg, int finalVel)	{
	deg = -deg;
	set_create_total_angle(0);
	float compRatio = .75; //.00405*finalVel*(standardVel/finalVel)
	
	float increment = (float) finalVel/10;
	float currVel = increment;
	if(deg > 0){
		//CCW: +deg, +vel
		while(get_create_total_angle(.1) < 0.5*(compRatio*deg))	{
			while(currVel < finalVel)
			{
				create_drive_direct(currVel, -currVel);
				currVel += increment;
				sleep(.05);
			}
			currVel = finalVel;
			create_drive_direct(currVel, -currVel);
		}
		
		set_create_total_angle(0);
		
		while(get_create_total_angle(.1) < 0.5*(compRatio*deg)){
			while(currVel > increment)
			{
				create_drive_direct(currVel, -currVel);
				currVel -= increment;
				sleep(.05);
			}
			currVel = 0;
			create_drive_direct(currVel, -currVel);
		}
	}
	else{
		while(get_create_total_angle(.1) > 0.5*(compRatio*deg))	{
			while(currVel < finalVel)
			{
				create_drive_direct(-currVel, currVel);
				currVel += increment;
				sleep(.05);
			}
			currVel = finalVel;
			create_drive_direct(-currVel, currVel);
		}
		set_create_total_angle(0);
		
		while(get_create_total_angle(.1) > 0.5*(compRatio*deg)){
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


/** \brief Move straight a specified velocity

	Create will accelerate to finalVel at totaltime/2 and then decelerate to 0. 
	Optimized at deg = 90, vel = 200.  
	\param speed Speed in mm/sec to move at
*/
void moveStraight(int speed){
	create_drive_straight(-speed);
}

/** \brief Experimental acceleration function
	
	\param distance
	\param speed
*/
void moveToVictor(int distance, int speed) 
{ 
        set_create_distance(0); 	
		
		
		
        if(distance > 0) {   
                createDrive(speed);
                while (get_create_distance(.1) < distance) {}
                createDrive(0);
        }
        else{ //backwards
                createDrive(-speed);
                while (get_create_distance(.1) > distance) {}
                createDrive(0);
        }
}

/** \brief Stops create movement
*/
void createStop(){
	moveStraight(0);
}

/** \brief Uses vision to center create on a colored blob
	\todo Clean up to allow for easier editing
	
	Utilizes visionAvgX to target the center of the blob. Moves left
	or right depending in order to center. Callibrated for red blocks.
	\param ch Color channel to use. 
*/
void createCenter(int ch){
	printf("Centering... \n");
	int avgX = visionAvgX(ch);
	int threshold = 1;
	while(avgX != 0){
		printf("Readjusting... \n");
		avgX = visionAvgX(ch);
		if(avgX > threshold){
			create_drive_direct(-100, 100);
			sleep(.01);
			createStop();
			sleep(.1);
			
		}
		else{
			create_drive_direct(100, -100);
			sleep(.01);
			createStop();
			sleep(.1);
		}
	}
	printf("Centered!");
}
