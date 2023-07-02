#include <Bloris/Bullet.h>

Bullet::Bullet()
{
	this->AddSprite("assets/player/Bullet.tga");
	scale = glm::vec3(0.5f, 0.5f, 0.5f);
	dead = false;
	velocity = glm::vec2(0, 0);
	damage = 1;
	health = 1;
}

Bullet::~Bullet()
{

}

void Bullet::update(float deltaTime)
{
	this->position += glm::vec3(velocity.x, velocity.y, 0) * deltaTime;
	this->rotation = this->parent->rotation;
}