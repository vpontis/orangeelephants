int main()
{
	//3 is left, 0 is right
	int initL = get_motor_position_counter(3);
	int initR = get_motor_position_counter(0);
	mav(3, 1000);
	mav(0, 1000);
	sleep(5);
	freeze(0);
	freeze(3);
	int leftDist = initL-get_motor_position_counter(3);
	int rightDist = initR-get_motor_position_counter(0);
	printf("The left distance traveled is %d.\n", initL-get_motor_position_counter(3));
	printf("The right distance traveled is %d.\n", initR-get_motor_position_counter(0));
	float ratio = (float)leftDist/(float)rightDist;
	printf("Comp ratio is %.3f or %.3f.\n", ratio, 1.0/ratio);
}

	
	
