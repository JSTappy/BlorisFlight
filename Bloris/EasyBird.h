#ifndef EASYBIRD_H
#define EASYBIRD_H

#include <Bloris/Enemy.h>

class EasyBird : public Enemy
{
public:
	EasyBird();
	virtual ~EasyBird();

	virtual void update(float deltaTime);

private:
	Timer* shotdelay;
	bool damaged;
};

#endif /* EASYBIRD_H */
