#ifndef SPAWNER_H
#define SPAWNER_H

#include <cstdlib>
#include "common/entity.h"
#include "Bloris/Enemy.h"

 /// @brief The Spawner implementation.
class Spawner : public Entity
{
public:
	Spawner();
	virtual ~Spawner();

	virtual void update(float deltaTime);
	void SpawnEnemies();
	std::vector <Enemy*> enemies;

	std::vector <Spawner*> spawners;

private:
	Enemy* enemy;
};

#endif /* SPAWNER_H */
