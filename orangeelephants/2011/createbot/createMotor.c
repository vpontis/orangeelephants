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


/** \brief Moves the robot a distance at a changing speed

	Does not work well for very short distances.
	\param distance Desired distance in mm
	\param initSpeed 
	\param finalSpeed 
*/

void moveToDistanceAccel(int distance, int finalSpeed) 
{ 
	set_create_distance(0); 
	
	double numIncrements = 4.;
	double increment = finalSpeed/numIncrements;
	
	int currSpeed = increment;
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
	float compRatio = .5*0.81; //.00405*finalVel*(standardVel/finalVel)
	
	int increment = finalVel/10;
	int currVel = increment;
	if(deg > 0){
		//CW: +deg, +vel
		while(get_create_total_angle(.1) < (compRatio*deg))	{
			while(currVel < finalVel)
			{
				create_drive_direct(currVel, -currVel);
				currVel += increment;
				sleep(.15*(deg/90));
			}
			currVel = finalVel;
			create_drive_direct(currVel, -currVel);
		}
		set_create_total_angle(0);
		while(get_create_total_angle(.1) < compRatio*deg){
			while(currVel > increment)
			{
				create_drive_direct(currVel, -currVel);
				currVel -= increment;
				sleep(.15*(deg/90));
			}
			currVel = 0;
			create_drive_direct(currVel, -currVel);
		}
	}
	else{
		while(get_create_total_angle(.1) > (compRatio*deg))	{
			while(currVel < finalVel)
			{
				create_drive_direct(-currVel, currVel);
				currVel += increment;
				sleep(.15*(deg/90));
			}
			currVel = finalVel;
			create_drive_direct(-currVel, currVel);
		}
		set_create_total_angle(0);
		while(get_create_total_angle(.1) > compRatio*deg){
			while(currVel > increment)
			{
				create_drive_direct(-currVel, currVel);
				currVel -= increment;
				sleep(.15*(deg/90));
			}
			currVel = 0;
			create_drive_direct(-currVel, currVel);
		}
	}
	create_stop();
	
}

