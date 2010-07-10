/* This program tests the motors, motor LEDS and servos

Check sensors and charge system separately */
int main()
{
	int i,j;
	kissSim_init(0,0,0,0);
	printf("Testing the CBC\n");
	while(!black_button()){
		for(i=0;i<4;i++){
			printf("Testing Motor %d\n",i);
			printf("Press black button to exit motor test\n");
			for(j=0;j<101;j++){motor(i,j);msleep(10);if(black_button()) break;}
			for(j=100;j>=-100;j--){motor(i,j);msleep(10);if(black_button()) break;}
			for(j=-100;j<=0;j++){motor(i,j);msleep(10);if(black_button()) break;}
			ao();
			if(black_button()) break;
		}
	}
	while(black_button());//wait for button to be released
	enable_servos();
	while(!black_button()){
		for(i=1;i<5;i++){
			printf("Testing Servo %d\n",i);
			printf("Press black button to exit servo test\n");
			for(j=0;j<2047;j=j+100){set_servo_position(i,j);msleep(50);if(black_button()) break;}
			for(j=2047;j>0;j=j-100){set_servo_position(i,j);msleep(50);if(black_button()) break;}
			if(black_button()) break;
		}
	}
	disable_servos();
	while(black_button());//wait for button to be released
	while(!black_button()){
		printf("Test Accellerometers by tilting CBC\n");
		printf("X %d\n",accel_x());
		printf("Y %d\n",accel_y());
		printf("Z %d\n",accel_z());
		printf("Batt Voltage = %f\n",power_level());
		msleep(100);
		printf("%c",12);//clear screen
	}
	printf("Use the sensor screen to test the sensor ports\n");
	printf("Make sure the Charge LED blinks when charging\n");
	printf("CBC test program finished\n");
	return(1);
}
