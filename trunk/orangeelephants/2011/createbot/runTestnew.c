#include "createConstants.h"
#include "runTestnew.h"

int main()
{
	printf("Press A button to run program \n");
	printf("Press UP to raise arm. Press DOWN to callibrate and to lower arm \n");
	while(1)
	{
		if(a_button())//Gives prompts to run code.
		{
			pickUpDropOff();
			sleep(1);
			break;
		}
		else if(up_button())
		{
			moveArmUp();
		}
		else if(down_button())
		{
			moveArmUp();
			moveArmDown(armPosDown);
		}        
	}
	
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

	set_servo_position(clawServoPort,clawOpenPos); //790 = default value to clench
	sleep(.5);  //pause before clench 
	
	
	set_servo_position(clawServoPort,0);
	sleep(1); //pause in between moving and clench
	
	moveArmUp();
	moveArmDown(armPartialDown); //goes down -8300+7800
	
	sleep(1); 
	slowReleaseClaw();
	sleep(1); 

	moveArmDown(armPosDown - armPartialDown); //Test this value. needs to go all the awy down. 
}
void slowReleaseClaw()
{	
	int clawPos = get_servo_position(clawServoPort); 
	int clawPosIncrement = clawOpenPos/10; 
	
	while (clawPos < clawOpenPos) {
		set_servo_position(clawServoPort, clawPos); 
		clawPos += clawPosIncrement; 
		sleep(.05); 
	}
}
