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

	int main()
	{
		int x = 0;
		int i = 0;
		create_connect();
		create_full();
		while(i++ < 100)
		{
		if(x < 2){x++;} else {x=2;}
		if( i % 2 ==0)	{
			create_drive_direct(500,500);
			sleep(2.75-x);
			
		}
		else
		{
		create_drive_direct(-500,-500);
		sleep(2.75-x);	
		}
			
		}
		
	}

/*Declare functions here as needed.*/
