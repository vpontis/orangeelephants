#include "turn_arc.c"
#include "moveToDistance.c"

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
			mtp(0, 1000, -5300); //-5100 predetermined by using motor test screen.
			bmd(0); 
			//After arm is down, move backwards
			mav(1, -500);
			mav(2, -500);
			sleep(2);
			//While bot is going in reverse, move the arm up slightly
			mtp(0, -1000, -2700);
			bmd(0);
			sleep(1);
			sleep(1);
			//Keep moving the arm up more. (Commented out because it seems unnecessary)
			//mtp(0, -1000, -1800);
			//bmd(0);
			//while arm is moving up, keep backing up
			//while(digital(15)){
			//	mav(1, -500);
			//	mav(2, -500);
			//}
			mav(1,0);
			mav(2,0);
			moveToDistance(20);
			turn(70);
			turn_arc(TRUE,250, 500, 70);
			mtp(0, 1000, -4800);
			bmd(0);
			return;
	
	}

/*Declare functions here as needed.*/
