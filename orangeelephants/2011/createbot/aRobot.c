#include "createFunctions.c"

int main()
{
	printf("Press the A button to createDrive.\n");
	printf("Press the B button to moveToDistance.\n");
	while(1)
	{
		if(a_button())
		{
			createInitialize();
			int speed=500;
			while(speed>0)
			{
				createDrive(speed);
				sleep(.5);
				
				set_create_distance(0);
				createDrive(0);
				printf("Decel from %d, distance is %d.\n", speed, get_create_distance(.1));
				speed -= 100;
			}
		}
		
		if(b_button())
		{
			createInitialize();
			int distance = 500;
			while( distance > 0)
			{
				moveToDistance(distance,500);
				printf("The distance moved is %d.\n", get_create_distance(.1));
				
				distance -= 100;
			}
		}
	}
}
		
