//Moves the demobot arm to the middle position
int main()
{
	int upPos, downPos, middlePos;
	printf("Press Black Button to start\n");
	while(!black_button()); while(black_button());// press & release
	set_servo_position(4,1023);// set servo position for miidle
	enable_servos();//turn on servos
	motor(3,50);//start arm up
	while(!digital(0) && !black_button()){//dig 0 is up sensor
		msleep(10);
	}
	off(3);
	upPos = get_motor_position_counter(3);
	while(black_button()){}//if pressed, wait for release
	motor(3,-50);//start arm down
	while(!digital(1) && !black_button()){// dig 1 is down sensor
		msleep(10);
	}
	downPos = get_motor_position_counter(3);
	off(3);
	while(black_button()){}//if pressed, wait for release
	middlePos = (upPos - downPos)/2 + downPos;
	motor(3,50);//start arm back up to the middle
	while(!black_button()){//black button in an emergency
		// is the arm halfway between the down and up pos?
		if(get_motor_position_counter(3) > middlePos){
			off(3);//stop motor
			printf("At the middle position\n");
			break;// jump out of while loop
		}
		printf(" At %d moving to %d\n",get_motor_position_counter(0),middlePos);
		msleep(10);//Don't print too fast
	}
	ao(); disable_servos();// all motors and servos off
	printf("Program finished\n");
	return 0;
}
		
		
		
