#include "turn_arc.c"
#include "moveToDistance.c"

			
void runApp();


int greenCount=0;

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
			mtp(0, 1000, -5300); //-5100 predetermined by using motor test screen.
			bmd(0); 
			//After arm is down, move backwards
			mav(1, -500);
			mav(2, -500);
			sleep(2);
			//While bot is going in reverse, move the arm up slightly
			mtp(0, -1000, -2700);
			sleep(.5);
			//Keep moving the arm up more.
			mtp(0, -1000, -1800);
			bmd(0);
			//while arm is moving up, keep backing up
			sleep(2);
			mav(1,0);
			mav(2,0);
			
			//against pvc at this point
		
			//forward
			moveToDistance(5);
			
			
			//arcing right
			turn_arc(FALSE,500, 400, 25);

			//arcing left
			turn_arc(TRUE,280, 400, 35);
			
			//process based green line watching - still arcing
			int duckarcproc=start_process(duckArc());
			start_process(greenWatch(duckarcproc));
			sleep(2.0);
			/*turn(70);
			turn_arc(TRUE,250, 500, 70);
			mtp(0, 1000, -4100);
			bmd(0);
			while(!(track_count(2)>0)){
				mav(1, 500);
				mav(2, 500);
			}
			moveToDistance(-6);*/
			return;
	
	}

/*Declare functions here as needed.*/
int greenWatch(int toKill) {
	
		while(greenCount<2) {
							
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
				sleep(0.1);
				//sleep(0.1); // don't rush print statement update
					//track_update(); // get new image data before repeating
			}	
	kill_process(toKill);
}

void duckArc() {
	turn_arc(TRUE,280, 400, 40);
}
