#include <demo/myscene.h>

MyScene::MyScene() : Scene()
{
	player = new Player();
	player->AddSprite("assets/kingkong.tga");
	player->position = glm::vec3(200.0f, 300.0f, 0.0f);
	this->AddChild(player);


	spawner = new Spawner();
	spawner->AddSprite("assets/rgba.tga");
	spawner->position = glm::vec3(2000.0f, 300.0f, 0.0f);
	spawners.push_back(spawner);
	this->AddChild(spawner);
}

MyScene::~MyScene()
{
	this->RemoveChild(player);
	this->RemoveChild(spawner);

	delete player;
	delete spawner;

	player = nullptr;
	spawner = nullptr;
}

void MyScene::update(float deltaTime)
{
	for (int i = player->bullets.size() - 1; i >= 0; i--) { // backwards!!!
		Bullet* bullet = player->bullets[i];
		for (int e = spawners.size() - 1; e >= 0; e--) {
			for (int i = spawners[e]->enemies.size() - 1; i >= 0; i--) {
				Enemy* enemy = spawners[e]->enemies[i];

				glm::vec2 enemypos(enemy->position.x, enemy->position.y);
				glm::vec2 bulletpos(bullet->position.x, bullet->position.y);
				float dyingDistance = 64.0f;

				if (bullet->position.x > WIDTH || bullet->position.x < 0 || bullet->position.y < 0 || bullet->position.y > HEIGHT) {
					bullet->dead = true;
				}
				if (glm::distance(enemypos, bulletpos) < dyingDistance)
				{
					bullet->dead = true;
					enemy->health -= bullet->damage;
					std::cout << enemy->health << std::endl;
				}
			}
		}
		if (bullet->dead && bullet != nullptr) {
			this->RemoveChild(bullet);
			delete bullet;
			bullet = nullptr;
			player->bullets.erase(player->bullets.begin() + i);
		}

	}
	for (int e = spawners.size() - 1; e >= 0; e--) {
		for (int i = spawners[e]->enemies.size() - 1; i >= 0; i--) {
			Enemy* enemy = spawners[e]->enemies[i];
			if (enemy->health <= 0) {
				this->RemoveChild(enemy);
				delete enemy;
				enemy = nullptr;
				spawners[e]->enemies.erase(spawners[e]->enemies.begin() + i);
				return;
			}
		}

	}
}
