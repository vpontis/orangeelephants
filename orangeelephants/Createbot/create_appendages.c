#include "create_constants.h"
#include "create_appendages.h"
#include "boolean.h"
/**brief Second to highest arm position
 */
void arm_up()	{
	mtp(ARM_MOTOR, ARM_FAST_SPEED, ARM_UP+ARM_OFFSET);
}

void arm_up_fast()	{
	mtp(ARM_MOTOR, ARM_FAST_SPEED, ARM_UP+ARM_OFFSET);
}

/**brief Arm position for first scrape
 */
void arm_scrape()	{
	mtp(ARM_MOTOR, ARM_FAST_SPEED, ARM_SCRAPE+ARM_OFFSET);
}
/**brief Highest arm position
*/
void arm_uppest()	{
	mtp(ARM_MOTOR, ARM_FAST_SPEED, ARM_UPPEST+ARM_OFFSET);
}


/**brief Derive arm speed
 /param target_pos the position the arm will be at.

 Function sees if arm is moving clockwise or counterclockwise. 
 If counterclockwise, the speed is lowered. If clockwise, the 
 speed is increased. Done to minimize tension and to optimize 
 create.
*/
int arm_speed(int target_pos){
		if(target_pos <= get_motor_position_counter(ARM_MOTOR)){
				return ARM_SLOW_SPEED;
		}
		else{
				return ARM_NORMAL_SPEED;
		}
}

/**brief Puts the metallic dozer in 90 vertical position
 */
void dozer_up()	{
	moveServos(DOZERL_SERVO,DOZERR_SERVO,DOZERL_UP,DOZERR_UP,100);
}
/**brief puts the dozer at 45 degrees
*/	
void dozer_neutral()	{
	moveServos(DOZERL_SERVO,DOZERR_SERVO,DOZERL_NEUTRAL,DOZERR_NEUTRAL,100);
}

/**brief Puts dozer at slightly above horizontal
 */	
void dozer_down()	{
	moveServos(DOZERL_SERVO,DOZERR_SERVO,DOZERL_DOWN, DOZERR_DOWN, 100);
}
/**brief Pushes dozer against ground for best scraping
 */
void dozer_scrape()	{
	moveServos(DOZERL_SERVO,DOZERR_SERVO,DOZERL_SCRAPE,DOZERR_SCRAPE,100);
}
/**brief Pushes dozer against ground for best scraping
 */
void dozer_high_scrape()	{
	moveServos(DOZERL_SERVO,DOZERR_SERVO,DOZERL_HIGH_SCRAPE,DOZERR_HIGH_SCRAPE,100);
}

/**brief Pushes dozer against ground for best scraping
 */
void dozer_timeout()	{
	moveServos(DOZERL_SERVO,DOZERR_SERVO,DOZERL_TIMEOUT,DOZERR_TIMEOUT,100);
}

/**brief Moves a servo to a position at a speed
   /param servo the port of servo
   /param pos the end position of servo
   /param speed the desired speed of movement
*/
void moveServoPosition(int servo, int pos, int speed)	{
	const float dSleep = .05;
	int jumpSize = abs(speed * abs(pos - get_servo_position(servo))) / 800;
	int curr = get_servo_position(servo);
	int change = pos > get_servo_position(servo) ? jumpSize : -jumpSize;
	
	//timeout
	int initPos = get_servo_position(servo);
	float initT = seconds();
	float timeOut=initT+dSleep*abs(initPos - pos)/((float)jumpSize)+.2; // .2 = leeway 
	
	for(curr = get_servo_position(servo); 
		((change < 0 &&  curr > pos) || (change > 0 && curr < pos)) && seconds()<timeOut;
			curr = curr + change) {
		set_servo_position(servo,curr);
		set_servo_position(servo,curr);
		sleep(dSleep);
	}
	if(curr<pos)
		printf("Timeout - Servo:%d, CurrPos:%d, TargetPos:%d\n",servo,get_servo_position(servo),pos);
	sleep(.05);
}

/**brief Moves two servos at once
   /see moveServoPosition
 */
void moveServos(int servo1, int servo2, int pos1, int pos2, int speed)	{
	const float dSleep = .05;
	int jumpSize1 = abs(speed * abs(pos1 - get_servo_position(servo1))) / 800;
	int jumpSize2 = abs(speed * abs(pos2 - get_servo_position(servo2))) / 800;
	int curr1 = get_servo_position(servo1);
	int curr2 = get_servo_position(servo2);
	int change1 = pos1 > get_servo_position(servo1) ? jumpSize1 : -jumpSize1;
	int change2 = pos2 > get_servo_position(servo2) ? jumpSize2 : -jumpSize2;
	/*timeout
	int initPos = get_servo_position(servo1);
	float initT = seconds();
	float timeOut=initT+dSleep*abs(initPos - pos)/((float)jumpSize)+.2; // .2 = leeway 
	*/
	curr1 = get_servo_position(servo1);
	curr2 = get_servo_position(servo2);
	while(((change1 < 0 &&  curr1 > pos1) || (change1 > 0 && curr1 < pos1)) || 
			((change2 < 0 &&  curr2 > pos2) || (change2 > 0 && curr2 < pos2)))
	{
			if((change1 < 0 &&  curr1 > pos1) || (change1 > 0 && curr1 < pos1))
			{
					set_servo_position(servo1, curr1);
					curr1 += change1;
			}
			if((change2 < 0 &&  curr2 > pos2) || (change2 > 0 && curr2 < pos2))
			{
					set_servo_position(servo2, curr2);
					curr2 += change2;
			}	
	}
	sleep(.05);
}

/**Turns at around center of the Create
   /param deg desired degrees
   /param vel desired velocity of turn
*/
void turn(float deg, int vel)	{//turn a given amout using gc_angle
	deg = -1 * deg;
	int a=(int)(deg+(deg*0.09/360.0 - 0.14)*deg/2);
	create_angle(); sleep(.05);
	gc_total_angle=0;
	if (a > 0) {
		create_spin_CCW(vel);
		while(gc_total_angle < a) {
			create_angle(); 
			sleep(.05);
		}
	}
	else {
		create_spin_CW(vel);
		while(gc_total_angle > a) {
			create_angle(); sleep(.05);
		}
	}
	create_stop();	
}

/**brief Converts inches to cm
   /param inch The input inch value
*/
float inchToMm(int inch) {
	//distances: 34.50, 24, 24, -19
	//34.50 is distance from wall to first slick, 19 is the width of the create
	return inch * 25.4;
}

/**brief Drives to wall until either bump sensor is hit.
   /param speed The desired speed to go to wall. POSITIVE = FORWARD!!!
 */
void drive_wall(int speed)	{
	create_sensor_update();
	create_drive_direct(-speed,-speed);
	while((gc_lbump==0) || (gc_rbump==0))	{
		create_sensor_update();
	}
	createStop();
}

/**brief Drives to wall until either bump sensor is hit.
   /param speed The desired speed to go to wall. POSITIVE = FORWARD!!!
 */
void drive_wall_timeout(int speed)	{
	int init_time = seconds();
	create_sensor_update();
	create_drive_direct(-speed,-speed);
	int timeout_one_flag = false; 
	
	while((gc_lbump==0) || (gc_rbump==0))	{
		create_sensor_update();
		if(((seconds()-init_time) >= 10) && !timeout_one_flag)
		{
			dozer_timeout();
			moveStraight(NORM_SPEED);
			sleep(.5);
			dozer_timeout();
			moveStraight(-NORM_SPEED);
			sleep(.75);		
			dozer_scrape();
			moveStraight(speed);
			timeout_one_flag = true;
		}
	}
	createStop();
}
/**brief Stops create movement
*/
void createStop()	{
	create_drive_direct(0,0);
}


/**brief Function for second Karel Island sweep.

	Sets are to arm_scrape. Turns 
    	counterclockwise. Raises up arm and turns
        90 degrees clockwise. Then, moves back
	25 cm.
*/
void secondSweep()	{
	/*create_drive_direct(80,80);
	sleep(1);
	createStop();*/
	arm_scrape();
	bmd(ARM_MOTOR);
	turn(110,70);
	arm_uppest();
	bmd(ARM_MOTOR);
	turn(-90,100);//Turns back to align w/ PVC again
	move_to_distance(-250,SLOW_SPEED);//Aligns with PVC
}


/**brief Moves to a specified mm value.
         /param distance Input absolute distance
         /param speed desired speed. POSITIVE = FORWARD!!!!
	
	Input absolute location and speed, and it will go there using gc_distance
	**Not too accurate**
*/
void move_to_distance(int distance, int speed)  { 
	gc_distance=0;
	if(gc_distance > distance) {      
		create_drive_direct(speed, speed);
        	create_sensor_update();
	while (gc_distance < -distance) {
		sleep(0.05);
       	        create_sensor_update();
        }
     }
     else {
	create_drive_direct(-speed,-speed);
	create_sensor_update();
        while (gc_distance > -distance) {
		sleep(0.05);
           	create_sensor_update();
        }
    }
}

/**brief Move straight
   /param speed The speed to move at. Negative = forward.
*/
void moveStraight(int speed)	{
	create_drive_direct(-speed, -speed);
}

/**brief Competition initiliazation. 
	/param *func The function to execute after the light.
	/param lightPort The lightport of the light sensor.
*/
int competitionRunner(int(*func)(), int lightPort)
{
    printf("Competition Runner Initiated\n");
    printf("Waiting for light port: %d\n", lightPort);
    wait_for_light(lightPort);
    shut_down_in(130);
    printf("Light Found, Running Func\n");
	return func();
}



