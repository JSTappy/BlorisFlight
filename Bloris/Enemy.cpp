#include <Bloris/Enemy.h>

Enemy::Enemy() 
{
	bullet = nullptr;
}

Enemy::~Enemy()
{

}

void Enemy::update(float deltaTime)
{
	this->position -= glm::vec3(100.0f, 0.0f, 0.0f) * deltaTime;
}