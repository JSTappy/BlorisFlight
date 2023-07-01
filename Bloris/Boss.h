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
	Timer* attack1;
	Timer* attack2;
	Timer* attack3;
	Timer* attack4;
	bool damaged;
	bool damaged2;
};

#endif /* BOSS_H */
