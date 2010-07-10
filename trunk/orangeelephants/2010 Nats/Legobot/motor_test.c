/***************************************************************************/
/*********     This comment should be filled with a description    *********/
/*********         of your program and what it does.               *********/
/*********       This template is for Botball programs.            *********/
/*********    Make sure you have selected the CBC target.          *********/
/***************************************************************************/

/* Libraries used in Botball are automatically included, but list any additional includes here */

/* #defines and constants go here.*/

/*Global variables go here (if you absolutely need them).*/

/*Function prototypes below*/
#include "boolean.h"
#include "legobot_motor.c"
#include "legobot_constants.h"
#include "legobot_main_all_modular.h"


int main()
{
    moveStraight(NORMAL_SPEED);
    sleep(10);
}

/*Declare functions here as needed.*/
