
int main()
{
	//for the left motor 
	/*clear_motor_position_counter(2);
	while(1){
		
		mav(2,100);
		
		if(get_motor_position_counter(2) >= 280){
			mav(2,0);
			break;
		}
	}*/
	
	//for the right servo
	set_servo_position(0,475);
	
	set_servo_position(0,1575);


}
