#include "Bloris/Spawner.h"

Spawner::Spawner()
{
	easybird = nullptr;
	boss = nullptr;
	bossActive = false;
	killed = 0;
}

Spawner::~Spawner()
{

}

void Spawner::update(float deltaTime)
{
	if (killed == 2 && !bossActive)
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
		glm::vec3 random = glm::vec3(0, rand() % HEIGHT/100,0); //Random position 
		easybird = new EasyBird();
		this->parent->AddChild(easybird);
		enemies.push_back(easybird);
		easybird->position = this->position + random;
}
void Spawner::SpawnBoss()
{
	glm::vec3 pos = glm::vec3(0,50,0);
	boss = new Boss();
	this->parent->AddChild(boss);
	enemies.push_back(boss);
	boss->position = this->position + pos;
}
