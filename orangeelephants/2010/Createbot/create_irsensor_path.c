 /***************************************************************************/
/*********     This comment should be filled with a description    *********/
/*********         of your program and what it does.               *********/
/*********       This template is for Botball programs.            *********/
/*********    Make sure you have selected the CBC target.          *********/
/***************************************************************************/

/* Libraries used in Botball are automatically included, but list any additional includes here */

/* #defines and constants go here.*/

/*Global variables go here (if you absolutely need them).*/

/*Function prototypes below*/
float inchToMm(int inch)
{
	return inch * 25.4;
}


int main()
{
	    set_each_analog_state(0,0,1,0,0,0,0,0);
        create_connect();
		create_full();
 
		cbc_display_clear();
		
		//float distance = inchToMm(34.50+24+24-25);
		float distance = 1680;
		
		int lowthresh = 0;
	    int highthresh = 980;
		gc_distance = 0;
		create_drive_direct(300,300);
		create_sensor_update();
		while (gc_distance < distance) 
		{ 
			while((analog10(2) <= highthresh))
			{
				create_spin_CCW(100);
				sleep(0.05);
				create_sensor_update();
				printf("Turning at sensor reading = %d\n",analog10(2));
			}
			printf("irsensorreading = %d\n", analog10(2));
			sleep(0.05);
			create_sensor_update();
			
		}
		
	
	
        create_stop();
    
}

/*Declare functions here as needed.*/
