void moveArm(int nVel, int nDistance, int nMotor) {
	while ( digital(15) == 0 ) // port 15 is sensor number
	{
		mav(nMotor,nVel);
		if ( digital(15) == 1 )
		{mav(nMotor,0);break;}
	}
	
	sleep(1.5); 
	clear_motor_position_counter(0);
	while( get_motor_position_counter(0) >= nDistance ) {
		mav(0,-nVel);
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
	set_servo_position(nServo,nClench);
	while ( digital(15) == 0 )
	{
		moveArm(750,-8000,0);
		if ( digital(15) == 1 ) {
		disable_servos(); 
		break;
		}
	}
	disable_servos(); 
}

int main()
{
	clenchClaw(2,285);
}
