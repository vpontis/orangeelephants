
void moveToDistance(double distance)
{
	static double ticksPerRev = 1020.4; //Number of motor ticks in one revolution
	static double circumference = 25.6; //Circumference in cm of 81.6x38R Lego wheels
	
	int ticksToMove = (int) (( distance / circumference ) * ticksPerRev);
	mrp(1,500,ticksToMove);
	mrp(2,500,ticksToMove);
	bmd(1);
	bmd(2);
	
	return;
}

