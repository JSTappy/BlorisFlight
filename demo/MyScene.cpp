#include <demo/myscene.h>

MyScene::MyScene() : Scene()
{
	player = new Sprite("assets/kingkong.tga");
	player->position = glm::vec3(920.0f, 300.0f, 0.0f);
	this->addSprite(player);

	testy = new TestEntity();
	testy->AddSprite("assets/rgba.tga");
	testy->position = glm::vec3(200.0f, 300.0f, 0.0f);
	this->AddChild(testy);
}

MyScene::~MyScene()
{
	
}

void MyScene::update(float deltaTime)
{
	player->position -= glm::vec3(100.0f, 0.0f, 0.0f) * deltaTime;
	player->rotation += 7.0f * deltaTime;
}
