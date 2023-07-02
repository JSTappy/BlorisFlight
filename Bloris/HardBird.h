/**
 * @file HardBird.h
 *
 * @brief The HardBird header file.
 *
 *
 * - Copyright 2023 Joas Sahetapy
 *
 */


#ifndef HARDBIRD_H
#define HARDBIRD_H

#include <Bloris/Enemy.h>

/// @brief The HardBird implementation.
class HardBird : public Enemy
{
public:
	/// @brief Constructor
	HardBird();

	/// @brief Destructor
	virtual ~HardBird();

	/// @brief update method
	/// @param deltaTime
	/// @return void
	virtual void update(float deltaTime);

private:
	/// @brief delay between shots of the birds
	Timer* shotdelay;
};

#endif /* HARDBIRD_H */
