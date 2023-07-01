#include <demo/myscene.h>

MyScene::MyScene() : Scene()
{
	
	player = new Player();
	player->AddSprite("assets/player/Balloon.tga");
	player->position = glm::vec3(200.0f, 300.0f, 0.0f);
	this->AddChild(player);

	spawner = new Spawner();
	spawner->AddSprite("assets/rgba.tga");
	spawner->position = glm::vec3(1280.0f, 360.0f, 0.0f);
	spawners.push_back(spawner);
	this->AddChild(spawner);

	redButton = new TestEntity();
	redButton->AddSprite("assets/buttons/redbtn.tga");
	redButton->position = glm::vec3(75.0f, 675.0f, 0.0f);
	this->AddChild(redButton);

	/*greenButton = new TestEntity();
	greenButton->AddSprite("assets/buttons/greenbtn.tga");
	greenButton->position = glm::vec3(150.0f, 675.0f, 0.0f);
	this->AddChild(greenButton);*/
	

	blueButton = new TestEntity();
	blueButton->AddSprite("assets/buttons/bluebtn.tga");
	blueButton->position = glm::vec3(225.0f, 675.0f, 0.0f);
	this->AddChild(blueButton);

	yellowButton = new TestEntity();
	yellowButton->AddSprite("assets/buttons/yellowbtn.tga");
	yellowButton->position = glm::vec3(300.0f, 675.0f, 0.0f);
	this->AddChild(yellowButton);

	pinkButton = new TestEntity();
	pinkButton->AddSprite("assets/buttons/pinkbtn.tga");
	pinkButton->position = glm::vec3(375.0f, 675.0f, 0.0f);
	this->AddChild(pinkButton);

	purpleButton = new TestEntity();
	purpleButton->AddSprite("assets/buttons/purplebtn.tga");
	purpleButton->position = glm::vec3(450.0f, 675.0f, 0.0f);
	this->AddChild(purpleButton);

	redDigit = new TestEntity();
	redDigit->AddSprite("assets/buttons/1.tga");
	redDigit->position = glm::vec3(95.0f, 660.0f, 0.0f);
	this->AddChild(redDigit);

	/*greenDigit = new TestEntity();
	greenDigit->AddSprite("assets/buttons/1.tga");
	greenDigit->position = glm::vec3(165.0f, 660.0f, 0.0f);
	this->AddChild(greenDigit);*/

	blueDigit = new TestEntity();
	blueDigit->AddSprite("assets/buttons/1.tga");
	blueDigit->position = glm::vec3(245.0f, 660.0f, 0.0f);
	this->AddChild(blueDigit);

	yellowDigit = new TestEntity();
	yellowDigit->AddSprite("assets/buttons/1.tga");
	yellowDigit->position = glm::vec3(320.0f, 660.0f, 0.0f);
	this->AddChild(yellowDigit);

	pinkDigit = new TestEntity();
	pinkDigit->AddSprite("assets/buttons/1.tga");
	pinkDigit->position = glm::vec3(395.0f, 660.0f, 0.0f);
	this->AddChild(pinkDigit);

	purpleDigit = new TestEntity();
	purpleDigit->AddSprite("assets/buttons/1.tga");
	purpleDigit->position = glm::vec3(470.0f, 660.0f, 0.0f);
	this->AddChild(purpleDigit);
}

MyScene::~MyScene()
{

}

void MyScene::update(float deltaTime)
{
	if (player->health <= 0)
	{
		player->dead = true;
		std::cout << "Rip je leven man in het echte leven heb je ook geen game over" << std::endl;
	}

	for (int i = player->bullets.size() - 1; i >= 0; i--) { // backwards!!!
		Bullet* bullet = player->bullets[i];
		for (int e = spawners.size() - 1; e >= 0; e--) {
			for (int i = spawners[e]->enemies.size() - 1; i >= 0; i--) {
				Enemy* enemy = spawners[e]->enemies[i];

				glm::vec2 enemypos(enemy->position.x, enemy->position.y);
				glm::vec2 bulletpos(bullet->position.x, bullet->position.y);

				if (bullet->position.x > WIDTH || bullet->position.x < 0 || bullet->position.y < 0 || bullet->position.y > HEIGHT) {
					bullet->dead = true;
				}
				if (glm::distance(enemypos, bulletpos) < 64) {
					enemy->health -= bullet->damage;
					bullet->health -= 1;
				}
				if (bullet->health <= 0) {
					bullet->dead = true;
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
			for (int b = enemy->bullets.size() - 1; b >= 0; b--) {
				Bullet* bullet = enemy->bullets[b];
				glm::vec2 bulletpos(bullet->position.x, bullet->position.y);
				glm::vec2 playerpos(player->position.x, player->position.y);

				if (bullet->dead && bullet != nullptr) {
					delete bullet;
					this->RemoveChild(bullet);
					bullet = nullptr;
					enemy->bullets.erase(enemy->bullets.begin() + b);
					return;
				}
				if (bullet->position.x > WIDTH || bullet->position.x < 0 || bullet->position.y < 0 || bullet->position.y > HEIGHT) {
					bullet->dead = true;
				}
				if (glm::distance(playerpos, bulletpos) < 64) {
					player->health -= bullet->damage;
					bullet->dead = true;
				}
				if (bullet->health <= 0) {
					bullet->dead = true;
				}
			}

			if (enemy->health <= 0) {
				spawner->killed += 1;
				this->RemoveChild(enemy);
				delete enemy;
				enemy = nullptr;
				spawners[e]->enemies.erase(spawners[e]->enemies.begin() + i);
				player->magicPoint += 1;
				return;
			}
			if (enemy->position.x < 0) {
				std::cout << "Enemy Out of Screen" << std::endl;
				player->health -= 1;
				this->RemoveChild(enemy);
				delete enemy;
				enemy = nullptr;
				spawners[e]->enemies.erase(spawners[e]->enemies.begin() + i);
			}

		}
		//Leveling Up
		if (player->Level() == 2)
		{
			purpleDigit->ChangeSprite("assets/buttons/2.tga");
		}
		if (player->Level() == 3)
		{
			purpleDigit->ChangeSprite("assets/buttons/3.tga");
		}
		if (player->Level() == 4)
		{
			purpleDigit->ChangeSprite("assets/buttons/MX.tga");
		}
		////////

		//Player Speed
		if (player->Speed() == 250.0f)
		{
			yellowDigit ->ChangeSprite("assets/buttons/2.tga");
		}
		if (player->Speed() == 300.0f)
		{
			yellowDigit->ChangeSprite("assets/buttons/3.tga");
		}
		if (player->Speed() == 350.0f)
		{
			yellowDigit->ChangeSprite("assets/buttons/4.tga");
		}
		if (player->Speed() == 400.0f)
		{
			yellowDigit->ChangeSprite("assets/buttons/5.tga");
		}
		if (player->Speed() == 450.0f)
		{
			yellowDigit->ChangeSprite("assets/buttons/6.tga");
		}
		if (player->Speed() == 500.0f)
		{
			yellowDigit->ChangeSprite("assets/buttons/MX.tga");
		}
		////////

		//Player HP
		if (player->maxHealth == 4)
		{
			pinkDigit->ChangeSprite("assets/buttons/2.tga");
		}
		if (player->maxHealth == 5)
		{
			pinkDigit->ChangeSprite("assets/buttons/3.tga");
		}
		if (player->maxHealth == 6)
		{
			pinkDigit->ChangeSprite("assets/buttons/MX.tga");
		}
		////////

		//BulletSpeed
		if (player->BulletSpeed() == 500)
		{
			blueDigit->ChangeSprite("assets/buttons/2.tga");
		}
		if (player->BulletSpeed() == 600)
		{
			blueDigit->ChangeSprite("assets/buttons/3.tga");
		}
		if (player->BulletSpeed() == 700)
		{
			blueDigit->ChangeSprite("assets/buttons/4.tga");
		}
		if (player->BulletSpeed() == 800)
		{
			blueDigit->ChangeSprite("assets/buttons/5.tga");
		}
		if (player->BulletSpeed() == 900)
		{
			blueDigit->ChangeSprite("assets/buttons/6.tga");
		}
		if (player->BulletSpeed() == 1000)
		{
			blueDigit->ChangeSprite("assets/buttons/MX.tga");
		}
		////////

		//BulletDamage
		if (player->BulletDamage() == 2)
		{
			redDigit->ChangeSprite("assets/buttons/2.tga");
		}
		if (player->BulletDamage() == 3)
		{
			redDigit->ChangeSprite("assets/buttons/3.tga");
		}
		if (player->BulletDamage() == 4)
		{
			redDigit->ChangeSprite("assets/buttons/4.tga");
		}
		if (player->BulletDamage() == 5)
		{
			redDigit->ChangeSprite("assets/buttons/5.tga");
		}
		if (player->BulletDamage() == 6)
		{
			redDigit->ChangeSprite("assets/buttons/MX.tga");
		}
		////////

		//FireRate
		//if (player->FireRate() == 0.7f)
		//{
		//	greenDigit->ChangeSprite("assets/buttons/2.tga");
		//}
		//if (player->FireRate() == 0.6f)
		//{
		//	greenDigit->ChangeSprite("assets/buttons/3.tga");
		//}
		//if (player->FireRate() == 0.5f)
		//{
		//	greenDigit->ChangeSprite("assets/buttons/4.tga");
		//}
		//if (player->FireRate() == 0.4f)
		//{
		//	greenDigit->ChangeSprite("assets/buttons/5.tga");
		//}
		//if (player->FireRate() == 0.3f)
		//{
		//	greenDigit->ChangeSprite("assets/buttons/6.tga");
		//}
		//if (player->FireRate() == 0.2f)
		//{
		//	greenDigit->ChangeSprite("assets/buttons/MX.tga");
		//}
		
		if (spawner->killed == 25)
		{
			TestEntity* winScreen = new TestEntity();
			winScreen->AddSprite("assets/boss/WinScreen.tga");
			winScreen->position = glm::vec3(600.0f, 300.0f, 0.0f);
			this->AddChild(winScreen);
		}
	}
}

