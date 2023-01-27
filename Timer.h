#pragma once

#include <chrono>

class Timer
{
public:
	Timer();

	//get global timer instance
	static Timer& Get();

	//ticks once every frame (game class)
	void Tick();

	//reset timer
	void Reset();

	double GetElapsedMilliseconds();
	double GetElapsedSeconds() const;

	double TotalTimeSeconds() const;
	double TotalTimeMilliseconds() const;

private:
	std::chrono::high_resolution_clock::time_point t0, t1;
	double elapsedTime;
	double totalTime;
};

