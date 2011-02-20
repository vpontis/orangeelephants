int main()
{
	clear_motor_position_counter(2);  
	while (1) {
		if (up_button() == 1) {
			mav(2,50); 
				if (black_button() ==1) {
					mav(2,0); 
					printf("%f", get_motor_position_counter(2)); 
				}
			}
		}
				
}


