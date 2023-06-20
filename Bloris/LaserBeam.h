#ifndef LASERBEAM_H
#define LASERBEAM_H

#include <Bloris/Bullet.h>
#include <iostream>
#include <vector>

class LaserBeam : public Bullet
{
public:
	LaserBeam();
	virtual ~LaserBeam();

	virtual void update(float deltaTime);

private:

};

#endif /* LASERBEAM_H */
