#include "legobotFunctions.c"
#include "legobotConstants.h"

int main() {	
	while(1)
	{
		if (b_button()==1)
		{
			moveToDistance(50,500);  
			sleep(.05); 
			//moveToDistance(-5,400);  
			//turnArc(0,20,400,-45); 
			//turn(45,500); 
			moveToDistance(-10,500); 
			sleep(.05); 
			turnArc(1,30,500,45);  
			moveToDistance(150,500); 
			sleep(.05);   
			moveToDistance(-15,300); 
			sleep(.05); 
			//turn(90,500); 
			//sleep(.05); 
			//moveToDistance(70,400); 
			turnArc(0,15,500,90);
			moveToDistance(60,500);  
			sleep(.05); 
			moveToDistance(-20,500); 
			turn(-90,500); 
			sleep(.05); 
			moveToDistance(20,400); 
			sleep(.05); 
			//moveGate(750); 
			//sleep(.05); 
			//moveGate(-750); 
		}
	}	
}

