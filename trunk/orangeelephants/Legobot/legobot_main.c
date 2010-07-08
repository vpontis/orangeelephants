#include "boolean.h"
#include "legobot_motor.c"
#include "legobot_constants.h"
#include "legobot_main.h"

/** \brief Legobot main will initialize, 
	prompt the user for different modes. 
   
	Asks user to callibrate the arm or to run the main
	code. For the main code, competition and testing mode
	is available.
*/

int main() {
	cbc_display_clear(); 
	set_each_analog_state(1,0,0,0,0,0,0,0);
	printf("Press A button to run code. \n Press B button for calibration. \n");
	while(1)
	{
		if(a_button()){//Gives prompts to run code.
			while(a_button()){
				sleep(.2);
			}
			printf("Press left button for non-competition mode. \n Press right button for competition mode. \n Press UP for neutral Arm\n");
			while(1){
				if(left_button()) {
					printf("Running testing mode");
					shut_down_in(130.0);
					runApp();       
					break;
				}
				if(right_button())   {
					printf("Running competition mode");
					competitionRunner(runApp, LIGHT_SENSOR_PORT); 
					//waitForTouch();//For waiting for either slot sensor or touch. 
					runApp();
					break;
				}
				sleep(.05);
			}
			break;
		}
		if(b_button())//Calibrate Arm 
		{
			while(digital(ARM_SENSOR_PORT) == 0)
			{
				mav(ARM_MOTOR,500);
			}
			mav(ARM_MOTOR,0);
			printf("Reset --> motor position counter = 0\n");
			clear_motor_position_counter(ARM_MOTOR);
			printf("Neutral arm\n");
			neutralArm();
			bmd(ARM_MOTOR);
			break;
		}                                            
	}
	//Rinse and repeat....
	ao();
}

/** \brief Calls method (runApp) that aligns ducks on green line 
	
	Used to create a modular code structure for testing.
*/
void runApp() {
	appPart1(); //Gets the first 4 clean ducks on the green line 
	appPart2(); //Gets the next 3 clean ducks on the green line  
}

/** \brief Part 1 of the Legobot execution

	Gets the legobot from staring position to the ducks. Gets the first row of 4 
	clean ducks, the ones farthest away, and puts them on the green line next to 
	the PVC. Ends with putting ducks on green line. 
*/
void appPart1() {
	//Begins Legobot functions
	//Legobot begins bearing 0 against the back PVC
	//Drives Legobot into clean duck PVC and picks up ducks
	//Bearings: 0 -> 90 
	/***************************************************************/
	sleep(4.0); //To wait for the Create to move
	moveToDistance(24, NORMAL_SPEED);//Drive forward
	turnSlow(83);//Turn towards PVC
	moveToDistance(11, NORMAL_SPEED);//Drive into PVC of clean duck center
	sleep(.5);
	clawOpen(); 
	duckGrabArm(); //Lower Arm
	bmd(ARM_MOTOR); 
	clawClose(); //Grab ducks
	sleep(.5);
	neutralArmSlow(); //Raises arm to pick ducks up across PVC
	bmd(ARM_MOTOR);
	sleep(.5);
	/***************************************************************/

	//Puts first 4 ducks on the green line
	//Backs up out of clean duck center, align against back PVC
	//Drive forwards to drop off ducks
	//Bearings: 90-> 0
	/***************************************************************/
	moveToDistance(-6, SLOW_SPEED); //Back up, old val -8, -7.5, -6.5
	turnSlow(-83); //Turn to allow back up into wall
	//moveToDistance(-32, SLOW_SPEED);
	moveStraight(-SLOW_SPEED);//Back up into wall
	sleep(8); //Prevents twitches
	//lookForColor(2, SLOW_SPEED, 3, 50, 50); For Camera, not being used
	//moveToDistance(-32, SLOW_SPEED);	
	moveToDistance(10, SLOW_SPEED); //Drive forwards to drop off ducks
	sleep(.5);
	duckGrabArm(); //Lower Claw 
	bmd(ARM_MOTOR); 
	clawOpen(); //Drop off ducks
	/***************************************************************/
}

/** \brief Part2 of the Legobot execution

	Alings with the PVC then gets the last row of 3 Clean Ducks and puts them on  
	the Green Line. Then gets out of the way for the create.
*/
void appPart2() {
	//Grabs second group of ducks
	//Puts up arm, goes forwards, turns to clean duck center
	//Runs into clean ducks center, picks up ducks
	//Bearings: 0 -> 90
	/***************************************************************/
	neutralArm();//Puts arm up again
	bmd(ARM_MOTOR);
	moveToDistance(13, SLOW_SPEED);//Moves forward to align with next ducks
	turnSlow(83);//Turns towards clean duck area
	moveToDistance(14, SLOW_SPEED); //Runs into PVC of clean duck area to align 
	moveToDistance(-11, SLOW_SPEED);//Backs up to get ducks 
	duckGrabArm(); //Lowers arm onto ducks
	sleep(.5);
	bmd(ARM_MOTOR);
	clawClose();//Grabs ducks
	sleep(.5);
	neutralArmSlow();//Picks up ducks
	bmd(ARM_MOTOR);
	/***************************************************************/
	
	//Puts second group of ducks on the green line
	//Backs up out of clean duck center, turn & backs up into back PVC
	//Drives forward and drops off ducks
	//Bearings: 90 -> 0
	/***************************************************************/
  	  moveToDistance(-15, SLOW_SPEED);//Backs up with ducks, -17.5, -16.5
	turnSlow(-80); //Turns to allow backup into PVC
	//moveToDistance(-32, SLOW_SPEED);
	moveStraight(-SLOW_SPEED);//Backs up into PVC
	sleep(8); //Prevents twitches
	//lookForColor(2, SLOW_SPEED, 3, 50, 50); For Camera, not being used
	//moveToDistance(-32, SLOW_SPEED);	
	moveToDistance(10, SLOW_SPEED);//Drives forward to drop off ducks
	sleep(.5);
	duckGrabArm(); //Lowers arm
	bmd(ARM_MOTOR);
	clawOpen();//Drops off ducks
	sleep(.5);
	/***************************************************************/
	
		
	//Gets the legobot out of the way for the create. 
	//Puts arm up, forward to avoid no-fly zone, runs into PVC at clean duck center
	//Bearings: 0 -> 90
	/***************************************************************/
	neutralArmSlow();//Puts arm up
	bmd(ARM_MOTOR);

	//Getting away option 1
	/***************************************************************/
	moveToDistance(14, NORMAL_SPEED);//Goes forwards a little bit to avoid turning into no-fly zone 
	turn(63);
	moveToDistance(36, NORMAL_SPEED); //Drives into PVC at clean duck center
	/***************************************************************/
	
	clawOpen(); 
	duckGrabArm(); //Lower Arm
	bmd(ARM_MOTOR); 
	clawClose(); //Grab ducks
	sleep(.5);
	neutralArmSlow(); //Raises arm to pick ducks up across PVC
	bmd(ARM_MOTOR);
	sleep(.5);

	moveToDistance(-6, SLOW_SPEED); //Back up, old val -8, -7.5, -6.5
	turnSlow(-83); //Turn to allow back up into wall
	//moveToDistance(-32, SLOW_SPEED);
	moveStraight(-SLOW_SPEED);//Back up into wall
	sleep(8); //Prevents twitches
	//lookForColor(2, SLOW_SPEED, 3, 50, 50); For Camera, not being used
	//moveToDistance(-32, SLOW_SPEED);	
	//moveToDistance(10, SLOW_SPEED); //Drive forwards to drop off ducks
	//sleep(.5);
	//duckGrabArm(); //Lower Claw 
	//bmd(ARM_MOTOR); 
	ao();
}

/** \brief Runs a method after waiting for light. 
	\param func Replace with function you want to run
	\param lightPort Replace with port of light sensor. 
*/
int competitionRunner(int(*func)(), int lightPort)	{
    printf("Competition Runner Initiated\n");
    printf("Waiting for light port: x%d\n", lightPort);
    wait_for_light(lightPort);
    shut_down_in(130.0);
    printf("Light Found, Running Func\n");
    return func();
}
