#include "legobotFunctions.c"
#include "legobotConstants.h"
#include "boolean.h"

//**NOTE: adjust the gate to be perpendicular to the ground before presesing the black or 'A' button
int main() {
	while (1)
	{
		if (a_button()==1)
		{
			moveToDistance(10000,950); 
		}
		if (b_button()==1)
		{
			moveToDistance(-10000,950); 
		}
	}
}
