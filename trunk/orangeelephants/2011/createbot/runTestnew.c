void moveArm(int nPosVel, int nNegVel, int nDistance, int nMotor) {
	while ( digital(15) == 0 ) // port 15 is sensor number
	{
		mav(nMotor,nPosVel);
		if ( digital(15) == 1 )
		{mav(nMotor,0);break;}
	}
	
	
	sleep(1.5);  
	disable_servos(); 
	clear_motor_position_counter(0);
	while( get_motor_position_counter(0) >= nDistance ) {
		mav(0,nNegVel);
		if ( get_motor_position_counter(0) == nDistance )
		{mav(nMotor,0);break;}
	}
	//8500
}

void clenchClaw(int nServo, int nClench) { 

	set_servo_position(nServo,1174); //1174 = default value to clench
	
	enable_servos();
	disable_servos();
	sleep(1);  //pause inbetween clench 
	set_servo_position(nServo,nClench); 
	enable_servos();
	while (1) {
		set_servo_position(nServo,nClench);
		sleep(.5); 
		moveArm(750,-300,-8000,0); 
		break;
	}
}

int main()
{
	clenchClaw(2,240);
}
