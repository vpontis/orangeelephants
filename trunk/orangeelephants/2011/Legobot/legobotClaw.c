int main()
{
	int CLAW_RAISER = 0;
	int CLAW_OPEN_CLOSE = 0;
	int CLAW_VERTICAL = 250;
	int CLAW_HORIZONTAL = 1200;
	int CLAW_OPEN = 1900;
	int CLAW_CLOSE_TIGHT = 1200;
	
	int position = get_servo_position( CLAW_RAISER );
	if ( position > CLAW_VERTICAL )
	{
		int increment = 15;
		while ( get_servo_position(CLAW_RAISER) > CLAW_VERTICAL )
		{
			set_servo_position(CLAW_RAISER , position - increment);
			increment += 15;
		}
	}
	sleep(2);
	position = CLAW_VERTICALv;
	while ( get_servo_position(CLAW_RAISER) < CLAW_HORIZONTAL )
	{
		set_servo_position(CLAW_RAISER, position);
		position += 15;
	}
	sleep(2);
	int increment = 15;
	while ( get_servo_position(CLAW_OPEN_CLOSE) < 1900 )
	{
		set_servo_position(CLAW_OPEN_CLOSE, increment);
		increment += 15;
	}
	int clawPos = 1900 - 15;
	while ( get_servo_position(CLAW_OPEN_CLOSE) > 1200 )
	{
		 set_servo_position( CLAW_OPEN_CLOSE, clawPos );
		 clawPos -= 15;
	}
}
