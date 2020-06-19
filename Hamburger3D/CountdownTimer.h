#pragma once

#include <chrono>

class Timer
{
public:
	Timer();

	void start();
	void stop();
	long getElapsedTime();
	void reset();

private:
	std::chrono::time_point<std::chrono::steady_clock> startTime;
	std::chrono::time_point<std::chrono::steady_clock> endTime;
};

