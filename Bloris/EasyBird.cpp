#include <Bloris/EasyBird.h>

EasyBird::EasyBird()
{
	this->AddSprite("assets/easybird/enemy1.tga");
	shotdelay = new Timer();
	health = 50;
	this->AddChild(shotdelay);
}

EasyBird::~EasyBird()
{

}

void EasyBird::update(float deltaTime)
{
	if (shotdelay->Seconds() > 3)
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
	this->position -= glm::vec3(100.0f, 0.0f, 0.0f) * deltaTime;
}