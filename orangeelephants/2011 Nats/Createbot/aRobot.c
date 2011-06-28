#include "createFunctions.c"

int main()
{
	
	enable_servos();
	createInitialize();
	calibrateArm();
	openClaw();
	while (1) {
		if (b_button()) {
			moveToDist(400,500); 
		}
	}
}
