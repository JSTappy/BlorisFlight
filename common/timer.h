#ifndef TIMER_H
#define TIMER_H

#include <common/entity.h>

class Timer : public Entity
{
public:
	Timer();
	virtual ~Timer();

	virtual void update(float deltaTime);

	void StartTimer();
	void PauseTimer();
	void StopTimer();
	void StartOverTimer();

	float Seconds() { return seconds; }

private:
	float seconds;
	bool paused;

};

#endif /* TIMER_H */