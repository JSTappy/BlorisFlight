#include "Bloris/Spawner.h"

Spawner::Spawner()
{
	easybird = nullptr;
	mediumbird = nullptr;
	hardbird = nullptr;
	boss = nullptr;
	bossActive = false;
	killed = 0;
}

Spawner::~Spawner()
{

}

void Spawner::update(float deltaTime)
{
	if (killed == 24 && !bossActive)
	{
		std::cout << "SPAWN BOSS WIEEE WOOO" << std::endl;
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


	if (killed  <= 8)
	{
		easybird = new EasyBird();
		easybird->position = this->position + glm::vec3(0, randomHeight, 0); // Set random height
		this->parent->AddChild(easybird);
		enemies.push_back(easybird);
	}
	else if (killed > 8 && killed <= 16)
	{
		mediumbird = new MediumBird();
		mediumbird->position = this->position + glm::vec3(0, randomHeight, 0); // Set random height
		mediumbird->scale = glm::vec3(2, 2, 2);
		this->parent->AddChild(mediumbird);
		enemies.push_back(mediumbird);
	}
	else if (killed > 16 && killed <= 24)
	{
		hardbird = new HardBird();
		hardbird->position = this->position + glm::vec3(0, randomHeight, 0); // Set random height
		this->parent->AddChild(hardbird);
		enemies.push_back(hardbird);
	}
}
void Spawner::SpawnBoss()
{
	boss = new Boss();
	this->parent->AddChild(boss);
	enemies.push_back(boss);
	boss->position = this->position;
}
