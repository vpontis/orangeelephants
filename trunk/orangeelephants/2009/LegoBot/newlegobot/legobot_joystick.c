/**
	\file legobot_joystick.h
	\date Feb 2, 2009
	\author Mark Allen Vismonte
	\brief This file uses the joystick
	
	Used to run the LegoBot with the controller we made.
*/
#include "legobot_motor.c"
#include "legobot_sensor.c"
#include "legobot_joystick.h"
#include "boolean.h"

/** \brief Runs the main program for the LegoBot.
	
	The main of the Legobot
	Runs serveral test programs depending on which button you press
	There are up,right,down,and left for the joystick and for the
	touch screen on the CBC
	The A and B buttons as well as the black button are also used
	to choose programs
*/
int run_joystick() 
{
	boolean competitionMode = false;
	int lightPort = 12;
	printf("Competition Mode? A = Yes B = No\n");
	while (!(a_button() || b_button()))
		msleep(100L);
	competitionMode = a_button();
	while (a_button() || b_button())
		msleep(100L);
	cbc_display_clear();
	printf("Legobot Main Menu\n");
	printf("Competition Mode: ");
	if (competitionMode)
		printf("On\n");
	else
		printf("Off\n");
	printf("Up - Joystick\n");
	printf("Right - Square dance\n");
	printf("Down - Distance test\n");
	printf("Left - Turn test\n");
	printf("Black button - Servo Position Test\n");
	printf("A button - Arc test\n");
	printf("B button - Check voltage\n");
	printf("Virtual up - Go to Slope\n");
	printf("Virtual down - Test Motor Ice\n");
	printf("Virtual left - Test Black Line Searcher and Follower\n");
	printf("Virtual right - Black Line Value Reader\n");
	while (!(JOYPAD_UP | JOYPAD_RIGHT | JOYPAD_DOWN | JOYPAD_LEFT | black_button() | a_button() | 
		b_button() | up_button() | down_button() | left_button() | right_button())) 
	{
		msleep(100L);
	}
	if (JOYPAD_UP) 
	{
		return competitionMode? competition_runner(do_joystick, lightPort): do_joystick();
	}
	if (JOYPAD_RIGHT) 
	{
		return competitionMode? competition_runner(do_square_dance, lightPort): do_square_dance();
	}
	if (JOYPAD_DOWN) 
	{
		return competitionMode? competition_runner(do_distance_test, lightPort): do_distance_test();
	}
	if (JOYPAD_LEFT) 
	{
		return competitionMode? competition_runner(do_turn_test, lightPort): do_turn_test();
	}
	if (black_button())
	{
		return competitionMode? competition_runner(do_servo_position_test, lightPort): do_servo_position_test();
	}
	if (up_button())
	{
		return competitionMode? competition_runner(go_to_slope, lightPort): go_to_slope();
	}
	if (a_button())
	{
		return competitionMode? competition_runner(do_arc_test, lightPort): do_arc_test();
	}
	if (left_button())
	{
		return competitionMode? competition_runner(black_line_searching_and_following, lightPort): 
			black_line_searching_and_following();
	}
	if (right_button())
	{
		return black_value_test();
		return competitionMode? competition_runner(black_value_test, lightPort): black_value_test();
	}
	if (b_button())
	{
		printf("Power level: %f\n", power_level());
		printf("Press A to continue\n");
		while (!a_button())
			sleep(5L);
		cbc_display_clear();
		return run_joystick();
	}
	if (down_button())
	{
		return competitionMode? competition_runner(test_freeze, lightPort): test_freeze();
	}
	return 0;
}

/** \brief Tests the freeze method.
	
	A Function that tests the freeze functionality
	\see ice
	\see legobot_motor.h
*/
int test_freeze()
{
	printf("Press up to exit\n");
	boolean frozen = true;
	int id;
	while (!JOYPAD_UP)
	{
		if (JOYPAD_LEFT || JOYPAD_RIGHT)
		{
			printf("Toggled Freeze\n");
			if (frozen)
			{
					doIce = true;
					id = start_process(ice);
					frozen = false;
					printf("id = %d, frozen = %d\n",id,frozen);
			}
			else
			{
					printf("Killing process: %d\n", id);
					doIce = false;
					kill_process(id);
					turn_off();
					frozen = true;
			}
				//speeds until both left and right are released
				while (JOYPAD_LEFT || JOYPAD_RIGHT)
					msleep(5L);
		}
	}
	printf("Done testing\n");
	return 0;
}

/** \brief This allows to use the LegoBot with the controller.
	
	A very very helpful method that allows us to drive the Legobot around
	It allows us to see the legobot do its proper task 
	with a human companion
	It is very help in programming the Legobot
*/
int do_joystick()
{
	boolean isGoingUp = false;
	boolean isGoingRight = false;
	boolean isGoingDown = false;
	boolean isGoingLeft = false;
	boolean isOff = true;
	while(!b_button())
	{
		if(JOYPAD_UP)
		{
			if(!isGoingUp)
			{
				move(JOYSTICK_SPEED, JOYSTICK_SPEED);
				isGoingUp = true;
				isOff = false;
				printf("up\n");
			}
		}
		
		else if(JOYPAD_RIGHT)
		{
			if(!isGoingRight)
			{
				move(JOYSTICK_SPEED, -JOYSTICK_SPEED);
				isGoingRight = true;
				isOff = false;
				printf("right\n");
			}
		}
		
		else if(JOYPAD_DOWN)
		{
			if(!isGoingDown)
			{
				move(-JOYSTICK_SPEED, -JOYSTICK_SPEED);
				isGoingDown = true;
				isOff = false;
				printf("down\n");
			}
		}
		
		else if(JOYPAD_LEFT)
		{
			if(!isGoingLeft)
			{
				move(-JOYSTICK_SPEED, JOYSTICK_SPEED);
				isGoingLeft = true;
				isOff = false;
				printf("left\n");
			}
		}
		
		else
		{
			if(!isOff)
			{
				turn_off();
				printf("STOP\n");
				isGoingUp = false;
				isGoingRight = false;
				isGoingDown = false;
				isGoingLeft = false;
				isOff = true;
			}
		}
	}

return 0;	
}

/** \brief Turns the LegoBot in a square.
	
	A simple turn test that makes a square until the b button is hit
*/
int do_square_dance() 
{
	int i;
	while (!b_button()) 
	{
		for (i = 0; i < 4; i++) 
		{
			move_distance(100.0);
			sleep(1);
			turn(90.);
			sleep(1);
			turn_off();
		}
	}
	return 0;
}

/** \brief Drives the legobot to the opposing slope.
*/
int go_to_slope()
{
	//I want revision 200
	int id = 0;
	printf("Starting Total Time: %f\n", seconds());
	lock_arms();
	move_direct_distance(RAMP_DEPART_SPEED, 750.0);
	black_line_searching_and_following();
	printf("Moving backwards %f mm\n", 80.0);
	move_direct_distance(500, -90.0);
	turn(95.0);
	printf("Turning %f degrees\n", 95.0);
	move_direct_distance(500.0 , 50.0);
	msleep(100L);
	release_arms();
	move_direct_distance(500.0 , -50.0);
	move_direct_distance(500.0 , 50.0);
	move_direct_distance(500.0 , -50.0);
	doIce = true;
	id = start_process(ice);
	disable_servos();
	printf("Moving Forward to snug into space\n");
	printf("Done\n Total Time: %f\n", seconds());
	return 0;
}

/** \brief Tests the arcing function.
	
	A test method that is used to test arcing functionality
	Using the joypad, the user can choose the outer radius
	outer velocity, left or right arc, and the distance to be 
	travelled by the outer wheel
*/
int do_arc_test()
{
	float outerRadius = 300.0, move_distance;//starting outerRadius
	int outerVelocity = 150;
	boolean leftArc = true;
	while (!b_button())
	{
		printf("Choosing outer radius, press up to continue\n");
		while (!JOYPAD_UP)
		{
			if (JOYPAD_LEFT)
				{
					outerRadius -= 100.0;
					printf("Outer radius changed to %f\n",outerRadius);
					msleep(250L);
				}
			if (JOYPAD_RIGHT)
				{
					outerRadius += 100.0;
					printf("Outer radius changed to %f\n",outerRadius);
					msleep(250L);
				}
		}
		while (JOYPAD_UP)
			msleep(5L);
		printf("Choosing outer velocity, press up to continue\n");
		while (!JOYPAD_UP)
		{
			if (JOYPAD_LEFT)
				{
					outerVelocity -= 100;
					printf("Outer velocity changed to %d\n",outerVelocity);
					msleep(250L);
				}
			if (JOYPAD_RIGHT)
				{
					outerVelocity += 100;
					printf("Outer velocity changed to %d\n",outerVelocity);
					msleep(250L);
				}
		}
		while (JOYPAD_UP)
			msleep(5L);
		printf("Press left to do left arc, right to do right arc\n");
		while (!(JOYPAD_LEFT || JOYPAD_RIGHT))
			msleep(100L);
		leftArc = JOYPAD_LEFT;
		if (leftArc)
			printf("Left arc is true\n");
		else
			printf("Right arc is true\n");
		move_distance = outerRadius * PI;
		turn_arc(leftArc, outerRadius, outerVelocity, move_distance);
		printf("Finished Arcing\n");
	}
	return 0;
}

/** \brief Tests the \ref move_direct_distance method.
	
	A test program that tests the method move_direct_distance
	The user chooses the distance in millimeters to be travelled
*/
int do_distance_test() 
{
	float distance = 800.0;
	printf("Press up and down to alter distance, right or left to start");
	while (!b_button())
	{
		while (!(JOYPAD_RIGHT || JOYPAD_LEFT))
			{
			if (JOYPAD_UP)
				{
				distance += 10.;
				printf("Set Distance: %f\n",distance);
				msleep(250L);
				}
			if (JOYPAD_DOWN)
				{
				distance -= 10.;
				printf("Set Distance: %f\n", distance);
				msleep(250L);
				}
			}
			printf("Starting Move\n");
			move_direct_distance(1000, distance);
			printf("Done Moving\n");
	}
	return 0;
}

/** \brief Tests the turning of the LegoBot.
	
	A method that tests the turning functionality of the Legobot
	The user chooses the amount of degrees (+ or -) that he wants
	the robot to move and then calls the turn method to turn the
	Legobot.
*/
int do_turn_test()
{
	while (!b_button())
	{
		float degrees = 90;
		printf("Press A to start\n");
		while (!a_button())
		{
			msleep(250L);
			if (JOYPAD_LEFT)
			{
			degrees = degrees + 45.;
			printf("Degrees to Turn: %f\n",degrees);
			}
			if (JOYPAD_RIGHT)
			{
			degrees = degrees - 45.;
			printf("Degrees to Turn: %f\n",degrees);
			}
		}
		printf("Starting to turn\n");
		turn(degrees);
		printf("Done turning\n");
		}
	return 0;
}

/** \brief Tests the dropping of the arms.
	
	A test functions that tests the dropping of the arms
	but moving the servo postion to remove the locking pin
*/
int drop_arms()
{
	enable_servos();
	set_servo_position(2,2047);
	set_servo_position(1, 0);
	printf("Press A to deploy\n");
	while (!a_button())
		msleep(100L);
	set_servo_position(2,100);// release point is 100
	set_servo_position(1, 1500);// release point is 1500
	msleep(1000L);
	disable_servos();
	printf("Arms deployed\n");
	return 0;
}

/** \brief Helps test servo positions for arms or other servo mounted accesories.
	
	A test function that will be helpful on ANY CBC because it 
	allows the user to find servo positions easily using the JOYPAD
	The user is allowed to choose the servo he uses to test
	after choosing the servo, the servos are enabled
	and by using the left and right buttons on the JOYPAD,
	he can move the servo position left and right.
*/
int do_servo_position_test()
{
	int servo = 1, i;
	int position = 2047;
	disable_servos();
	while (!b_button())
	{
		printf("Choose servo, press up to continue\n");
		while (!JOYPAD_UP)
		{
			if(JOYPAD_LEFT)
				{
				servo = f_max(servo - 1, 1);
				printf("Servo: %d\n", servo);
				msleep(1000L);
				}
			if(JOYPAD_RIGHT)
				{
				servo = f_min(servo + 1, 4);
				printf("Servo: %d\n", servo);
				msleep(1000L);
				}
			if (JOYPAD_DOWN)
				{
					return drop_arms();
				}
		}
		enable_servos();
		for (i = 1; i <= 4; i++)
			set_servo_position(i, 0);
		printf("Test starting, press down to stop\n");
		position = get_servo_position(servo);
		while (!JOYPAD_DOWN)
		{
			if(JOYPAD_LEFT)
				{
				position = get_servo_position(servo);
				printf("Position: %d\n", position);
				set_servo_position(servo, position - 10);
				msleep(50L);
				}
			if(JOYPAD_RIGHT)
				{
				position = get_servo_position(servo);
				printf("Position: %d\n", position);
				set_servo_position(servo, position + 10);
				msleep(50L);
				}
		}
		disable_servos();
		printf("Test end\n");
	}
	return 0;
}

/** \brief Searches and Follows Black line
*/
int black_line_searching_and_following()
{
	printf("Black Line Searcher + Follower Started\n");
	float secs = seconds();
	boolean lastValues[3] = {0, 0, 0}, currentValues[3] = {0, 0, 0};
	boolean isFollowingLine = false, bothBlack = false;
	printf("Searching for black line\n");
	turn_arc_at_velocity(false, 6800.0, BLACK_LINE_SEARCH_OUTER_VELOCITY);
	
	//searching for line
	while(!isFollowingLine)
	{
		currentValues[0] = is_left_black();
		currentValues[1] = is_center_black();
		currentValues[2] = is_right_black();
	
		int currentState = current_state(currentValues);
		int lastState = current_state(lastValues);
		
		printf("State is:%d\n", currentState);
		printf("Last state was:%d\n\n", lastState);
		printf("Center reading: %d\n", get_center_ir_sensor());
		
		if(lastState == currentState)
		{
			//do nothing different.
			printf("Center reading: %d\n", get_center_ir_sensor());
		}
		else if(currentState == FFF)
		{
			printf("THIS STATEMENT SHOULD NOT PRINT\n");
			turn_arc_at_velocity(false, 7300.0, 1000);
			lastValues[0] = false;
			lastValues[1] = false;
			lastValues[2] = false;
		}
		else if(is_center_black())
		{
			printf("WOW CENTER\n");
			if(lastState == FFF)
			{
				printf("FOLLOWING LINE\n");
				turn_off();
				isFollowingLine = true;
			}
			lastValues[0] = false;
			lastValues[1] = true;
			lastValues[2] = false;
		}
		msleep(100L);
	} //found the line

	//on line, following it
	while (!bothBlack)
	{
		printf("Left: %d Center: %d Right: %d\n", get_left_ir_sensor(), 
			get_center_ir_sensor(), get_right_ir_sensor());
		
		if (both_on_black_line())
		{
			printf("Exiting, Two on black line\nLeft: %d Center: %d Right: %d\n", get_left_ir_sensor(), 
				get_center_ir_sensor(), get_right_ir_sensor());
			bothBlack = true;
		}
		else if(is_left_black())
		{
			printf("Should be turning CCW\n");
			move(-BLACK_LINE_FOLLOWING_CORRECTION_VELOCITY, 
				BLACK_LINE_FOLLOWING_CORRECTION_VELOCITY);
			while(is_left_black())
				msleep(15L);
		}
		else if(is_right_black())
		{
			printf("Should be turning CW\n");
			move(BLACK_LINE_FOLLOWING_CORRECTION_VELOCITY, 
				-BLACK_LINE_FOLLOWING_CORRECTION_VELOCITY);
			while(is_right_black())
				msleep(15L);
		}
		else if(!is_left_black() && !is_right_black())
		{
			move(BLACK_LINE_FOLLOWING_STRAIGHT_VELOCITY, 
				BLACK_LINE_FOLLOWING_STRAIGHT_VELOCITY);
			printf("Going Straight\n");
			while (!is_left_black() && !is_right_black())
				msleep(15L);
		}
		else
			printf("Confused\tLeft: %d Center: %d Right: %d\n", get_left_ir_sensor(), 
				get_center_ir_sensor(), get_right_ir_sensor());
		msleep(50L);
	} //end black line following.
	return 0;
}

/** \brief Finds the current state using boolean values
	\param currentValues[] the three values of the sensors
*/
int current_state(boolean currentValues[])
{
	if(currentValues[0] == true)
	{
		if(currentValues[1] == true)
		{
			if(currentValues[2] == true)
			{
				return TTT;
			}
			else if(currentValues[2] == false)
			{
				return TTF;
			}
		}
		else if(currentValues[1] == false)
		{
			if(currentValues[2] == true)
			{
				return TFT;
			}
			else if(currentValues[2] == false)
			{
				return TFF;
			}
		}
	}
	else if(currentValues[0] == false)
	{
		if(currentValues[1] == true)
		{
			if(currentValues[2] == true)
			{
				return FTT;
			}
			else if(currentValues[2] == false)
			{
				return FTF;
			}
		}
		else if(currentValues[1] == false)
		{
			if(currentValues[2] == true)
			{
				return FFT;
			}
			else if(currentValues[2] == false)
			{
				return FFF;
			}
		}
	}
}

/** \brief Helps tests the Top Hat sensors.
*/
int black_value_test()
{
	printf("Press B Button to Start Reading Values\n");
	while(!b_button())
		msleep(100L);
	while(!a_button())
	{
		printf("Left: %d Center: %d Right: %d\n", get_left_ir_sensor(), 
			get_center_ir_sensor(), get_right_ir_sensor());
		msleep(100L);
	}
	printf("Done\n");
	return 0;
}

/** \brief The competition runner method for the competition
	\param (*func)() the name of the function wished to be implemented
	\param lightPort the port that the function should look for with regards to light
*/
int competition_runner(int(*func)(), int lightPort)
{
	printf("Competition Runner Initiated\n");
	printf("Waiting for light port: %d\n", lightPort);
	wait_for_light(lightPort);
	shut_down_in(115.0);
	printf("Light Found, Running Func\n");
	return func();
}
