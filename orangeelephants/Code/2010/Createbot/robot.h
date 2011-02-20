/** \file robot.h
	\brief The main robot file for the CreateBot
	
*/
#ifndef robot_h
#define robot_h
/** \fn int controller(void)
	\brief Starts the controller for the Create
*/
int controller(void);

/** \fn int jacob(void)
	\brief Preliminary test to go up slope and back down.
*/
int jacob(void);

/** \fn int mark(void)
	\brief Method to run for seeding rounds
*/
int mark(void);

/** \fn int yixin(void)
	\brief Ideal double-elimination method
*/
int yixin(void);

/** \fn int vivek(void)
	\brief If their robot is going to block peak this method should be used.
*/
int vivek(void);

/** \fn void printCurrentDist(void)
	\brief Prints current distance travelled.	
*/
void printCurrentDist(void);

int check_battery_levels(void);

int competition_runner(int(*func)(), int lightPort);
#endif
