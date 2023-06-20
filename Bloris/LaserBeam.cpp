#include <Bloris/LaserBeam.h>

LaserBeam::LaserBeam()
{
	this->AddSprite("assets/pencils.tga");
	scale = glm::vec3(4, 4, 0);
	dead = false;
	speedx = 500;
	speedy = 0;
	damage = 20;
}

LaserBeam::~LaserBeam()
{

}

void LaserBeam::update(float deltaTime)
{
	this->position += glm::vec3(speedx, speedy, 0) * deltaTime;
}