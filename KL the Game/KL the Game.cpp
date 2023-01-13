#include "menu.h"
#include <random>
//#include <time.h>
int main()
{
	srand(static_cast<unsigned>(time(0)));
	menu menu;;

	menu.run();

	return 0;
}