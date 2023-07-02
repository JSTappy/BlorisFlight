#include <Bloris/Boss.h>

Boss::Boss()
{
	this->AddSprite("assets/boss/partyparty.tga");
	
	timer = new Timer();
	attack1 = new Timer();

	health = 1000;

	this->AddChild(timer);
	this->AddChild(attack1);
}

Boss::~Boss()
{

}

void Boss::update(float deltaTime)
{
	if (attack1->Seconds() > 0.69)
	{
		std::cout << "attack" << std::endl;
		Bullet* bullet = new Bullet();
		bullet->AddSprite("assets/enemies/enemybullet.tga");
		bullet->position = this->position;
		bullet->scale = glm::vec3(2, 2, 2);
		bullet->velocity.x = -300.0f;
		bullet->health = 1;
		bullets.push_back(bullet);
		this->parent->AddChild(bullet);
		attack1->StartOverTimer();
	}
	if (timer->Seconds() > 6)
	{
		this->position -= glm::vec3(0, 0, 0.0f) * deltaTime;
		timer->StartOverTimer();
		return;
	}
	if (timer->Seconds() > 3)
	{
		this->position -= glm::vec3(0, -150.0f, 0.0f) * deltaTime;
		return;
	}
	if (timer->Seconds() > 0)
	{
		this->position -= glm::vec3(0, 150.0f, 0.0f) * deltaTime;
	}


	if (this->position.x >= 1000.0f)
	{
		this->position -= glm::vec3(100.0f, 0.0f, 0.0f) * deltaTime;
		timer->StartTimer();
	}
}