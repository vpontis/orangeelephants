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
											runApp();       
											break;
										}
										if(right_button())   {
											printf("Running competition mode");
											//competitionMode(); //Old competition thing 
											set_each_analog_state(1,0,0,0,0,0,0,0);
											competitionRunner(runApp,LIGHT_SENSOR_PORT);
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
				
				neutralArm();
				//back up form first pvc pipe and turn 90 degrees to the left
                moveToDistance(-5, FAST_SPEED);               
                turn(-90);  

				//move arm to neutral position
                
				
				
                //back up until the robot is aligned with the pvc pipe
                sleep(0.05);
                moveToDistanceTurn(-92, FAST_SPEED+15, FAST_SPEED-15); //make slight arc while backing up into PVC      
			    moveToDistanceTurn(3, FAST_SPEED, FAST_SPEED); //move forward a little so it can take a turn  
                turn(-90);//now alined at bearing -90 degrees
				moveToWall(FAST_SPEED);//running into the wall until touch sensors triggered
              
				moveToDistanceTurn(-8,FAST_SPEED, FAST_SPEED);
				turn(-180);//bearing 90 degrees
				moveToWall(FAST_SPEED);//against PVC
				lowNeutralArm();
				bmd(ARM_MOTOR);
				
				moveToDistanceTurn(-8,FAST_SPEED,FAST_SPEED);
				turn(-90);
				moveToWall(FAST_SPEED); //bearing 0 degrees against PVC
				
				moveToDistanceTurn(-8,FAST_SPEED,FAST_SPEED);
				turn(90);
				moveToWall(FAST_SPEED); //bearing 90 degrees against PVC
				
				
				moveToDistanceTurn(-8,FAST_SPEED,FAST_SPEED);
				turn(90);
				moveToWall(FAST_SPEED); //bearing 180 degrees running into other robot hopefully
       
                
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
			if((timedOutTime-nowTime)>12) {
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

