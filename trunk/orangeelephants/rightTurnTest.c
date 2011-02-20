void turnLeft();
void turnRight();
void turn();

int main()
{	
	printf("PRESS A FOR LEFT TURN, B FOR RIGHT TURN");
	
	while(1){
		if(a_button() == 1){
			turn(500,-90);
		}
		
		if(b_button() == 1){
			turn(500,90);
		}
	}	
}

/*void turnRight(int speed, int degree){
	
	int ticks = degree*9.564;
	
	while(1){
		mav(3,speed);
		mav(0,-speed);
	
		if(get_motor_position_counter(3) >= ticks){
			clear_motor_position_counter(3);
			clear_motor_position_counter(0);
			mav(rightWheel,0);
			mav(leftWheel,0);
			break;
		}
	}
}

void turnLeft(int speed, int degree){
	
	int ticks = degree*9.564;
	while(1){
		mav(0,speed);
		mav(3,-speed);
		
		if(get_motor_position_counter(0) >= ticks){
			clear_motor_position_counter(3);
			clear_motor_position_counter(0);
			mav(3,0);
			mav(0,0);
			break;
		}
	}
}*/





/*Turns the Legobot a certain degree, a negative degree will result in a left turn
  while a positive degree will result in a right turn.
  The turn also pivots the robot.
  
	axle is 13.75 cm
	3.14159c * 2 * 13.75 = circumference
	1/4 of circumference = 21.60
	21.60 * 79.7ticks = 1721.52     CAUSED A 180 DEG TURN
	860.76							CAUSED A 90 DEG TURN
	
	/*************** 9.564 ticks per degree **************
				LEFT/RIGHT FROM THE BACK OF THE ROBOT   */
				
void turn(int speed, int degree){
	
	int ticks = degree*9.564;
	//right turn
	if(degree > 0){
		while(1){
			mav(3,speed);
			mav(0,-speed);
			
			if(get_motor_position_counter(3) >= ticks){
				clear_motor_position_counter(3);
				clear_motor_position_counter(0);
				mav(3,0);
				mav(0,0);
				break;
			}
		}
	}
	
	//left turn
	if(degree < 0){
		while(1){
			mav(0,speed);
			mav(3,-speed);
			//neg. ticks so that the motor_position remains positive
			if(get_motor_position_counter(0) >= -ticks){
				clear_motor_position_counter(3);
				clear_motor_position_counter(0);
				mav(3,0);
				mav(0,0);
				break;
			}
		}
	}	
}
