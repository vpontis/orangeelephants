/**
** \file math.c
** \brief Has various mathematical functions.
**
** Holds mathematical/calculation functions
** for any bot
** \author Vivek B.
** \author Jay K. 
**
*/

#include "boolean.h"

// JDK - 02/19/08 - Refactor; add some functions from siueLibs
// JDK - 02/21/08 - Mathematical Functions; I don't like IC. No overloading. :(
// JDK - 02/21/08 - Constants moved into individual files because constants.c is annoying
// JDK - 02/21/08 - Several boolean functions written
// VSB - 02/22/08 - Formatted the code. Deleted boolean functions.
// VSB - 02/29/09 - Added signums.
/** \brief value of PI accurate up to 5 decimals
*/
#define PI 3.14159265

/*-------------------------------------------------
 Logical Functions
-------------------------------------------------*/
/** \brief Returns the bigger of two numbers (float)
	\param x an argument
	\param y another argument
*/
float f_max(float x, float y) 
{ 
	return x > y ? x : y;
}

/** \brief Returns the bigger of two numbers (int)
	\param x an argument
	\param y another argument
*/
int i_max(int x, int y)
{ 
	return x > y ? x : y;
}

/** \brief Returns the bigger of two numbers (long)
	\param x an argument
	\param y another argument
*/
long l_max(long x, long y)
{
	return x > y ? x : y;
}

/** \brief Returns the smaller number of the two numbers (float)
	\param x an argument
	\param y another argument
*/
float f_min(float x, float y) 
{ 
	return x < y ? x : y;
}

/** \brief Returns the smaller of the two numbers (int)
	\param x an argument
	\param y another argument
*/
int i_min(int x, int y)
{ 
	return x < y ? x : y;
}

/** \brief Returns the smaller of the two numbers (long)
	\param x an argument
	\param y another argument
*/
long l_min(long x, long y)
{
	return x < y ? x : y;
}

/** \brief The absolute value of n (float)
	\param n the value to the abs value of.
*/
float f_abs(float n)
{
	return n < 0.0 ? -n : n;
}
/** \brief The absolute value of n (float)
	\param n the value to the abs value of.
*/
double d_abs(double n)
{
	return n < 0.0 ? -n : n;
}
/** \brief Returns the absolute value of n (int)
	\param n the number to get the abs value of.
*/
int i_abs(int n)
{
	return n < 0 ? -n : n;
}

/** \brief Returns the absolute value of n (long).
	\param n the number to get the abs value of.
*/
long l_abs(long n)
{
	return n < 0L ? -n : n;
}

/*-------------------------------------------------
 Mathematical Functions
-------------------------------------------------*/
/** \brief Finds the circumference of a circle with radius r
	\param r the radius of the circle.
*/
float circle_circumference(float r)
{
    return 2.0 * PI * r;
}

/** \brief Returns the arc length given the number of degrees and the radius.
	\param degrees the degrees of the arc.
	\param radius the radius of the circle.
*/
float arc_length(float degrees, float radius)
{
	return circle_circumference(radius) * (degrees/ 360.0);
}

/** \brief Finds the area of a circle with radius r
	\param r the radius of the circle.
 */
float circle_area(float r)
{
    return PI * r * r;
}
/** \brief Returns the sign of the float
	\param x the number to get the signum of.
*/
int f_signum(float x)
{
    if(x > 0.0)
      return 1;
    if(x < 0.0)
      return -1;
    return 0;
}
/** \brief Returns the sign of the int.
	\param x the number to get the signum of.
*/
int i_signum(int x)
{
    if(x > 0)
      return 1;
    if(x < 0)
      return -1;
    return 0;
}
