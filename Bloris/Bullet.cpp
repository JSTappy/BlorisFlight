#include <Bloris/Bullet.h>

Bullet::Bullet()
{
	this->AddSprite("assets/rgba.tga");
	dead = false;
	speedx = 0;
	speedy = 0;
}

Bullet::~Bullet()
{

}

void Bullet::update(float deltaTime)
{
	this->position += glm::vec3(speedx, speedy, 0) * deltaTime;
}