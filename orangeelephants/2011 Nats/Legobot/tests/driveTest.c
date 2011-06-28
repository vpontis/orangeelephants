#include "legobotFunctions.c"
#include "legobotConstants.h"

int main() {
	int x = 1;
	while (x <= 10) {
		printf("%d",x*100);
		moveToDist(50, x*100);
		sleep(2);
		moveToDist(-50,x*100);
		sleep(2);
		x++;
	}
}
