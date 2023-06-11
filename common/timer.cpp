#include "common/timer.h"

Timer::Timer()
{
	seconds = 0;
	paused = false;
}

Timer::~Timer()
{

}

void Timer::update(float deltaTime)
{
	if (!paused) {
	seconds += deltaTime;
	}
}

void Timer::StartTimer() {
	paused = false;
}

void Timer::PauseTimer() {
	if (paused) {
		paused = false;
		return;
	}
	paused = true;
}

void Timer::StopTimer() {
	paused = true;
	seconds = 0;
}

void Timer::StartOverTimer() {
	paused = true;
	seconds = 0;
	paused = false;
}
