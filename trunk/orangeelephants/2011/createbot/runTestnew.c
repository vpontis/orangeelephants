#include "createConstants.h"
#include "runTestnew.h"

int increment = 79; // maxClawRelease divided by 10
int x = 0; 
int main()
{
	pickUpDropOff();
}

void moveArmUp(){
	
	mav(armMotorPort, armUpVelocity);
	while (digital(15) == 0) // port 15 is sensor number
	{
		sleep(0.1);
	}
	mav(armMotorPort,0);
	clear_motor_position_counter(0);
	sleep(0.5);  //removable??
}

void moveArmDown(int nDistance) {
	clear_motor_position_counter(0);
	mav(armMotorPort, armDownVelocity);
	
	while(get_motor_position_counter(0) >= nDistance) {
		sleep(0.1);
	}
	mav(armMotorPort,0);	
}

void pickUpDropOff() { 

	set_servo_position(clawServoPort,maxClawRelease); //790 = default value to clench
	sleep(.5);  //pause before clench 
	
	
	set_servo_position(clawServoPort,0);
	sleep(1); //pause in between moving and clench
	
	moveArmUp();
	moveArmDown(dropHeight);
	
	sleep(1); 
	slowReleaseClench();
	sleep(1); 

	
	moveArmDown(-7700); //Test this value. needs to go all the awy down. 
}
void slowReleaseClench()
{
	while (x < maxClawRelease) {
		set_servo_position(clawServoPort, x); 

		x += increment; 
		sleep(.05); 
	}
}
