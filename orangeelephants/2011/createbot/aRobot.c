#include "createFunctions.c"

int main()
{
	printf("Press the A button to run the function");
	while(1)
	{
		if(a_button())
		{
			
			createDrive(500);
			sleep(3);
			createDrive(0);
		}
	}
}
		
