#ifndef MYSCENE_H
#define MYSCENE_H

#include "common/scene.h"
#include "common/game.h"
#include "common/entity.h"
#include "Bloris/Player.h"

class MyScene : public Scene
{
public:
	MyScene();
	virtual ~MyScene();

	virtual void update(float deltaTime);

private:
	Player* player;

};

#endif /* MYSCENE_H */
