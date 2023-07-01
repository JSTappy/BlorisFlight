#include <Bloris/TestEntity.h>

TestEntity::TestEntity() //Test to test
{
	
}

TestEntity::~TestEntity()
{

}

void TestEntity::update(float deltaTime)
{
}

void TestEntity::ChangeSprite(const std::string& imagepath)
{
	this->sprite = new Sprite(imagepath);
}
