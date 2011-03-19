//wait_for_light(LIGHT_PORT);
				shut_down_in(117);
				printf("\n Starting side B");
				//LEG 1: collects ping pong balls @ first station
				//sleep(14.5);
				moveToDist(50.5, MED_SPEED);
				sleep(.2);
				moveToDist(3, MED_SPEED);
				sleep(.7);
				
				//LEG 2: navigates to north PVC
				moveToDist(-8, FAST_SPEED); //moves back to avoid tampering the red towers	
				sleep(2.5);
				pivot(1,-90,FAST_SPEED); //pivots -90 degrees CCW
				moveToDist(-6-10,FAST_SPEED);//moves back to avoid pivoting on black tape, faces North PVC
				pivot(0,-90 , FAST_SPEED); //pivots -90 degrees CW
				moveToDist(82+72, FAST_SPEED);//head to North PVC, the two distances should add up to 120
				
				//LEG 3: collects ping pong balls @ second station
				moveToDist(-19,FAST_SPEED); //backs up to allow for turn
				turn(90, SLOW_SPEED); //pivots to face east PVC
				moveToDist(60+10,FAST_SPEED); //aligns with east PVC
				moveToDist(-6,FAST_SPEED); //backs up to allow for turn
				turn(88,SLOW_SPEED); //pivots to face south PVC & ping pong balls
				moveToDist(21, FAST_SPEED); //collects all biofuels
				sleep(.7);
				moveToDist(-5,FAST_SPEED);
				
				//LEG 4: drop all biofuels			
				turnArc(0, 50, -MED_SPEED, -4); //arcs back and hits north PVC <-reverted
				moveToDist(-55,SLOW_SPEED-100); //aligns with north PVC
				moveToDist(4, FAST_SPEED); //moves slightly forward to leave room for pivot
				pivot(0, 100, FAST_SPEED); //pivots to face final east PVC
				moveToDist(100, FAST_SPEED); //moves and aligns with east PVC
				moveToDist(-42.5,FAST_SPEED);
				pivot(0, 86, FAST_SPEED); //pivots to face drop zone
				moveToDist(50, FAST_SPEED); //drives to and aligns with drop zone (north PVC)
				gateOpen(); //drops all biofuels
				int i;
				for (i = 0; i < 7; i++) {
					moveToDist(-0.5,FAST_SPEED);
					sleep(0.1);
					moveToDist(2,SUPER_SPEED);
				}
