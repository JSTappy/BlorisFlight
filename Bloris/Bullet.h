/**
 * @file Bullet.h
 *
 * @brief The Bullet header file.
 *
 *
 * - Copyright 2023 Joas Sahetapy
 *
 */


#ifndef BULLET_H
#define BULLET_H

#include <common/entity.h>
#include <iostream>
#include <vector>

 /// @brief The Bullet implementation.
class Bullet : public Entity
{
public:
	/// @brief Constructor
	Bullet();
	/// @brief Destructor
	virtual ~Bullet();

	/// @brief x and y speed of the bullets
	glm::vec2 velocity;

	/// @brief damage of the bullet
	int damage;

	/// @brief health of the bullet
	int health;

	/// @brief update method
	/// @param deltaTime
	/// @return void
	virtual void update(float deltaTime);

	/// @brief checking if this is dead or not
	bool dead;

private:

};

#endif /* BULLET_H */
