/**
 * @file Player.h
 *
 * @brief The Player header file.
 *
 *
 * - Copyright 2023 Joas Sahetapy
 *
 */


#ifndef PLAYER_H
#define PLAYER_H

#include <common/entity.h>
#include <common/timer.h>
#include <Bloris/Bullet.h>

/// @brief The Player implementation.
class Player : public Entity
{
public:
	///@brief Constructor
	Player();

	///@brief Destructor
	virtual ~Player();

	///@brief update method
	virtual void update(float deltaTime);
	
	///@brief _speed getter
	/// @param _speed
	/// return float
	float Speed() { return _speed; };

	///@brief _bulletspeed getter
	/// @param _bulletspeed
	/// return float
	float BulletSpeed() { return _bulletspeed; };

	///@brief _bulletdamage getter
	/// @param _bulletdamage
	/// return float
	float BulletDamage() { return _bulletdamage; };

	///@brief _level getter
	/// @param _level
	/// return int
	int Level() { return _level; };

	///@brief the offset to make it seem like the bullets are coming out of the player cannon
	glm::vec3 bulletoffset;

	///@brief Magicpoints are the points needed to upgrade your bullets and balloon
	int magicPoint;

	///@brief check if player is dead or not
	bool dead;

	///@brief health of the player
	int health;

	///@brief list of Bullets
	std::vector <Bullet*> bullets;
private:

	///@brief the time that has to be in between shooting beams
	Timer* sphereDelay;
	
	///@brief speed of the player
	float _speed;

	///@brief speed of the bulllets
	float _bulletspeed;

	///@brief damage of the bullets
	float _bulletdamage;

	///@brief level of the player
	int _level;

	///@brief Shooting method.
	/// @return void
	void Shoot();

	///@brief Big Sphere Shooting Method
	/// @return void
	void ShootBeam();

	///@brief method for upgrading Balloon
	/// @return int
	int UpgradeBalloon();

	///@brief method for upgrading Bullet Speed
	/// @return int
	int UpgradeBulletSpeed();

	///@brief method for upgrading Bullet Damage
	/// @return int
	int UpgradeBulletDamage();

	///@brief method for upgrading Hit Points
	/// @return int
	int UpgradeHitPoints();

	///@brief method for upgrading Speed
	/// @return float
	float UpgradeSpeed();
};

#endif /* PLAYER_H */
