#include "StopWatch.h"

StopWatch::StopWatch()
{
}

void StopWatch::start()
{
	startTime = std::chrono::steady_clock::now();

}

void StopWatch::stop()
{
	endTime = std::chrono::steady_clock::now();

}

long StopWatch::getElapsedTime()
{
	endTime = std::chrono::steady_clock::now();

	auto seconds = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);

	return seconds.count();
}
