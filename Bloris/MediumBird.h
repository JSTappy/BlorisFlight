/**
 * @file MediumBird.h
 *
 * @brief The MediumBird header file.
 *
 *
 * - Copyright 2023 Joas Sahetapy
 *
 */


#ifndef MEDIUMBIRD_H
#define MEDIUMBIRD_H

#include <Bloris/Enemy.h>

/// @brief The MediumBird implementation.
class MediumBird : public Enemy
{
public:
	/// @brief Constructor
	MediumBird();

	/// @brief Destructor
	virtual ~MediumBird();

	/// @brief update method
	/// @param deltaTime
	/// @return void
	virtual void update(float deltaTime);

private:
	/// @brief delay between shots of the birds
	Timer* shotdelay;

	/// @brief timer for the pattern of the bird
	Timer* timer;
};

#endif /* MEDIUMBIRD_H */
