#include "create_constants.h"
#include "create_motor.c"
#include "boolean.h"
int main() {

	int offset, x, y; 
	enable_servos(); 
	track_update(); // get most recent camera image and process it
	
	while(black_button() == 0) {
		x = track_x(1,0); // get image x data y = track_y(1,0); //	and y data. track_x(1,0) looks for color group 1 and 0 gets the largest (0th element of a sorted array).		
		if(track_count(1) > 0) { // there is a blob
			printf("Blob is at (%d,%d)\n",x,y); 
			offset=5*(x-80); // amount to deviate servo from center
			set_servo_position(2,1024+offset);
		} else {
			printf("No yellow object in sight\n"); // don't rush print statement update
		}
		sleep(0.2);
		track_update(); // get new image data before repeating
	}
	
	disable_servos();
	printf("All done\n");
}
