#ifndef _CREATE_APPENDAGES_H
#define _CREATE_APPENDAGES_H
;
void arm_up();
void arm_netural();
void dozer_up();
void dozer_down();
void dozer_neutral();
void dozer_high_scrape();
void moveServoPosition(int servo, int pos, int speed);
void moveServos(int servo1, int servo2, int pos1, int pos2, int speed);
void turn(float deg, int vel);
float inchToMm(int inch);
void secondSweep();
void createStop();
void arm_scrape();
void arm_uppest();
int arm_speed(int target_pos);
void move_to_distance(int distance, int speed);
int competitionRunner(int(*func)(), int lightPort);


#endif
