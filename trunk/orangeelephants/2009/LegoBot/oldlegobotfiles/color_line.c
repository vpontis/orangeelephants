//Makes robot follow object being tracked
//on color channel 0
int main()
{
	int forwardSpeed = 150, x;
	//the next 2 lines used instead of create_connect
	create_start();
	create_safe();
	printf("Press black button to start/end\n");
	while(!black_button()){msleep(20);}
	while(black_button()){msleep(20);}
	while(!black_button()) //press black button again
	{
		track_update();
		if(track_count(0)>0)
		{
			x = track_x(0, 0);
			create_drive_direct(forwardSpeed+2*(80-x), forwardSpeed+2*(x-80));
			printf("Object at %d, %d\n", x, track_y(0,0));
		}
		else
		{
			create_stop();
			printf("No red seen\n");
		}
		msleep(200); //slow loop so we can read prints
	} //end while
	printf("All done \n");
	create_disconnect();
	return 0;
}
