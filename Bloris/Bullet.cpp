#include <Bloris/Bullet.h>

Bullet::Bullet()
{
	this->AddSprite("assets/rgba.tga");
	scale = glm::vec3(0.5f, 0.5f, 0.5f);
	dead = false;
	speedx = 0;
	speedy = 0;
	damage = 1;
}

Bullet::~Bullet()
{

}

void Bullet::update(float deltaTime)
{
	this->position += glm::vec3(speedx, speedy, 0) * deltaTime;
}