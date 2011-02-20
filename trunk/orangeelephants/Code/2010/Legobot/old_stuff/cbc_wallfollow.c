/***************************************************************************/
/*********     This comment should be filled with a description    *********/
/*********         of your program and what it does.               *********/
/*********       This template is for Botball programs.            *********/
/*********    Make sure you have selected the CBC target.          *********/
/***************************************************************************/

/* Libraries used in Botball are automatically included, but list any additional includes here */

/* #defines and constants go here.*/
#include "boolean.h"
#include "math.c"
#include "legobot_motor.h"
/*Global variables go here (if you absolutely need them).*/

/*Function prototypes below*/
//left wheel = 1, right wheel = 2;


void turn(double angle){
	static double BotCircumference = 53.4; //BOT CIRCUMFERENCE
	static double ticksPerRev = 1020.4; //Number of motor ticks in one revolution
	static double circumference = 25.6; //Circumference in cm of 81.6x38R Lego wheels
	double turnCM = d_abs((angle/360.0) * 53.4);
	int ticksToMove = (int) (( turnCM / circumference ) * ticksPerRev);
	
		
	if(angle<0)
	{
		mrp(1, 500, -ticksToMove);
		mrp(2, 500, ticksToMove);
	}
	else{
		mrp(1, 500, ticksToMove);
		mrp(2, 500, -ticksToMove);
		
		}
	bmd(1);
	bmd(2);
	
	}





int main()   {
	set_each_analog_state(1,0,0,0,0,0,0,0);
	 while(a_button() == 0)
	 { 
		if(digital(8) == 0)
		 { 
			if(analog10(0) <= 400)
			{
			 mav(1,500);
			 mav(2,300);
			 printf("loop 1 IR reading: %d\n", analog10(0));
			 sleep(0.05);
			}
			else if (analog10(0) >= 700)
			{
			mav(1,300);
			mav(2,500);
		    printf("loop 2 IR reading: %d\n", analog10(0));
			sleep(0.05);
			}
			else
			{
			mav(1,300);
			mav(2,300);
		    printf("loop 3 IR reading: %d\n", analog10(0));
			sleep(0.05);
			}
		}
		else
		{
			mav(1,-500);
			mav(2,-500);
			sleep(1.1);
			turn(-66);
			sleep(.2);
		}
	}
        ao();
       // create_stop();
        
    //Put anything below you want your robot to do after the game (e.g. play victory song).
    
}

/*Declare functions here as needed.*/
