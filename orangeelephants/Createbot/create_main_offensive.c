#include "create_appendages.c"
#include "create_main_offensive.h"

void create_main_offensive()
{
	int init_time = seconds();
	//Initializes Create to face bearing 0.
	//Puts the dozer up and starts moving the arm up. 
	//Moves forward 96 cm. 
	//Bearings: 50 -> 0
	/***************************************************************/
	moveStraight(NORM_SPEED);
	sleep(.35);
	turn(-34.5,200);//Turns to bearing 0.
	arm_up();//Puts arm up so it will not catch on Karel island
	dozer_high_scrape();//Puts the dozer down so it can push off oily ducks
	move_to_distance(1220, 700); //Moves the create out past the oily duck center, old value 890, 850
	/***************************************************************/
	create_stop();
	dozer_up();
	move_to_distance(-35,700);
	turn(75,200);
	move_to_distance(140,700);//250
	dozer_down();
	turn(-75,200);
	dozer_up();
	arm_high_scrape();
	move_to_distance(170,700);
	turn(75,200);
	bmd(ARM_MOTOR);
	//move_to_distance(150,700);
	moveStraight(700);
	sleep(.75);
	createStop();
	move_to_distance(140,100);
	int islandtime = seconds() - init_time;
	printf("Time to island is %d \n, islandtime");
	turn(130,100);
	
	
	/*move_to_distance(-300, 700);
	arm_high_scrape();
	turn(35, 100);
	move_to_distance(380, 500);
	create_stop(); 
	turn(40,100);
	bmd(ARM_MOTOR);
	move_to_distance(290, 500);
	turn(5, 100);
	move_to_distance(140, 500);
	turn(130,100);*/
	
	//Goes to Karel Island. Aligns with PVC piece next to the 
	//island. 
	//Bearings: 0 -> 90 -> 0 -> 90
	/**************************************************************/
	/*create_stop();
	dozer_up();
	move_to_distance(-25, 700);
	arm_high_scrape();
	turn(49, 100);
	move_to_distance(625, 500);
	create_stop(); 
	turn(30,100);
	move_to_distance(230, 500);
	bmd(ARM_MOTOR);
	turn(130,100);
	/**************************************************************/
	
	//Lowers Arm for the scrape. Turns CW ~90 degrees to scrape.
	//Puts arm at arm_uppest. Turns CCW 90 degrees and realigns. A
	//ARM to arm_scrape()
	//Optional second scrape.
	//Bearings: 270 -> 360 -> 270
	/**************************************************************/
	//turn(10,50);//Split up turn in order to prevent arm from catching
	//arm_scrape();//Lower arm onto Karel Island to scrape frogs and Botguy
	//bmd(ARM_MOTOR);
	//turn(100,50);//Scraping turn 
	arm_up();//Puts arm back up to pass over Karel Island w/o catching
	bmd(ARM_MOTOR);
	turn(-90,100);//Turns back to align w/ PVC again
	arm_scrape();//No cost function that may sweep frogs off
	move_to_distance(100,SLOW_SPEED);//Aligns with PVC
	/**************************************************************/
	
	//Moves back. Turns right. Moves backward with
	//drive_wall to align for floor scrap.
	//Bearings: 90 -> 180
	/**************************************************************/
	sleep(.2);//Pause to prevent uneven backups
	//move_to_distance(5,SLOW_SPEED);//Pulls back to allow turn
	moveStraight(-80);
	sleep(1.2);
	createStop();
	turn(85,100);//Turns create to bearing 360.
	drive_wall(-NORM_SPEED);
	moveStraight(-NORM_SPEED);
	sleep(.25); 
	/**************************************************************/
	
	//Puts dozer at neutral, moves forward for 1st frog scrape.
	//Puts dozer down and moves back. Puts dozer at neutral again
	//Moves forward partially. Puts dozer down and moves backup.
	//for a second scrape.
	//Bearings: 360
	/**************************************************************/
	dozer_neutral();//Puts dozer in position that it will not catch on Karel Island
	move_to_distance(390,150);//Moves forward to get frogs
	//sleep(1.5);
	createStop();
	dozer_scrape();//Puts dozer down to get frogs
	sleep(1);
	move_to_distance(-100,150);//Pulls back frogs
	dozer_neutral();
	move_to_distance(40,150);
	dozer_scrape();
	drive_wall(-NORM_SPEED);//Pulls back frogs
	/**************************************************************/
	

	//Moves forward. Turns right to bearing 270. Then moves forward.
	//to the center of our board.
	//Bearings: 360 -> 270
	/**************************************************************/
	//!!!sleep(.4);!!!Changed!
	moveStraight(150);
	sleep(.7);
	create_stop();
	turn(92,50);//Turns bearing 270
	move_to_distance(680,150);//Drives out in the middle to allow u-turn
	/*************************************************************/

	//Turns around 180 so it can utilize bump sensors. 
	//Drives and pushes against wall to align.
	//Bearings: 270 -> 90  
	/**************************************************************/
	turn(180,50);//U-turn so bearing 90, this allows bump sensor utilization
	drive_wall(-NORM_SPEED);//Drive into PVC until bump sensors triggered
	moveStraight(-NORM_SPEED);//To allow more alignment
	sleep(.50);	
	//create_drive_direct(NORM_SPEED,NORM_SPEED);
	//sleep(.4);
	//create_drive_direct(-NORM_SPEED,-NORM_SPEED);
	//sleep(.4);
	moveStraight(NORM_SPEED);
	sleep(.1); 
	createStop();
	printf("Wall sensed now beginning to turn. \n");
	//move_to_distance(-1,-150);//Gets Create off wall to allow turn (may not be necessary)
	/*create_drive_direct(-100,-100);
	sleep(.4);*/
	//createStop();
	/*************************************************************/

	//Attempts to "parallel park." Turns left 50 degrees.
	//Backs up until the right bump sensor is hit. 
	//Then moves backward. Realigns by repeating.
	/*************************************************************/
	turn(-50,50);//Turns slightly 
	//Backs up until the right bump sensor is hit	
	moveStraight(-NORM_SPEED);
	create_sensor_update();
	while(gc_rbump == 0){
		create_sensor_update();
	}
	turn(-53, 50);//Realigns with the wall
	//Keeps moving back.
	moveStraight(-NORM_SPEED);
	sleep(1);
	/**********************************************************/	

	//Backs up until the wall is hit with both sensors.
	//Additional Failsafe
	/**********************************************************/
	/*const int arcValue = 10;
	create_drive_direct(NORM_SPEED-arcValue,NORM_SPEED+arcValue);
	sleep(7);*/
	createStop();
	sleep(7);
	moveStraight(-SLOW_SPEED);
	while(1){
		create_sensor_update();
		if(gc_rbump == 1){
			if(gc_lbump == 0)
			{
				createStop();
				turn(-10, 50);//The motherfucking failsafe
				moveStraight(-SLOW_SPEED);
			}
			if(gc_lbump == 1)
			{
				break;
			}
		}
	}
	moveStraight(100);
	sleep(2.5);
	dozer_high_scrape();
	drive_wall(-NORM_SPEED);
	createStop();
	ao();
	/**********************************************************/
}
