void accel(int initSpeed, int finalSpeed);
void createDrive(int finalSpeed);
void initializeCreate();

/**
accel(int initSpeed, int finalSpeed)
Accelerates or decelerates the robot from one speed to the next in 20 incremental speeds. 
Robot continues on driving straight at finalSpeed.
*/
void accel(int initSpeed, int finalSpeed)
{
	int increm = (finalSpeed-initSpeed)/20;
	int speed = initSpeed;
	
	float time = abs((finalSpeed-initSpeed)/2500);//delay is .1 sec for accel from 0-500
	
	if(speed<finalSpeed)//if you are accelerating
	{
		while(speed<finalSpeed)
		{
			speed += increm; 
			create_drive_straight(speed);
			sleep(time);
		}
	}
	else//if you are decelerating
	{
		while(speed>finalSpeed)
		{
			speed += increm; 
			create_drive_straight(speed);
			sleep(time);
		}
	}
	
	create_drive_straight(finalSpeed);
}

void createDrive(int finalSpeed)
{
	int initSpeed = get_create_requested_velocity(.1);
	accel(initSpeed, finalSpeed);
}

void initializeCreate()
{
	int conVal = create_connect();
	create_full();
}
