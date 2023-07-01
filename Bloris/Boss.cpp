#include <Bloris/Boss.h>

Boss::Boss()
{
	this->AddSprite("assets/boss/PartyParty.tga");
	
	timer = new Timer();
	attack1 = new Timer();
	attack2 = new Timer();
	attack3 = new Timer();
	attack4 = new Timer();

	health = 1000;

	damaged = false;
	damaged2 = false;

	this->AddChild(timer);
	this->AddChild(attack1);
	this->AddChild(attack2);
	this->AddChild(attack3);
	this->AddChild(attack4);
}

Boss::~Boss()
{

}

void Boss::update(float deltaTime)
{
	if (attack1->Seconds() > 2)
	{
		std::cout << "attack" << std::endl;
		Bullet* bullet = new Bullet();
		bullet->position = this->position;
		bullet->position.y = 100;
		bullet->scale = glm::vec3(1.0f, 1.0f, 1.0f);
		bullet->speedx = -200.0f;
		bullet->health = 1;
		bullets.push_back(bullet);
		this->parent->AddChild(bullet);
		attack1->StartOverTimer();
	}
	if (attack2->Seconds() > 5)
	{
		std::cout << "Attack2" << std::endl;
		Bullet* bullet = new Bullet();
		glm::vec3 random = glm::vec3(0, rand() % HEIGHT / 20, 0); //Random position 
		bullet->position = this->position + random;
		bullet->scale = glm::vec3(1.0f, 1.0f, 1.0f);
		bullet->speedx = -200.0f;
		bullet->health = 1;
		bullets.push_back(bullet);
		this->parent->AddChild(bullet);
		attack2->StartOverTimer();
	}
	if (attack3->Seconds() > 6)
	{
		std::cout << "Attack3" << std::endl;
		Bullet* bullet = new Bullet();
		bullet->position = this->position;
		bullet->position.y += 200;
		bullet->scale = glm::vec3(1.0f, 1.0f, 1.0f);
		bullet->speedx = -200.0f;
		bullet->health = 1;
		bullets.push_back(bullet);
		this->parent->AddChild(bullet);
		attack3->StartOverTimer();
	}

	if (this->position.x >= 1000.0f)
	{
		this->position -= glm::vec3(100.0f, 0.0f, 0.0f) * deltaTime;
	}
}