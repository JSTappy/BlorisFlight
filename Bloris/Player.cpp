#include <Bloris/Player.h>

Player::Player()
{
	bullet = nullptr;
}

Player::~Player()
{

}

void Player::update(float deltaTime)
{
	if (input()->GetKey(KEY_W))
	{
		this->position -= glm::vec3(0.0f, 100.0f, 0.0f) * deltaTime;
	}
	if (input()->GetKey(KEY_A))
	{
		this->position -= glm::vec3(100.0f, 0.0f, 0.0f) * deltaTime;
	}
	if (input()->GetKey(KEY_S))
	{
		this->position += glm::vec3(0.0f, 100.0f, 0.0f) * deltaTime;
	}
	if (input()->GetKey(KEY_D))
	{
		this->position += glm::vec3(100.0f, 0.0f, 0.0f) * deltaTime;
	}
	if (input()->GetKeyDown(Space))
	{
		bullet = new Bullet();
		bullet->position = this->position;
		bullets.push_back(bullet);
		this->parent->AddChild(bullet);
		std::cout << "Shoot" << std::endl;
	}
}