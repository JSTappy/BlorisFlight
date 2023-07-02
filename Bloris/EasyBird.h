/**
 * @file EasyBird.h
 *
 * @brief The EasyBird header file.
 *
 *
 * - Copyright 2023 Joas Sahetapy
 *
 */


#ifndef EASYBIRD_H
#define EASYBIRD_H

#include <Bloris/Enemy.h>

 /// @brief The EasyBird implementation.
class EasyBird : public Enemy
{
public:
	/// @brief Constructor
	EasyBird();

	/// @brief Destructor
	virtual ~EasyBird();

	/// @brief update method
	/// @param deltaTime
	/// @return void
	virtual void update(float deltaTime);

private:
	/// @brief delay between shots of the birds
	Timer* shotdelay;
};

#endif /* EASYBIRD_H */
