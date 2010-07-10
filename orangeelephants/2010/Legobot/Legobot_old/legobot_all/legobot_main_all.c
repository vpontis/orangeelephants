#include "boolean.h"
#include "legobot_motor.c"

void runApp();
int main()
{
		
		while(1)
			{
				if(b_button())
				{
						while(1)
						{
							printf("release button pressed\n");
							mav(0,500); 
							sleep(.1);
							if(b_button())
							{
								mav(0,0);	
								sleep(.1);
								break;
							}
						}
				  }
				if(a_button())
				{
					runApp();	
					break;
				}
				
				
			}
		   //Rinse and repeat....
		   
			ao();
			
}
void runApp()
	{
	
			clear_motor_position_counter(0); //Assumes that the arm starts pointing straight up
			cbc_display_clear();
			set_each_analog_state(1,0,0,0,0,0,0,0);
		
			mtp(0, 1000, -5100); //-5300 predetermined by using motor test screen.
			bmd(0); 
			//After arm is down, move backwards
			mav(1, -500);
			mav(2, -500);
			sleep(2);
			//While bot is going in reverse, move the arm up slightly
			mtp(0, -1000, -4216);
			sleep(.5);
			//Keep moving the arm up more.
			//mtp(0, -1000, -2000);
			bmd(0);
			//while arm is moving up, keep backing up
			sleep(2);
			mav(1,0);
			mav(2,0);
			moveToDistance(5);
			mtp(0,-1000, -1600);
			bmd(0);
			//against pvc at this point
		
			//forward
			moveToDistance(5);
			
			
			//arcing right
			turn_arc(FALSE,500, 400, 25);

			//arcing left
			turn_arc(TRUE,230, 400, 30);
			
			int greenCount=0;
			while(greenCount<2) {
				turn_arc(TRUE,300, 400, 2);
			
				track_update(); // get most recent camera image and process it
				if(track_count(2) > 0) { // there is a blob
			//			printf("Blob is at (%d,%d)\n",x,y);
						greenCount++;
//						set_servo_position(2,1024+offset);
				}
				else {
				//		printf("No yellow object in sight\n");
						greenCount--;
				}
					
				//sleep(0.1); // don't rush print statement update
					//track_update(); // get new image data before repeating
			}
			printf("Green Detected");
			
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
		  
		  return;
	
	}

/*Declare functions here as needed.*/
