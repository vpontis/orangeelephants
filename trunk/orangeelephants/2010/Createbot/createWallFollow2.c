
int main()
{
	
	//left speed = 300 + speed offset
	//while loop updating sensor reading
	create_connect();
	create_full();
	set_each_analog_state(0, 0, 0, 0, 0, 0, 1, 1);
	int ir = 0, son = 0;
	int targetDist=900;
	int propConstI=4;
	int rspd=0,lspd=0;
	int speed_offset=0;
	gc_distance = 0;
	create_drive_direct(200, 200);
	while(1)
	{	create_sensor_update();
		ir = analog10(6);
		son = analog10(7);
		printf("ir: %d; son: %d;", ir, son);
		speed_offset = (targetDist - ir)/propConstI ;
		
		
		rspd=max(50,75 + (speed_offset<0 ? speed_offset : 0));
		lspd=max(50,75 + (speed_offset>0 ? -1*speed_offset : 0));
		
		if(ir<600&&son<30) {
			rspd=80;
			lspd=100;
		}
		
		printf("l: %d; r: %d;\n", lspd, rspd);
		
		create_drive_direct(rspd,lspd);
		//sleep(.5);
		//create_drive_direct(100 + (speed_offset<0 ? speed_offset : 0), 100+(speed_offset>0 ? -1*speed_offset : 0));
		sleep(.1);
		create_drive_direct(75,75);
		sleep(.1);
				
		//create_drive_direct(100, 100);
		if(gc_distance > 2000)
		{	create_stop();
			break;
		}
	}    
}

/*Declare functions here as needed.*/
int max(int a, int b) {
	return (a>b) ? a : b;
}
