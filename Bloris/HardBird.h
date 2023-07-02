#ifndef HARDBIRD_H
#define HARDBIRD_H

#include <Bloris/Enemy.h>

/// @brief The HardBird implementation.
class HardBird : public Enemy
{
public:
	HardBird();
	virtual ~HardBird();

	virtual void update(float deltaTime);

private:
	Timer* shotdelay;
	Timer* timer;
	bool damaged;
};

#endif /* HARDBIRD_H */
