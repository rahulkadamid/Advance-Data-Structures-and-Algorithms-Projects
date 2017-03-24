// 
// revision history: 
// 
// version 1.0 - intial release 
// 
// version 1.1 - fix by Shawn Mueller to start the stopwatch in the constructor 
//				to give similar behaviour to the unix stopwatch. 
// 

#include "WindowsStopWatch.h" 
#include <exception>
#ifdef linux 
#elif defined __APPLE_CC__ 
#else

WindowsStopWatch::WindowsStopWatch()
{
	b = 0UL; if (QueryPerformanceFrequency((LARGE_INTEGER*)&f) == 0) throw std::exception("no high resolution counter on this platform");
	QueryPerformanceCounter((LARGE_INTEGER*)&a);
}

void WindowsStopWatch::start()
{ 
	::Sleep(0); 
	QueryPerformanceCounter((LARGE_INTEGER*)&a); 
}

void WindowsStopWatch::stop()
{ 
	QueryPerformanceCounter((LARGE_INTEGER*)&b); 
}

long WindowsStopWatch::getTime()
{ 
	__int64 d = (b - a); 
	__int64 ret_milliseconds; 
	ret_milliseconds = (d * 1000UL) / f; 
	return ret_milliseconds; 
}
#endif