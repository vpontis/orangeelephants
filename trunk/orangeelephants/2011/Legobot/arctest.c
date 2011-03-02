#include "legobotFunctions.c"
#include "legobotConstants.h"

int main() {	
{
	while(1)
	{
		if (a_button()==1)
		{
	turnArc(1,20,500,50); 
		}
		else if (b_button()==1)
		turnArc(1,-20,500,50); 
		else if (black_button()==1)
		break; 
	}
}
