#include <Bloris/EasyBird.h>

EasyBird::EasyBird()
{
	this->AddSprite("assets/easybird/enemy1.tga");
	timer = new Timer();
	health = 10;
	this->AddChild(timer);
	damaged = false;
}

EasyBird::~EasyBird()
{

}

void EasyBird::update(float deltaTime)
{
	if (this->health == 4 && !damaged)
	{
		this->sprite = new Sprite("assets/easybird/enemy1dmg.tga");
		damaged = true;
		
	}
	if (this->health == 1 && damaged)
	{
		this->sprite = new Sprite("assets/easybird/enemy1oh.tga");
		damaged = false;
	}

	if (timer->Seconds() > 3)
	{
		std::cout << this->health << std::endl;
		Bullet* bullet = new Bullet();
		bullet->position = this->position;
		bullet->scale = glm::vec3(0.5f, 0.5f, 0.5f);
		bullet->speedx = -300.0f;
		bullets.push_back(bullet);
		this->parent->AddChild(bullet);
		timer->StartOverTimer();
	}
	this->position -= glm::vec3(100.0f, 0.0f, 0.0f) * deltaTime;
}