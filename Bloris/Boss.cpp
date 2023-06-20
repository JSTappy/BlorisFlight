#include <Bloris/Boss.h>

Boss::Boss()
{
	this->AddSprite("assets/kingkong.tga");
	timer = new Timer();
	health = 10;
	this->AddChild(timer);
	damaged = false;
}

Boss::~Boss()
{

}

void Boss::update(float deltaTime)
{

}