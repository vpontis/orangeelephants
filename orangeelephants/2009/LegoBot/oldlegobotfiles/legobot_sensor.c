/**
legobot_sensor.c
Created 1/27/09
Mark Allen Vismonte
Creating a legobot sensor file that sorts all the sensor functions for the legobot
*/

#include "legobot_sensor.h"

#define READ_TIMES 25

#define WHITE_READING_MAX 100
#define BLACK_READING_MIN 200

#define R_IRSENSOR 8 //Analog Port 8
#define L_IRSENSOR 11 //Analog Port 11

int readAnalog(int port)
{
int i, counter = 0;
for (i = 0; i < READ_TIMES; i++)
	{
	counter += analog10(port);
	msleep(15L);//sleeps to allow enough time for the reading
	}
//printf("Reading Analog Port %d\n", port);
return counter/READ_TIMES;
}

int getRightIRSensor()
{
return readAnalog(R_IRSENSOR);
}

int getLeftIRSensor()
{
return readAnalog(L_IRSENSOR);
}

boolean onBlackLine(boolean leftIR)
{
if (leftIR)
	return getLeftIRSensor() > BLACK_READING_MIN;
else
	return getRightIRSensor() > BLACK_READING_MIN;
}

boolean bothOnBlackLine()
{
return onBlackLine(true) && onBlackLine(false);
}
