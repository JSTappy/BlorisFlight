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
	Spawner();
	virtual ~Spawner();

	virtual void update(float deltaTime);
	void SpawnEnemies();
	void SpawnBoss();

	int killed;
	bool bossActive;
	std::vector <Enemy*> enemies;
	std::vector <Spawner*> spawners;

private:
	EasyBird* easybird;
	MediumBird* mediumbird;
	HardBird* hardbird;
	Boss* boss;
};

#endif /* SPAWNER_H */
