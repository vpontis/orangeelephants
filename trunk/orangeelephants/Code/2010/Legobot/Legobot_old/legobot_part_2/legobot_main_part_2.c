/***************************************************************************/
/*********     This comment should be filled with a description    *********/
/*********         of your program and what it does.               *********/
/*********       This template is for Botball programs.            *********/
/*********    Make sure you have selected the CBC target.          *********/
/***************************************************************************/

/* Libraries used in Botball are automatically included, but list any additional includes here */

/* #defines and constants go here.*/
#include "boolean.h"
#include "legobot_motor.c"
//#include "legobot_motor.h"
/*Global variables go here (if you absolutely need them).*/
//back up 35 cm, 
/*Function prototypes below*/
//left wheel = 1, right wheel = 2;









int main()   {
	cbc_display_clear();
	set_each_analog_state(1,0,0,0,0,0,0,0);
	
	moveToDistance(-46);
	moveToDistance(15);
	turn(-85);
	while(digital(8) == 0)
	{
		mav(1,500);
		mav(2,500);
		sleep(0.05);
	}
		mav(1,-500);
		mav(2,-500);
		moveToDistance(-15);
	turn(90);
	
	
	     
				track_update(); // get most recent camera image and process it
	           while(track_count(0) == 0)
				{
					mav(1,400);
					mav(2,400);
					sleep(0.05);
					track_update();
				}
				printf("YAY found...");
				track_update();
				if(track_count(0) > 0) { // there is a blob
					
				moveToDistance(40);
				turn(90);	
				moveToDistance(90);
				turn(-90);
				moveToDistance(10);
				turn(90);
					
				
				while(digital(8) == 0)
				{
					mav(1,500);
					mav(2,500);
					sleep(0.05);
				}
				    mav(1,0);
					mav(2,0);
				sleep(0.2);
					moveToDistance(-7);		
					turn(90);	
	
				}
				
				
	
			
	
	
	
	
	/*
	 while(a_button() == 0)
	 { 
		if(digital(8) == 0)
		 { //turn right
			if(analog10(0) >= 800)
			{
			 mav(1,500);
			 mav(2,300);
			 printf("loop 1 IR reading: %d\n", analog10(0));
			 sleep(0.05);
			}//turn left
			else if (analog10(0) <= 600)
			{
			mav(1,300);
			mav(2,500);
		    printf("loop 2 IR reading: %d\n", analog10(0));
			sleep(0.05);
			}//go straight
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
	}*/
        ao();
       // create_stop();
        
    //Put anything below you want your robot to do after the game (e.g. play victory song).
    
}

/*Declare functions here as needed.*/
