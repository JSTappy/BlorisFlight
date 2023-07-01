#include <Bloris/Enemy.h>

Enemy::Enemy() 
{
	bullet = nullptr;
	health = 3;
}

Enemy::~Enemy()
{
	delete bullet;
	bullet = nullptr;
}

void Enemy::update(float deltaTime)
{

}