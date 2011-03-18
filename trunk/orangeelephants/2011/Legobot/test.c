#include "legobotFunctions.c"
#include "legobotConstants.h"
#include "boolean.h"

int main(){
	/*int i = 1000;
	while(i >= 100)
	{
		clear_motor_position_counter(L_MOTOR);
		mav(L_MOTOR, i);
		sleep(5);
		mav(L_MOTOR, 0);
		printf("The left distance is %d.\n", get_motor_position_counter(L_MOTOR));
		
		clear_motor_position_counter(R_MOTOR);
		mav(R_MOTOR, i);
		sleep(5);
		mav(R_MOTOR, 0);
		printf("The right distance is %d.\n", get_motor_position_counter(R_MOTOR));
		
		clear_motor_position_counter(L_MOTOR);
		float initSeconds = seconds();
		mtp(L_MOTOR, i, 5000);
		printf("The time in secs for left is %f.\n", seconds()-initSeconds);
		
		clear_motor_position_counter(R_MOTOR);
		initSeconds = seconds();
		mtp(R_MOTOR, i, 5000);
		printf("The time in secs for right is %f.\n", seconds()-initSeconds);
		i = i - 100;
	}*/
	while(1){
	//test interference capabilities
					moveToDist(60,FAST_SPEED);
					moveToDist(-75,FAST_SPEED);
				}	
}
