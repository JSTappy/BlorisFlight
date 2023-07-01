#include "Bloris/Spawner.h"

Spawner::Spawner()
{
	srand(time(NULL));
	easybird = nullptr;
	boss = nullptr;
	bossActive = false;
	killed = 0;
}

Spawner::~Spawner()
{
	delete easybird;
	delete boss;
	easybird = nullptr;
	boss = nullptr;
	enemies.clear();
	spawners.clear();
}

void Spawner::update(float deltaTime)
{
	if (killed == 24 && !bossActive)
	{
		SpawnBoss();
		bossActive = true;
	}
	if (enemies.size() <= 0 && !bossActive)
	{
		SpawnEnemies();
	}
}

void Spawner::SpawnEnemies()
{
	float minHeight = -300.0f;  // Minimum height for spawning
	float maxHeight = 300.0f; // Maximum height for spawning
	float randomHeight = minHeight + static_cast<float>(rand()) / (RAND_MAX / (maxHeight - minHeight));

	easybird = new EasyBird();
	easybird->position = this->position + glm::vec3(0, randomHeight, 0); // Set random height
	this->parent->AddChild(easybird);
	enemies.push_back(easybird);
}
void Spawner::SpawnBoss()
{
	glm::vec3 pos = glm::vec3(0,50,0);
	boss = new Boss();
	this->parent->AddChild(boss);
	enemies.push_back(boss);
	boss->position = this->position + pos;
}
