/**
 * @file Boss.h
 *
 * @brief The Boss header file.
 * 
 * 
 * - Copyright 2023 Joas Sahetapy 
 * 
 */


#ifndef BOSS_H
#define BOSS_H


#include <Bloris/Enemy.h>

/// @brief The Boss implementation.
class Boss : public Enemy
{
public:
	/// @brief Constructor
	Boss();

	/// @brief Destructor
	virtual ~Boss();

	/// @brief update method
	/// @param deltaTime
	/// @return void
	virtual void update(float deltaTime);

private:
	/// @brief timer
	Timer* timer;

	/// @brief attack1
	Timer* attack1;

	/// @brief attack2
	Timer* attack2;

	/// @brief attack3
	Timer* attack3;
	 
	/// @brief attack4
	Timer* attack4;

	/// @brief damaged
	bool damaged;

	/// @brief damaged
	bool damaged2;
};

#endif /* BOSS_H */
