/**
* legobot_main.c
* created 1/24/09
* Mark Allen Vismonte
* This file will be used to run what the legobot does for the final task
* Used now for testing purposes
*/
//#include "legobot_motor.c"
#include "legobot_combine.c"
#include "boolean.h"

/* Pseudocode
drive out of the box until it is out of the box
turn left
drive past the turbine and knock it down
go up the start of the slope
center on the middle black line
go up the hill until both IR sensors find the black line
Then we will deploy the blockers and park there
end
*/
int run_legobot()
{
/*enable_servos();
setBlockerPosition(true, L_BLOCKER_UP);
setBlockerPosition(false, R_BLOCKER_UP);
printf("Blockers @ the top\n");
msleep(10000L);
setBlockerPosition(true, L_BLOCKER_DOWN);
setBlockerPosition(false, R_BLOCKER_DOWN);
printf("Blockers @ the down\n");
msleep(4000L);
disable_servos();
printf("Program done");
int i;
for (i = R_BLOCKER_DOWN; i < 2047; i+= 50)
	{
	setBlockerPosition(false, i);
	msleep(2500L);
	}
printf("Program done");*/
initMotors();
printf("Start Testing\n");
moveMotorsAt(150,150);
msleep(7500L);
disableMotors();
printf("Program done\n");
return 0;

}
