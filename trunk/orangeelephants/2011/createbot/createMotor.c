#include "createMotor.h"
#include "createConstants.h"

/**
accel(int initSpeed, int finalSpeed)
Accelerates or decelerates the robot from one speed to the next in 20 incremental speeds. 
Robot continues on driving straight at finalSpeed.
*/
void accel(int initSpeed, int finalSpeed)
{
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

void createDrive(int finalSpeed)
{
	int initSpeed = get_create_requested_velocity(.1);
	
	accel(initSpeed, finalSpeed);
}

/** \brief Moves the robot a distance at a constant speed

	Does not work well for very short distances.
	\param distance Desired distance in mm
	\param speed Desired speed in ??
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
}


/** \brief Moves the robot a distance at a changing speed

	Does not work well for very short distances.
	\param distance Desired distance in mm
	\param initSpeed 
	\param finalSpeed 
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

//Optimized at d = 90, v = 200. Test at other values. 
void smoothTurn(float deg, int finalVel)	{
	deg = -deg;
	set_create_total_angle(0);
	float compRatio = .85; //.00405*finalVel*(standardVel/finalVel)
	
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

