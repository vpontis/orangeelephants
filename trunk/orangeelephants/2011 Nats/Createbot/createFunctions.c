 #include "createFunctions.h"
#include "createConstants.h"
#include "createVision.c"
#include "createMotor.c"

void createInitialize()
{
	int conVal = create_connect();
	if(conVal == 0) {
		printf("Connection success. Setting to full mode...\n");
	}
	else {
		printf("Connection failed.\n");
	}
	create_full();
}

void openClaw() {
	set_servo_position(CLAWL_SERVO_PORT, CLAWL_OPEN_POS); 
	set_servo_position(CLAWR_SERVO_PORT, CLAWR_OPEN_POS); 
}

void closeClaw() {
	set_servo_position(CLAWL_SERVO_PORT, CLAWL_CLOSE_POS); 
	set_servo_position(CLAWR_SERVO_PORT, CLAWR_CLOSE_POS); 
}

void closeClawIncrement() {
	int CLAW_INCR = 25; 
	int positionR = get_servo_position(CLAWR_SERVO_PORT); 
	int positionL = get_servo_position(CLAWL_SERVO_PORT); 
	while (positionR <= CLAWR_CLOSE_POS) {
		set_servo_position(CLAWR_SERVO_PORT, positionR); 
		positionR += CLAW_INCR; 
		set_servo_position(CLAWL_SERVO_PORT, positionL); 
		positionL -= CLAW_INCR; 
	}
	closeClaw();  
}

void openClawIncrement() {
	int CLAW_INCR = 25; 
	int positionR = get_servo_position(CLAWR_SERVO_PORT); 
	int positionL = get_servo_position(CLAWL_SERVO_PORT); 
	while (positionR >= CLAWR_OPEN_POS) {
		set_servo_position(CLAWR_SERVO_PORT, positionR); 
		positionR -= CLAW_INCR; 
		set_servo_position(CLAWL_SERVO_PORT, positionL); 
		positionL += CLAW_INCR; 
	}
	openClaw(); 
}


void calibrateArm() { //beginning of game
	printf("Set arm at the bottom. Black Button to break.\n"); 
	while (1) {     
		if (up_button()) {
			mrp(ARM_MOTOR_PORT, 800, 20); 
		}
		if (down_button()) {
			mrp(ARM_MOTOR_PORT, -800, -20); 
		}
		if (black_button()) {
			clear_motor_position_counter(ARM_MOTOR_PORT); 
			break; 
		}
		sleep(.05); 
	}
}

void moveArm(int pos) {
	printf("Moving arm.\n"); 
	mtp(ARM_MOTOR_PORT, 1000, pos); 
}

void moveSupport(int pos) {
	printf("Moving support.\n"); 
	set_servo_position(SUPPORT_SERVO_PORT, pos); 
}

void touchSensorMovement() {

	while (digital(TOUCH_SENSOR_PORT) == 0) {
		moveStraight(150); 
		sleep(0.05); 
	}
	beep(); 
	createStop(); 
}
