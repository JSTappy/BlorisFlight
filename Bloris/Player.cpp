#include <Bloris/Player.h>

Player::Player()
{
	fireRate = 0;
	shootdelay = new Timer();
	beamdelay = new Timer();
	speed = 200.0f;
	health = 3;
	level = 1;
	bulletspeed = 400;
	bulletdamage = 1;
	this->AddChild(beamdelay);
	this->AddChild(shootdelay);
	beamdelay->StopTimer();
	shootdelay->StopTimer();
}

Player::~Player()
{

}

void Player::update(float deltaTime)
{
	//Movement
	if (input()->GetKey(KEY_W))
	{
		this->position -= glm::vec3(0.0f, speed, 0.0f) * deltaTime;
	}
	if (input()->GetKey(KEY_A))
	{
		this->position -= glm::vec3(speed, 0.0f, 0.0f) * deltaTime;
	}
	if (input()->GetKey(KEY_S))
	{
		this->position += glm::vec3(0.0f, speed, 0.0f) * deltaTime;
	}
	if (input()->GetKey(KEY_D))
	{
		this->position += glm::vec3(speed, 0.0f, 0.0f) * deltaTime;
	}


	if (input()->GetKeyDown(KEY_L))
	{
		UpgradeSpeed();
		std::cout << "----------------" << std::endl;
		std::cout << "SPD is now" << std::endl;
		std::cout << speed << std::endl;
		std::cout << "----------------" << std::endl;
	}
	if (input()->GetKeyDown(KEY_O))
	{
		UpgradeHitPoints();
		std::cout << "----------------" << std::endl;
		std::cout << "HP is now" << std::endl;
		std::cout << health << std::endl;
		std::cout << "----------------" << std::endl;
	}
	if (input()->GetKeyDown(KEY_K))
	{
		UpgradeBulletDamage();
		std::cout << "----------------" << std::endl;
		std::cout << "BDMG is now" << std::endl;
		std::cout << bulletdamage << std::endl;
		std::cout << "----------------" << std::endl;
	}
	if (input()->GetKeyDown(KEY_I))
	{
		UpgradeBulletSpeed();
		std::cout << "----------------" << std::endl;
		std::cout << "BSPD is now" << std::endl;
		std::cout << bulletspeed << std::endl;
		std::cout << "----------------" << std::endl;
	}
	if (input()->GetKeyDown(KEY_U))
	{
		UpgradeBalloon();
		std::cout << "----------------" << std::endl;
		std::cout << "Upgraded Balloon to Level" << std::endl;
		std::cout << level << std::endl;
		std::cout << "----------------" << std::endl;
	}
	if (input()->GetKeyDown(Space))
	{
		beamdelay->StartOverTimer();
		Shoot();	
		std::cout << beamdelay->Seconds() << std::endl;
	}
	if (input()->GetKey(Space))
	{
		std::cout << beamdelay->Seconds() << std::endl;
	}
	if (input()->GetKeyUp(Space) && beamdelay->Seconds() >= 2)
	{
		std::cout << "BEAAMMM" << std::endl;
		beamdelay->StopTimer();
		ShootBeam();

	}
}

void Player::ShootBeam()
{
	LaserBeam* laserbeam = new LaserBeam();
	laserbeam->position = this->position;
	bullets.push_back(laserbeam);
	this->parent->AddChild(laserbeam);
}


void Player::Shoot() 
{
	if (level == 1)
	{
		Bullet* bullet = new Bullet();
		bullet->position = this->position;
		bullet->speedx = bulletspeed;
		bullet->damage = bulletdamage;
		bullets.push_back(bullet);
		this->parent->AddChild(bullet);
		
	}
	if (level == 2)
	{
		Bullet* bullet = new Bullet();
		bullet->position = this->position;
		bullet->speedx = bulletspeed;
		bullet->speedy = bulletspeed;
		bullet->damage = bulletdamage;
		bullets.push_back(bullet);
		this->parent->AddChild(bullet);

		Bullet* bullet2 = new Bullet();
		bullet2->position = this->position;
		bullet2->speedx = bulletspeed;
		bullet2->damage = bulletdamage;
		bullets.push_back(bullet2);
		this->parent->AddChild(bullet2);
	}
	if (level == 3)
	{
		Bullet* bullet = new Bullet();
		bullet->position = this->position;
		bullet->speedx = bulletspeed;
		bullet->speedy = bulletspeed;
		bullet->damage = bulletdamage;
		bullets.push_back(bullet);
		this->parent->AddChild(bullet);

		Bullet* bullet2 = new Bullet();
		bullet2->position = this->position;
		bullet2->speedx = bulletspeed;
		bullet2->damage = bulletdamage;
		bullets.push_back(bullet2);
		this->parent->AddChild(bullet2);

		Bullet* bullet3 = new Bullet();
		bullet3->position = this->position;
		bullet3->speedx = bulletspeed;
		bullet3->speedy = -bulletspeed;
		bullet3->damage = bulletdamage;
		bullets.push_back(bullet3);
		this->parent->AddChild(bullet3);
	}
	if (level == 4)
	{
		Bullet* bullet = new Bullet();
		bullet->position = this->position;
		bullet->speedx = bulletspeed;
		bullet->speedy = bulletspeed;
		bullet->damage = bulletdamage;
		bullets.push_back(bullet);
		this->parent->AddChild(bullet);

		Bullet* bullet2 = new Bullet();
		bullet2->position = this->position;
		bullet2->speedx = bulletspeed;
		bullet2->damage = bulletdamage;
		bullets.push_back(bullet2);
		this->parent->AddChild(bullet2);

		Bullet* bullet3 = new Bullet();
		bullet3->position = this->position;
		bullet3->speedx = bulletspeed;
		bullet3->speedy = -bulletspeed;
		bullet3->damage = bulletdamage;
		bullets.push_back(bullet3);
		this->parent->AddChild(bullet3);

		Bullet* bullet4 = new Bullet();
		bullet4->position = this->position;
		bullet4->speedx = -bulletspeed;
		bullet4->damage = bulletdamage;
		bullets.push_back(bullet4);
		this->parent->AddChild(bullet4);
	}


}
int Player::UpgradeBalloon() 
{
	if (level == 4)
	{
		std::cout << "MAXED OUT BALLOON" << std::endl;
		return level;
	}
	level += 1;
	return level;
}
int Player::UpgradeBulletSpeed()
{
	if (bulletspeed == 1000)
	{
		std::cout << "MAXED OUT BSPD" << std::endl;
		return bulletspeed;
	}
	bulletspeed += 50;
	return bulletspeed;
}
int Player::UpgradeBulletDamage()
{
	if (bulletdamage == 6)
	{
		std::cout << "MAXED OUT BDMG" << std::endl;
		return bulletdamage;
	}
	bulletdamage += 1;
	return bulletdamage;
}
int Player::UpgradeFireRate()
{
	if (fireRate == 6)
	{
		std::cout << "MAXED OUT FR" << std::endl;
		return fireRate;
	}
	fireRate += 1;
	return fireRate;
}


int Player::UpgradeHitPoints()
{
	if (health == 6)
	{
		std::cout << "MAXED OUT HP" << std::endl;
		return health;
	}
	health += 1;
	return health;
}
int Player::UpgradeSpeed()
{
	if (speed == 500.0f)
	{
		std::cout << "MAXED OUT SPD" << std::endl;
		return speed;
	}
	speed += 50.0f;
	return speed;
}