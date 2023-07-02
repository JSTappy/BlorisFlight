#ifndef MEDIUMBIRD_H
#define MEDIUMBIRD_H

#include <Bloris/Enemy.h>

class MediumBird : public Enemy
{
public:
	MediumBird();
	virtual ~MediumBird();

	virtual void update(float deltaTime);

private:
	Timer* timer;
	bool damaged;
};

#endif /* MEDIUMBIRD_H */
