#ifndef MYSCENE_H
#define MYSCENE_H

#include "common/scene.h"
#include "common/game.h"
#include "common/entity.h"
#include "Bloris/Player.h"
#include "Bloris/Enemy.h"
#include "Bloris/Spawner.h"
#include <cmath>

class MyScene : public Scene
{
public:
	MyScene();
	virtual ~MyScene();

	virtual void update(float deltaTime);

	std::vector <Enemy*> enemies;
	std::vector <Spawner*> spawners;

private:
	Player* player;
	Spawner* spawner;


};

#endif /* MYSCENE_H */
