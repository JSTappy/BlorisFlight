#include <Bloris/Bullet.h>

Bullet::Bullet()
{
	this->AddSprite("assets/rgba.tga");
	dead = false;
}

Bullet::~Bullet()
{

}

void Bullet::update(float deltaTime)
{
	this->position += glm::vec3(300.0f, 0, 0.0f) * deltaTime;
}