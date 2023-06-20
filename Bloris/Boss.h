#ifndef BOSS_H
#define BOSS_H

#include <Bloris/Enemy.h>

class Boss : public Enemy
{
public:
	Boss();
	virtual ~Boss();

	virtual void update(float deltaTime);

private:
	Timer* timer;
	bool damaged;
	bool damaged2;
};

#endif /* BOSS_H */
