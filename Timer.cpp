#include "Timer.h"


using namespace std::chrono;

Timer::Timer()
{
	Reset();
}



void Timer:: Reset()
{
	t0 = high_resolution_clock::now();
	t1 = t0;

	elapsedTime = 0.0;
	totalTime = 0.0;
	
}

Timer& Timer::Get()
{
	//will only happen once
	static Timer t;
	return t;
}



void Timer::Tick()
{
	t1 = high_resolution_clock::now();
	auto delta = t1 - t0;
	t0 = t1;

	elapsedTime = delta.count();
	totalTime += elapsedTime;
}

double Timer::GetElapsedMilliseconds()
{
	//convert from nanoseconds to milliseconds
	return elapsedTime * 1e-6;
}

double Timer::GetElapsedSeconds() const
{
	return elapsedTime * 1e-9;
}

double Timer::TotalTimeMilliseconds() const
{
	return totalTime * 1e-6;
}

double Timer::TotalTimeSeconds() const
{
	return totalTime * 1e-9;
}





