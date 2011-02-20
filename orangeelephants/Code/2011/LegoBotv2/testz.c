#include "legobotFunctions.c"
#include "legobotConstants.h"



void calibrateBlockerLeft(){
        while(1){
                if(down_button() == 1){
                        mrp(L_BLOCKER_MOTOR, 10, -10);
                }
                else if(up_button() == 1){
                        mrp(L_BLOCKER_MOTOR, 50, 1000);
                }
                else if (right_button()== 1){
					clear_motor_position_counter(L_BLOCKER_MOTOR); 
                }
				else if(left_button() ==1){
					break; 
				}
        } 
		printf("%d", get_motor_position_counter(L_BLOCKER_MOTOR)); 
}

int main()
{
	//moveToDistance(10*2.54,300); 
	calibrateBlockerLeft(); 
}
