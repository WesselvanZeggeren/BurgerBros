#include "CountdownTimer.h"

Timer::Timer()
{
}

void Timer::start()
{
	startTime = std::chrono::steady_clock::now();
}

void Timer::stop()
{
	endTime = std::chrono::steady_clock::now();

}

long Timer::getElapsedTime()
{
	endTime = std::chrono::steady_clock::now();

	auto seconds = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);

	return seconds.count();
}

void Timer::reset()
{
	startTime = std::chrono::steady_clock::now();
}
