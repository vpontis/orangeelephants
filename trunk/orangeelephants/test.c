/***************************************************************************
*********  This comment area should be filled with a description  
*********         of your program and what it does.               
***************************************************************************/
/* Libraries used in Botball are automatically included, but list any additional includes below */
/* #defines and constants go below.*/

/* Global variables go below (if you absolutely need them).*/

/*Function prototypes below*/

int main()
{
	lowerBlockerRight();
}

void lowerBlockerLeft(){ //lower left blocker and move forward 20 cm (subject to change)
	set_servo_position(2,1100);
	sleep(1);
	moveToDistance(20,200);
	sleep(1);
	//when blocker is vertical: position 1800 
	//when blocker hits the ground and is horizontal: position 650 
}

void lowerBlockerRight(){ //lower right blocker and move forward 20 cm (subject to change)
	set_servo_position(0,1575);
	sleep(1);
	moveToDistance(20,cmToTicks(20));
	sleep(1);
	//when blocker is vertical: position 450
	//when blocker hits the ground and is horizontal: position 1575
}


void moveToDistance(float distance, int speed) {
	mrp(0, speed, cmToTicks(distance)); //left wheel
	mrp(3, speed, cmToTicks(distance)); //right wheel
	bmdMotors();
}

float cmToTicks(float cmDistance) {                // return ticks the motors need to turn to go that distance
	return (float) (cmDistance * TICK_PER_CM);        
}

void bmdMotors() {     //wait until driving motors finish moving
	bmd(L_MOTOR);
	bmd(R_MOTOR);	
}
