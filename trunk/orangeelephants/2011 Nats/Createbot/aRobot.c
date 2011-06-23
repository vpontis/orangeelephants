#include "createFunctions.c"
//#include "createMotor.c"

int main()
{
	
	enable_servos();
	createInitialize();
	printf("Press B to callibrate slider. \n");
	while(1){
		if(b_button()){
			printf("Press B when done. \n");
			sleep(0.1);
			closeHopper();
			while(1){
				if(up_button()){
					mav(SLIDER_FRONT, 500);
					mav(SLIDER_BACK, -500);
					sleep(0.1);
				}
				if(down_button()){
					mav(SLIDER_FRONT, -500);
					mav(SLIDER_BACK, 500);
					sleep(0.1);
				}
				mav(SLIDER_FRONT, 0);
				mav(SLIDER_BACK, 0);
				if(b_button()){
					printf("Slider Callibrated. \n");
					clear_motor_position_counter(SLIDER_BACK);
					clear_motor_position_counter(SLIDER_FRONT);
					break;
				}
			}
		}
	}
	
	moveSlider(-2000, 1000);
	ao();
}

	
