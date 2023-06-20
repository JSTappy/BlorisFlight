#include "Bloris/Spawner.h"

Spawner::Spawner()
{
	easybird = nullptr;
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
		glm::vec3 random = glm::vec3(0, rand() % HEIGHT/100,0); //Random position 
		easybird = new EasyBird();
		this->parent->AddChild(easybird);
		enemies.push_back(easybird);
		easybird->position = this->position + random;
}
