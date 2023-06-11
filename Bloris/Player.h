#ifndef PLAYER_H
#define PLAYER_H

#include <common/entity.h>
#include <Bloris/Bullet.h>

class Player : public Entity
{
public:
	Player();
	virtual ~Player();

	virtual void update(float deltaTime);

	std::vector <Bullet*> bullets;
private:
	Bullet* bullet;
};

#endif /* PLAYER_H */
