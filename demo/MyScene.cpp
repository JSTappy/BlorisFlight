#include <demo/myscene.h>

MyScene::MyScene() : Scene()
{
	player = new TestEntity();
	player->AddSprite("assets/rgba.tga");
	player->position = glm::vec3(200.0f, 300.0f, 0.0f);
	this->AddChild(player);
}

MyScene::~MyScene()
{
	
}

void MyScene::update(float deltaTime)
{
	player->position -= glm::vec3(100.0f, 0.0f, 0.0f) * deltaTime;
	player->rotation += 7.0f * deltaTime;
}
