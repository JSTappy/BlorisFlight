#ifndef TESTENTITY_H
#define TESTENTITY_H

#include <common/entity.h>

class TestEntity : public Entity
{
public:
	TestEntity(); //constructor
	~TestEntity(); //destructor

	virtual void update(float deltaTime); //update

private:

};
#endif // !TESTENTITY_H
