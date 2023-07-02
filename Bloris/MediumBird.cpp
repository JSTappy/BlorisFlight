#include <Bloris/MediumBird.h>

MediumBird::MediumBird()
{
	this->AddSprite("assets/pencils.tga");
	timer = new Timer();
	health = 50;
	this->AddChild(timer);
	damaged = false;
}

MediumBird::~MediumBird()
{

}

void MediumBird::update(float deltaTime)
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

	if (timer->Seconds() > 1)
	{
		std::cout << this->health << std::endl;
		Bullet* bullet = new Bullet();
		bullet->AddSprite("assets/easybird/enemybullet.tga");
		bullet->position = this->position;
		bullet->scale = glm::vec3(2, 2, 2);
		bullet->speedx = -300.0f;
		bullet->health = 1;
		bullets.push_back(bullet);
		this->parent->AddChild(bullet);
		timer->StartOverTimer();
	}
	this->position -= glm::vec3(100.0f, 0.0f, 0.0f) * deltaTime;
}