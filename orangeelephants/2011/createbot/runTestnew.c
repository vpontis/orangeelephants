#include "createConstants.h"
#include "runTestnew.h"

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
	
	while(get_motor_position_counter(0) <= nDistance) {
		sleep(0.1);
	}
	mav(armMotorPort,0);	
}

void pickUpDropOff() { 

	set_servo_position(clawServoPort,1174); //1174 = default value to clench
	sleep(1);  //pause inbetween clench 
	
	moveArmUp();
	moveArmDown(300);
	
	set_servo_position(clawServoPort,0); 
	
	moveArmDown(7700); //Value may be wrong 
}
