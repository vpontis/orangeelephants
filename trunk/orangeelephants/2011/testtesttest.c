//wait_for_light(LIGHT_PORT);
				shut_down_in(117);
				printf("\n Starting side A");
				//LEG 1: collects ping pong balls @ first station
				//sleep(14);
				moveToDist(49, MED_SPEED);
				sleep(0.2);
				moveToDist(3, MED_SPEED);
				sleep(.7);
				
				//LEG 2: navigates to north PVC
				moveToDist(-6, FAST_SPEED); //moves back to avoid tampering the red towers	
				sleep(1.5);
				pivot(0,-90,FAST_SPEED); //pivots -90 degrees CW
				moveToDist(-7-6,FAST_SPEED);//moves back to avoid pivoting on black tape***********
				pivot(1,-98,FAST_SPEED); //pivots -100 degrees CCW, faces north
				//moveToDist(120,FAST_SPEED); //split into two distances in following lines
				moveToDist(87+65, FAST_SPEED);//runs into to North PVC, the two distances should add up to 140

				
				//LEG 3: collects ping pong balls @ second station				
				moveToDist(-20,FAST_SPEED); //backs up to allow for turn
				turn(-90,SLOW_SPEED); //pivots to face west PVC
				moveToDist(40+10,FAST_SPEED); //aligns with west PVC
				moveToDist(-6,FAST_SPEED); //backs up to allow for turn
				turn(-85, SLOW_SPEED); //pivots to face south PVC & ping pong balls
				moveToDist(20, FAST_SPEED); //collects all biofuels
				sleep(.7);
				moveToDist(-10,FAST_SPEED); //backs up so that bot won't turn on tape when arriving at drop zone
				
				//LEG 4: drop all biofuels
				turnArc(1, 50, -MED_SPEED, -4); //arcs back and hits north PVC <-reverted
				moveToDist(-45,SLOW_SPEED-100); //aligns with north PVC
				moveToDist(4, FAST_SPEED); //moves slightly forward to leave room for pivot
				pivot(1, 94, FAST_SPEED); //pivots to face final east PVC
				moveToDist(100, FAST_SPEED); //moves and aligns with east PVC
				moveToDist(-29, FAST_SPEED); //moves back to align with drop zone and avoid tape
				pivot(0, -82, FAST_SPEED); //pivots to face drop zone
				moveToDist(50, FAST_SPEED); //drives to and aligns with drop zone (north PVC)
				gateOpen(); //drops all biofuels
				int i;
				for (i = 0; i < 7; i++)	{
					moveToDist(-0.5,FAST_SPEED);
					sleep(0.1);
					moveToDist(2,SUPER_SPEED);
				}
