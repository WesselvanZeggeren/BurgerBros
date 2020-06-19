#pragma once

#include <chrono>
#include <string>

class StopWatch
{
public:
	StopWatch();

	void start();

	void stop();
	
	long getElapsedTime();
	

private:
	std::chrono::time_point<std::chrono::steady_clock> startTime;
	std::chrono::time_point<std::chrono::steady_clock> endTime;
};

