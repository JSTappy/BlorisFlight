#include <Bloris/Enemy.h>

Enemy::Enemy() 
{
	bullet = nullptr;
	timer = new Timer();
	this->AddChild(timer);
}

Enemy::~Enemy()
{

}

void Enemy::update(float deltaTime)
{
	if (timer->Seconds() > 3)
	{
		Bullet* bullet = new Bullet();
		bullet->position = this->position;
		bullet->scale = glm::vec3(0.5f,0.5f,0.5f);
		bullet->speedx = -300.0f;
		bullets.push_back(bullet);
		this->parent->AddChild(bullet);
		timer->StartOverTimer();
	}
	this->position -= glm::vec3(100.0f, 0.0f, 0.0f) * deltaTime;
}