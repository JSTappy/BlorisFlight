#ifndef ENEMY_H
#define ENEMY_H

#include <common/entity.h>
#include <common/timer.h>
#include <Bloris/Bullet.h>

class Enemy : public Entity
{
public:
	Enemy();
	virtual ~Enemy();

	virtual void update(float deltaTime);

	int health;

	std::vector <Bullet*> bullets;
private:
	Bullet* bullet;
	Timer* timer = 0;
	Timer* hitdelay = 0;
};

#endif /* ENEMY_H */
