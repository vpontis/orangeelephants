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
    turn_arc(true,250,500,200);
    
}

void turn_arc(boolean leftArc, float outerRadius, int speed, float move_distance)
{
	static double ticksPerRev = 1020.4; //Number of motor ticks in one revolution
	static double circumference = 25.6; //Circumference in cm of 81.6x38R Lego wheels
	
	if (outerRadius < LEGOBOT_DIAMETER)
	{
		printf("Outer Radius must be greater than %d\n", LEGOBOT_DIAMETER);
		return;
	}
	float ratio = (outerRadius - LEGOBOT_DIAMETER)/(outerRadius);
	printf("Arcing Ratio =%f\n",ratio);
	float smallerDistance = move_distance * ratio;
	int	smallerVelocity = (int)(speed * ratio);
	if (leftArc)
	{
		mrp(1, smallerVelocity, (long)(((smallerDistance / circumference ) * ticksPerRev)));
		mrp(2, speed, (long)(((move_distance / circumference ) * ticksPerRev)));
	}
	else
	{
		mrp(1, speed, (long)(((move_distance / circumference ) * ticksPerRev)));
		mrp(2, smallerVelocity, (long)(((smallerDistance / circumference ) * ticksPerRev)));
	}
	bmd(1);
	bmd(2);
}
void turn(double angle){
	static double BotCircumference = 53.4; //BOT CIRCUMFERENCE
	static double ticksPerRev = 1020.4; //Number of motor ticks in one revolution
	static double circumference = 25.6; //Circumference in cm of 81.6x38R Lego wheels
	double turnCM = d_abs((angle/360.0) * 53.4);
	int ticksToMove = (int) (( turnCM / circumference ) * ticksPerRev);
	
		
	if(angle<0)
	{
		mrp(1, 500, -ticksToMove);
		mrp(2, 500, ticksToMove);
	}
	else{
		mrp(1, 500, ticksToMove);
		mrp(2, 500, -ticksToMove);
		
		}
	bmd(1);
	bmd(2);
	
	}


/*Declare functions here as needed.*/
