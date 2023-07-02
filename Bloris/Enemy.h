/**
 * @file Enemy.h
 *
 * @brief The Enemy header file.
 *
 *
 * - Copyright 2023 Joas Sahetapy
 *
 */


#ifndef ENEMY_H
#define ENEMY_H

#include <common/entity.h>
#include <common/timer.h>
#include <Bloris/Bullet.h>

 /// @brief The Enemy implementation.
class Enemy : public Entity
{
public:
	/// @brief Constructor
	Enemy();

	/// @brief Destructor
	virtual ~Enemy();

	/// @brief update method
	/// @param deltaTime
	/// @return void
	virtual void update(float deltaTime);

	/// @brief Health of the Enemy
	int health;

	/// @brief list of Bullets
	std::vector <Bullet*> bullets;
private:
	/// @brief a Bullet
	Bullet* bullet;
};

#endif /* ENEMY_H */
