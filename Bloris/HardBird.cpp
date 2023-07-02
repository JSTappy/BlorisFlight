#include <Bloris/HardBird.h>

HardBird::HardBird()
{
	this->AddSprite("assets/kingkong.tga");
	shotdelay = new Timer();
	timer = new Timer();
	health = 200;
	this->AddChild(shotdelay);
	this->AddChild(timer);
}

HardBird::~HardBird()
{

}

void HardBird::update(float deltaTime)
{
	if (shotdelay->Seconds() > 0.75)
	{
		std::cout << this->health << std::endl;
		Bullet* bullet = new Bullet();
		bullet->AddSprite("assets/easybird/enemybullet.tga");
		bullet->position = this->position;
		bullet->scale = glm::vec3(2, 2, 2);
		bullet->velocity.x = -300.0f;
		bullet->health = 1;
		bullets.push_back(bullet);
		this->parent->AddChild(bullet);
		shotdelay->StartOverTimer();
	}

	if (timer->Seconds() > 7)
	{
		timer->StartOverTimer();
	}
	if (timer->Seconds() > 6)
	{
		this->position -= glm::vec3(50.0f, 200.0f, 0.0f) * deltaTime;
		return;
	}
	if (timer->Seconds() > 5)
	{
		this->position -= glm::vec3(25.0f, -200.0f, 0.0f) * deltaTime;
		return;
	}
	if (timer->Seconds() > 4)
	{
		this->position -= glm::vec3(50.0f, 200.0f, 0.0f) * deltaTime;
		return;
	}
	if (timer->Seconds() > 3)
	{
		this->position -= glm::vec3(25.0f, -200.0f, 0.0f) * deltaTime;
		return;
	}
	if (timer->Seconds() > 2)
	{
		this->position -= glm::vec3(25.0f, 100.0f, 0.0f) * deltaTime;
		return;
	}
	if (timer->Seconds() > 1)
	{
		this->position -= glm::vec3(50.0f, -200.0f, 0.0f) * deltaTime;
		return;
	}
	if (timer->Seconds() > 0)
	{
		this->position -= glm::vec3(150.0f, 200.0f, 0.0f) * deltaTime;
		return;
	}
	

	this->position -= glm::vec3(200.0f, 0.0f, 0.0f) * deltaTime;
}