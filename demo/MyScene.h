#ifndef MYSCENE_H
#define MYSCENE_H

#include "common/scene.h"
#include "common/game.h"
#include "common/entity.h"
#include "common/timer.h"
#include "Bloris/Player.h"
#include "Bloris/Enemy.h"
#include "Bloris/Spawner.h"
#include "Bloris/TestEntity.h"

class MyScene : public Scene
{
public:
	MyScene();
	virtual ~MyScene();

	virtual void update(float deltaTime);

	std::vector <Enemy*> enemies;
	std::vector <Spawner*> spawners;
	std::vector <TestEntity*> buttons;
	Player* getPlayer() { return player; };

private:

	TestEntity* redButton;
	TestEntity* redDigit;

	//TestEntity* greenButton;
	//TestEntity* greenDigit;

	TestEntity* blueButton;
	TestEntity* blueDigit;

	TestEntity* yellowButton;
	TestEntity* yellowDigit;

	TestEntity* pinkButton;
	TestEntity* pinkDigit;

	TestEntity* purpleButton;
	TestEntity* purpleDigit;

	Player* player;

	Spawner* spawner;


};

#endif /* MYSCENE_H */
