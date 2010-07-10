#ifndef create_motor_h
#define create_motor_h

void move(float cm);
void move_forward(float cm);
void move_backward(float cm);
void forward(int speed);
void backward(int speed); 
void stop(void);
void release(void);
void grab(void);
void turn(int degrees);
void turn_cw(int degrees);
void turn_ccw(int degrees);
void turn_right(void);
void turn_left(void);
void accelerate(int motorVelocityL, int motorVelocityR, int finalVelocityL, int finalVelocityR,
 float time);
void accelerate_straight(int motorVelocity, int finalVelocity, float time);
void turn_angle(float degrees, int initSpeed, int finalSpeed);
void move_dist(float distance, int initSpeed, int finalSpeed);
void turn_speed(int s, float d);
void turn_d(float degrees);

#endif
