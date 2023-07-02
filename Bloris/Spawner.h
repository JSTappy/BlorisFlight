/**
 * @file Spawner.h
 *
 * @brief The Spawner header file.
 *
 *
 * - Copyright 2023 Joas Sahetapy
 *
 */


#ifndef SPAWNER_H
#define SPAWNER_H

#include <cstdlib>
#include "common/entity.h"
#include "Bloris/Enemy.h"
#include "Bloris/EasyBird.h"
#include "Bloris/MediumBird.h"
#include "Bloris/HardBird.h"
#include "Bloris/Boss.h"

 /// @brief The Spawner implementation.
class Spawner : public Entity
{
public:

	/// @brief Constructor
	Spawner();

	/// @brief Destructor
	virtual ~Spawner();

	/// @brief update method
	/// @param deltaTime
	/// @return void
	virtual void update(float deltaTime);

	/// @brief Constructor
	/// @return void
	void SpawnEnemies();

	/// @brief Constructor
	/// @return void
	void SpawnBoss();

	/// @brief the amount of enemies killed
	int killed;

	/// @brief check if boss is active or not
	bool bossActive;

	/// @brief list of enemies
	std::vector <Enemy*> enemies;

private:
	/// @brief Easybird
	EasyBird* easybird;

	/// @brief MediumBird
	MediumBird* mediumbird;

	/// @brief HardBird
	HardBird* hardbird;

	/// @brief Final Boss
	Boss* boss;
};

#endif /* SPAWNER_H */
