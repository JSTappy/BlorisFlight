#ifndef BULLET_H
#define BULLET_H

#include <common/entity.h>
#include <iostream>
#include <vector>

class Bullet : public Entity
{
public:
	Bullet();
	virtual ~Bullet();

	float speedx;
	float speedy;
	int damage;
	int health;

	virtual void update(float deltaTime);
	bool dead;

private:

};

#endif /* BULLET_H */
