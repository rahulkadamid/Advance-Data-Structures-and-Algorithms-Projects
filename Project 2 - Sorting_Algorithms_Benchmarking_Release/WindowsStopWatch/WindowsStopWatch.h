#ifndef WINDOWS_STOPWATCH_H 
#define WINDOWS_STOPWATCH_H 
// // Based on code from Dr. Fawcett: 
// http://www.lcs.syr.edu/faculty/fawcett/handouts/CSE687/code/HiResTimerNativeCpp/HiResTimer.cpp 
// http://www.lcs.syr.edu/faculty/fawcett/handouts/CSE687/code/HiResTimerNativeCpp/HiResTimer.h 
// 
#ifdef linux 
#elif defined __APPLE_CC__ 
#else

#include <Windows.h>

class WindowsStopWatch 
{ 
public: 
	WindowsStopWatch();
	void start(); 
	void stop(); 
	long getTime(); 
protected:
	__int64 a, b, f;
};

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
#endif