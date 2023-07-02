#ifndef HARDBIRD_H
#define HARDBIRD_H

#include <Bloris/Enemy.h>

class HardBird : public Enemy
{
public:
	HardBird();
	virtual ~HardBird();

	virtual void update(float deltaTime);

private:
	Timer* timer;
	bool damaged;
};

#endif /* HARDBIRD_H */
