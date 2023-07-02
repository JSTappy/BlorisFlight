/**
 * @file timer.h
 *
 * @brief The timer header file.
 *
 *
 * - Copyright 2023 Joas Sahetapy
 *
 */


#ifndef TIMER_H
#define TIMER_H

#include <common/entity.h>

/// @brief The Timer class is a timer that you can add as a child from an entity
class Timer : public Entity
{
public:
	/// @brief constructor
	Timer(); 

	/// @brief destructor
	virtual ~Timer(); 


	/// @brief update function
	/// @return void
	virtual void update(float deltaTime);


	/// @brief method for starting the timer
	/// @return void
	void StartTimer(); 

	/// @brief method for pausing the timer
	/// @return void
	void PauseTimer(); 

	/// @brief method for resetting the timer and setting the second back to 0
	/// @return void
	void StopTimer(); 

	/// @brief method for starting over
	/// @return void
	void StartOverTimer();

	/// @brief seconds getter
	/// @return seconds
	float Seconds() { return seconds; } 

private:
	/// @brief Seconds in seconds
	float seconds; 

	/// @brief check if timer is paused
	bool paused; 

};

#endif /* TIMER_H */