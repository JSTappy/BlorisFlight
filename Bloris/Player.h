#ifndef PLAYER_H
#define PLAYER_H

#include <common/entity.h>
#include <common/timer.h>
#include <Bloris/Bullet.h>
#include <Bloris/LaserBeam.h>

class Player : public Entity
{
public:
	Player();
	virtual ~Player();

	virtual void update(float deltaTime);

	std::vector <Bullet*> bullets;
private:
	Timer* shootdelay;
	Timer* beamdelay;
	float speed;
	float fireRate;
	int health;
	int level;

	float bulletspeed;
	int bulletdamage;

	void Shoot();
	void ShootBeam();


	int UpgradeBalloon();

	int UpgradeBulletSpeed();

	int UpgradeBulletDamage();

	int UpgradeFireRate();

	int UpgradeHitPoints();

	int UpgradeSpeed();
};

#endif /* PLAYER_H */
