

#include <iostream>
#include "WindowsStopWatch.h"

using namespace std;

#ifndef TEST_WINDOWSSTOPWATCH
#define TEST_WINDOWSSTOPWATCH

int main()
{

	WindowsStopWatch wsw;
	wsw.start();

	for (int i = 0; i < 100000000; i++);

	wsw.stop();

	cout << "Timed:" << wsw.getTime() << endl;

	return 0;
}

#endif // !TEST_WINDOWSSTOPWATCH