#include "boolean.h"
#include "legobot_motor.c"
#include "legobot_constants.c"

//INSTRUCTIONS TO RUN CODE: MOVE THE ARM MANUALLY DOWN ABOUT 2-3 TWISTS. THEN RUN THE CODE AND PRESS THE BLACK BUTTON. THEN RUN THE CODE AGAIN AND PRESS A AND THEN HIGH-FIVE PRABHAV FOR BEING AN AWESOME CODER.
float startTime;

void runApp();
void appPart1(); //up until first collision with pvc in the middle 
void appPart2(); //everything else
void lowerArm(); //lowers arm
void neutralArm(); //tilts arm to neutral position
void raiseArm(); //raises arm
void lowNeutralArm();
void highNeutralArm();
void moveToWall(int speed);
void clear_motor();
void lowerArmForSweep();
void sweepNeutralArm();
void competitionMode();
void lookForColor(int colorModel, int speed, int numBlobSightings, float delay, float distOut, int cmBackup);
void lookForColorFirstGreen(int colorModel, int speed, int numBlobSightings, float delay, float distOut, int cmBackup);
int competitionRunner();
int nonCompetitionRunner();
int waitForTouch();
int otherFunction();

int legobot_main() {
				printf("Press A button to run code. \n Press B button for calibration. \n");
                while(1)
                        {
                                if(up_button())
                                {
                                                while(1)
                                                {
                                                        printf("Release button pressed. \n");
                                                        mav(0,500); 
                                                        sleep(.1);
                                                        if(up_button())
                                                        {
                                                                mav(0,0);       
                                                                sleep(.05);
                                                                break;
                                                        }
                                                }
                                  }
                                 /*if(black_button())
                                 {
                                 printf("Neutral arm\n");
                                 neutralArm();
                                 }*/
                                if(a_button()){
									while(a_button()){
										sleep(.2);
									}
									printf("Press left button for non-competition mode. \n Press right button for competition mode. \n");
									while(1){
										if(left_button()) {
											printf("Running testing mode");
											shut_down_in(116.0);
											sleep(40);
											runApp();       
											break;
										}
										if(right_button())   {
											printf("Running competition mode");
											//competitionMode(); //Old competition thing 
											set_each_analog_state(1,0,0,0,0,0,0,0);
											//competitionRunner();
											waitForTouch();
											break;
										}
										sleep(.05);
									}
									break;
                                }
                                
                                if(b_button())
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

void runApp() {
		clear_motor();
        appPart1(); //up until first collision with pvc in the middle 
		otherFunction();
        appPart2(); //everything else
}

void competitionMode() {
		set_each_analog_state(1,0,0,0,0,0,0,0);
		wait_for_light(LIGHT_SENSOR_PORT);
		runApp();
}



void appPart1() {
		//clear_motor_position_counter(0); //Assumes that the arm starts pointing straight up
        //cbc_display_clear();
        set_each_analog_state(1,0,0,0,0,0,0,0);
		startTime = seconds();
        turn(168);
        moveToDistance(15, FAST_SPEED);
        stopMovement();
		moveStraight(300);
        //mtp(ARM_MOTOR,1000,-5100);
        lowerArm(); //-5300 predetermined by using motor test screen.
        bmd(ARM_MOTOR); 
        //After arm is down, move backwards
        moveStraight(-600);
        sleep(2);
        lowNeutralArm();
        //While bot is going in reverse, move the arm up slightly
	
        //mtp(ARM_MOTOR, 1000, -4216);
        //mtp(ARM_MOTOR, 1000, -1900);
        //mtp(ARM_MOTOR, 1000, -5500+MODIFIER);
        sleep(2);
        //Keep moving the arm up more.
        //mtp(ARM_MOTOR, 1000, -2000);
        bmd(ARM_MOTOR);
        //while arm is moving up, keep backing up
        sleep(2);
        stopMovement();
        moveToDistance(5, FAST_SPEED);
        //mtp(ARM_MOTOR,1000, -600);
        neutralArm(); //        mtp(ARM_MOTOR, 1000, -3700+MODIFIER);  changed to -3600
        bmd(ARM_MOTOR);
        //against pvc at this point
        //forward
        moveToDistance(5, FAST_SPEED);
        //arcing right 
        turn_arc_sweep(FALSE,500, 400, 25);
        //arcing left
        turn_arc_sweep(TRUE,200, 400, 40); 
		
        moveToDistance(14, FAST_SPEED);
        lookForColorFirstGreen(2, 100, 3, 0.05, 12, -8.5); //old value: 14
        printf("Green Detected\n");
        stopMovement();
		lowNeutralArm();
		bmd(ARM_MOTOR);
        //mtp(ARM_MOTOR, 1000, -1500);//put down crane so it can pull ducks back
        
        moveToDistance(-30.25, (NORMAL_SPEED-150) );//back up and align ducks on green line
}
		
int otherFunction()
{
        //mtp(ARM_MOTOR, 1000, -500);//put crane back up
        neutralArm();
        bmd(ARM_MOTOR);
        moveToDistance(-5, FAST_SPEED);
        turn(-82);
        
        moveToWall(FAST_SPEED);
        
        moveStraight(-FAST_SPEED);
        
        moveToDistance(-15, FAST_SPEED);
        turn(92);
        
        lookForColor(0, NORMAL_SPEED, 3, 0.05, 76.5, -10); //3400 ticks is equivalent to 85cm
        printf("Found Orange");//Keep going straight until Orange line is found
		
        //raiseArm(); //raises arm
        highNeutralArm();
        //move across board to center PVC
		moveToDistance(-5,FAST_SPEED);
		turnArc(FALSE, 20, FAST_SPEED, 88);
        //turn(91);       
        moveToDistance(120, NORMAL_SPEED);
  
        //forward until hits center pvc for first time
        moveToWall(FAST_SPEED);
        stopMovement();
        sleep(0.2);
        

}



//initial value for arm is 3 revolutions down
void clear_motor()
{

        //clear_motor_position_counter(ARM_MOTOR);
        cbc_display_clear();
}

void appPart2() {
				
				
				//back up form first pvc pipe and turn 90 degrees to the left
                
                moveToDistance(-5, FAST_SPEED);               
                turn(-90);  

				//move arm to neutral position
                neutralArm();
				
				
                //back up until the robot is aligned with the pvc pipe
                sleep(0.05);
                int backUpSpeed = 500;
                moveToDistanceTurn(-92, FAST_SPEED+15, FAST_SPEED-15); //make slight arc while backing up into PVC      
				//moveToDistance(-92, backUpSpeed);      
			    //move forward a turn 90 degrees to the left and align with the pvc pipe	
			    moveToDistanceTurn(3, FAST_SPEED, FAST_SPEED); //move forward a little so it can take a turn  
                turn(-90);
				
				
                moveToWall(FAST_SPEED);//running into the wall until touch sensors triggered
              /*  while((seconds()-startTime)<60)
				{
					printf("Waiting \n");
				}*/
                //moveToDistance(-7, FAST_SPEED);
				//move to the next pvc pipe and turn 180 degrees
                /*moveToDistance(-40, NORMAL_SPEED);
				turn(-190);  */
				turnArc(TRUE, -55, FAST_SPEED, 27);//going backwards to prepare for sweep
				//lower arm to prepare for sweeping and back up
                //moveToWall(FAST_SPEED);
				moveToDistance(-33, FAST_SPEED);
				
				turn(-50);
				lowerArmForSweep();//higher arm while turning, uses ARM_ISLAND_SWEEP
				turn(-130);
				bmd(ARM_MOTOR);
				
				moveStraight(FAST_SPEED);
				while(digital(RIGHT_TOUCH_PORT) == 0)
				{
					sleep(0.05);
				}
				
				//Sweep items off of Karel Island
               // moveToDistance(-5, FAST_SPEED);      
                turnArc(TRUE, -20.8, FAST_SPEED, 50);//Main changing value, 21.5
				
				
				moveToDistance(-30, FAST_SPEED);
				
				
				//do an initial turn and then sweep
                //turn(65);
                /*turnArc(TRUE, 45, FAST_SPEED, 115); 
				
				//back up
                moveToDistance(-25,FAST_SPEED);
				
				//move forward and turn 270 degrees
                moveToDistance(5, FAST_SPEED);
                turn(270);
				
				//move to wall to align and then turn 90 degrees
				*/
				
               // moveToDistance(6,FAST_SPEED);
				//move forward and turn 270 degrees
                moveToDistance(7, FAST_SPEED);	
                turn(75);
				
				mav(L_MOTOR, FAST_SPEED - 15);//-40
				mav(R_MOTOR, FAST_SPEED+15);//35
				while(digital(LEFT_TOUCH_PORT) == 0 || digital(RIGHT_TOUCH_PORT) == 0) {
                        sleep(0.5);
                }
				sleep(.25);
				stopMovement();
				
				moveToDistance(-10.5, FAST_SPEED);//Has to add up absolute value with the code 3 lines below to 45
				turn(-188);
				neutralArm();
				moveToDistanceTurn(34.5, FAST_SPEED-10, FAST_SPEED);
				turnArc(FALSE, 25, FAST_SPEED, 90);
               
				
				//move forward before beginning to arc
				moveToDistance(12,FAST_SPEED);//Old value 18  
				
				//arc
				//turnArc(TRUE, 70, FAST_SPEED, 160); 
				turnArc(TRUE, 35, FAST_SPEED, 85);
				moveToDistance(60.5, FAST_SPEED);
				sweepNeutralArm();
				turnArc(TRUE, 25, FAST_SPEED, 85);
				//turn(-7);
				moveToDistance(7, FAST_SPEED);
				//move forward and then look for the green line
			
				//void lookForColor(int colorModel, int speed, int numBlobSightings, float delay, float distOut, int cmBackup);
				lookForColor(2, NORMAL_SPEED, 3, 0.05, 85, -5); //1024 ticks is equal to 25.6 centimeters on the distOut command 
				printf("Green Detected\n"); 
				bmd(ARM_MOTOR);
				moveToDistance(-35, NORMAL_SPEED);//back up and align ducks on green line
				//printf{"Finished running through main code \n");
       
                
}
void lowerArm() {
        mtp(ARM_MOTOR, TILT_SPEED, ARM_DOWN + MOTOR_OFFSET);
}

void raiseArm() {
        mtp(ARM_MOTOR, TILT_SPEED, ARM_UP + MOTOR_OFFSET);       //no MODIFIER?
}

void lowNeutralArm() {
        mtp(ARM_MOTOR, TILT_SPEED,  ARM_LOW_NEUTRAL + MOTOR_OFFSET);
}
void highNeutralArm() {
        mtp(ARM_MOTOR, TILT_SPEED, ARM_HIGH_NEUTRAL + MOTOR_OFFSET);
}
void sweepNeutralArm() {
        mtp(ARM_MOTOR, TILT_SPEED, ARM_SWEEP_NEUTRAL + MOTOR_OFFSET);
}

void neutralArm() {
        mtp(ARM_MOTOR, TILT_SPEED, ARM_NEUTRAL + MOTOR_OFFSET);
}

void lowerArmForSweep()
{
        mtp(ARM_MOTOR, TILT_SPEED, ARM_ISLAND_SWEEP + MOTOR_OFFSET);
}


void moveToWall(int speed) {
        moveStraight(speed);
        int nowTime=seconds();
		int timedOutTime=seconds();
		//int rInitMotorPosit = get_motor_position_counter(R_MOTOR); //motors cannot be going backwards
        //int lInitMotorPosit = get_motor_position_counter(L_MOTOR);
		//int lElapseMotorPosit = 0;
		//int rElapseMotorPosit = 0;
		//int elapsedDist = 0;
		while(1) {
			if(digital(LEFT_TOUCH_PORT) == 1 || digital(RIGHT_TOUCH_PORT) == 1) {
				printf("Touch Sensor Triggered \n");
				break;
			}
			if((timedOutTime-nowTime)>7) {
				printf("Timed Out \n");
				break;
			}
			/*if((elapsedDist > cmToTicks(distanceOut) {
				printf("Distanced Out \n");
				break;
			}*/
			sleep(.05);
			timedOutTime=seconds();
		}
		sleep(.25);
        stopMovement();
}

void lookForColor(int colorModel, int speed, int numBlobSightings, float delay, float distOut, int cmBackup)
{
        track_update(); 
        moveStraight(speed);
		int blobCounter = 0;
		//I, Victor Pontis, commented out the next two lines because as of now they are unnecessary. They can be used if we use a time out instead of a distance out. 
		//float startTime = seconds();
		//float elapsedTime = 0;
		int rInitMotorPosit = get_motor_position_counter(R_MOTOR); //motors cannot be going backwards
        int lInitMotorPosit = get_motor_position_counter(L_MOTOR);
		int lElapseMotorPosit = 0;
		int rElapseMotorPosit = 0;
		int elapsedDist = 0;
        while(blobCounter < numBlobSightings) {
                       if(track_count(colorModel) >= 1) {
							blobCounter++;
						}
						if(elapsedDist > cmToTicks(distOut)){
							printf("Green line not detected, function timed out. /n");
							moveToDistance(cmBackup,NORMAL_SPEED);
							stopMovement();
							break;
						}
                        track_update();
						rElapseMotorPosit = get_motor_position_counter(R_MOTOR) - rInitMotorPosit;
						lElapseMotorPosit = get_motor_position_counter(L_MOTOR) - lInitMotorPosit;
						elapsedDist = rElapseMotorPosit < lElapseMotorPosit ? rElapseMotorPosit : lElapseMotorPosit;
                        sleep(delay);
        }
		stopMovement();
       return;
}
void lookForColorFirstGreen(int colorModel, int speed, int numBlobSightings, float delay, float distOut, int cmBackup)
{
        track_update(); 
        moveStraight(speed);
		int blobCounter = 0;
		//They can be used if we use a time out instead of a distance out. 
		//float startTime = seconds();
		//float elapsedTime = 0;
		int rInitMotorPosit = get_motor_position_counter(R_MOTOR); //motors cannot be going backwards
        int lInitMotorPosit = get_motor_position_counter(L_MOTOR);
		int lElapseMotorPosit = 0;
		int rElapseMotorPosit = 0;
		int elapsedDist = 0;
        while(blobCounter < numBlobSightings) {
                       if(track_count(colorModel) >= 1) {
							blobCounter++;
						}
						if(elapsedDist > cmToTicks(distOut)){
							printf("Green line not detected, function timed out. /n");
							stopMovement();
							lowNeutralArm();
							bmd(ARM_MOTOR);
							moveToDistance(cmBackup,NORMAL_SPEED);
							stopMovement();
							break;
						}
                        track_update();
						rElapseMotorPosit = get_motor_position_counter(R_MOTOR) - rInitMotorPosit;
						lElapseMotorPosit = get_motor_position_counter(L_MOTOR) - lInitMotorPosit;
						elapsedDist = rElapseMotorPosit < lElapseMotorPosit ? rElapseMotorPosit : lElapseMotorPosit;
                        sleep(delay);
        }
		stopMovement();
       return;
}


int competitionRunner(int(*func)(), int lightPort)
{
        printf("Competition Runner Initiated\n");
        printf("Waiting for light port: %d\n", lightPort);
        wait_for_light(lightPort);
        shut_down_in(116.0);
        printf("Light Found, Running Func\n");
        return func();
}

int waitForTouch()
{
		int beginningTime = seconds();
		int delayStartTime = seconds();
		while(1) {
			//printf("Wait For Touch Initiated \n");
			printf("Wait for slot sensor \n");
			/*if(digital(9) == 1) {
				sleep(4);
				shut_down_in(108);
				runApp();
				break;
			}*/
			if(digital(15) == 1){
				sleep(4);
				shut_down_in(109);
				runApp();
				break;
			}
			if((delayStartTime-beginningTime)>40){
				shut_down_in(50);
				clear_motor();
				appPart1(); 
				break;
			}
			sleep(.05);
			delayStartTime=seconds();
		}
		ao();
}

/*
	If we are using a slot sensor it is in port 15.
	Digital = 1 means empty
	Digital = 0 means blocked
*/
