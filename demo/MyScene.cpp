#include <demo/myscene.h>

MyScene::MyScene() : Scene()
{
	player = new Player();
	player->AddSprite("assets/kingkong.tga");
	player->position = glm::vec3(200.0f, 300.0f, 0.0f);
	this->AddChild(player);
}

MyScene::~MyScene()
{
	
}

void MyScene::update(float deltaTime)
{
	for (int i = player->bullets.size() - 1; i >= 0; i--) { // backwards!!!
		Bullet* bullet = player->bullets[i]; // make the player bullets list into a local variable so its easier to type out
		if (bullet != nullptr)
		{
			if (bullet->position.x > WIDTH || bullet->position.x < 0 || bullet->position.y < 0 || bullet->position.y > HEIGHT) {
				bullet->dead = true;
			}
		}
		//remove the bullets from the scene and the memory
		if (bullet->dead && bullet != nullptr) {
			this->RemoveChild(bullet);
			delete bullet;
			bullet = nullptr;
			player->bullets.erase(player->bullets.begin() + i);
		}
	}
}
