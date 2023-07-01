#ifndef PLAYER_H
#define PLAYER_H

#include <common/entity.h>
#include <common/timer.h>
#include <Bloris/Bullet.h>

class Player : public Entity
{
public:
	Player();
	virtual ~Player();

	virtual void update(float deltaTime);
	
	float Speed() { return _speed; };
	float BulletSpeed() { return _bulletspeed; };
	float BulletDamage() { return _bulletdamage; };
	float FireRate() { return _fireRate; };
	int Level() { return _level; };

	glm::vec3 bulletoffset;
	int magicPoint;

	bool dead;
	int health;
	int maxHealth;

	std::vector <Bullet*> bullets;
private:
	Timer* shootdelay;
	Timer* beamdelay;
	
	
	float _speed;
	float _bulletspeed;
	float _bulletdamage;
	float _fireRate;
	int _level;


	void Shoot();
	void ShootBeam();


	int UpgradeBalloon();

	int UpgradeBulletSpeed();

	int UpgradeBulletDamage();

	float UpgradeFireRate();

	int UpgradeHitPoints();

	float UpgradeSpeed();
};

#endif /* PLAYER_H */
