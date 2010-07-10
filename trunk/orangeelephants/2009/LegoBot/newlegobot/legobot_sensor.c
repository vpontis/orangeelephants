/**
	\file legobot_sensor.h
	\date Jan 27, 2009
	\author Mark Allen Vismonte
	\brief Holds all sensor reading functions. 
*/

#include "legobot_sensor.h"

/** \brief Reads value from an analog port.
	\param port The port to read from.
	\return The value read from the sensor.
*/
int read_analog(int port)
{
	int i, counter = 0, current;
	for (i = 0; i < READ_TIMES; i++)
	{
		current = analog10(port);
		printf("Current Reading: %d\n", current);
		counter += current;
		msleep(15L);//sleeps to allow enough time for the reading
	}
	printf("%d\n", counter/READ_TIMES);
//printf("Reading Analog Port %d\n", port);
	return counter/READ_TIMES;
}

/** \brief Reads a value from the right IR sensor.
	\return The value read from the sensor.
*/
int get_right_ir_sensor()
{
	return analog10(R_IRSENSOR);
}

/** \brief Reads a value from the center IR sensor.
	\return The value read from the sensor.
*/
int get_center_ir_sensor(void)
{
	return analog10(C_IRSENSOR);
}

/** \brief Reads a value from the left IR sensor.
	\return The value read from the sensor.
*/
int get_left_ir_sensor()
{
	return analog10(L_IRSENSOR);
}

/** \brief Checks if there is a black line on left sensor.
	\return true if there is black on left else false.
*/
boolean is_left_black()
{
	return get_left_ir_sensor() > BLACK_READING_MIN;
}

boolean is_center_black()
{
	return get_center_ir_sensor() > BLACK_READING_MIN;
}

/** \brief Checks if there is a black line on right sensor.
	\return true if there is black on right else false.
*/
boolean is_right_black()
{
	return get_right_ir_sensor() > BLACK_READING_MIN;
}

/** \brief Checks if there is a black line on both sensors.
	\return true if there is black on both else false.
*/
boolean both_on_black_line()
{
	return is_right_black() && is_center_black();
}

boolean two_on_black_line()
{
	int count = 0;
	if (is_left_black())
		count++;
	if (is_center_black())
		count++;
	//if (is_right_black())
	//	count++;
	return count > 1;
}

boolean three_on_black_line()
{
	return both_on_black_line() && is_center_black();
}

