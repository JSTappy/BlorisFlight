#include "Bloris/Spawner.h"

Spawner::Spawner()
{

}

Spawner::~Spawner()
{

}

void Spawner::update(float deltaTime)
{
	if (enemies.size() <= 0)
	{
	SpawnEnemies();
	}
}

void Spawner::SpawnEnemies()
{
		enemy = new Enemy();
		enemy->AddSprite("assets/kingkong.tga");
		glm::vec3 random = glm::vec3(0, rand() % HEIGHT/100,0); //Random position 
		this->parent->AddChild(enemy);
		enemies.push_back(enemy);
		enemy->position = this->position + random;
}
