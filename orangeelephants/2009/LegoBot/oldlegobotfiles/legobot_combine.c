/**
legobot_combine.c
Created 1/27/09
Mark Allen Vismonte
Has methods that combines the legobot sensor and motor methods
*/

#include "legobot_combine.h"


void followBlackLine()
{
printf("Following Black Line\n");
moveMotorsAt(50,50);
turnWheelMiddle();
while (!bothOnBlackLine())
	{
	if (onBlackLine(false))
		{
		turnWheel(BW_MIN_LEFT);
		printf("Detected Black on right side IR, turn wheel to %d\n", BW_MIN_LEFT);
		}
	if (onBlackLine(true))
		{
		turnWheel(BW_MIN_RIGHT);
		printf("Detected Black on left side IR, turn wheel to %d\n", BW_MIN_RIGHT);
		}
	msleep(500L);
	}
printf("Found Parallel Black Line, Time to deploy\n");
deployBlockers();
}
