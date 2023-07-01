#include <Bloris/Player.h>

Player::Player()
{
	bulletoffset = glm::vec3(0, 40.0f, 0);
	dead = false;
	_fireRate = 0;
	shootdelay = new Timer();
	beamdelay = new Timer();
	_speed = 200.0f;
	health = 3;
	maxHealth = 3;
	_level = 1;
	_bulletspeed = 400;
	_bulletdamage = 1;
	this->AddChild(beamdelay);
	this->AddChild(shootdelay);
	beamdelay->StopTimer();
	shootdelay->StopTimer();
}

Player::~Player()
{
	shootdelay = nullptr;
	beamdelay = nullptr;
}

void Player::update(float deltaTime)
{
	//Movement
	if (input()->GetKey(KEY_W))
	{
		this->position -= glm::vec3(0.0f, _speed, 0.0f) * deltaTime;
	}
	if (input()->GetKey(KEY_A))
	{
		this->position -= glm::vec3(_speed, 0.0f, 0.0f) * deltaTime;
	}
	if (input()->GetKey(KEY_S))
	{
		this->position += glm::vec3(0.0f, _speed, 0.0f) * deltaTime;
	}
	if (input()->GetKey(KEY_D))
	{
		this->position += glm::vec3(_speed, 0.0f, 0.0f) * deltaTime;
	}

	//Upgrades
	if (input()->GetKeyDown(KEY_Z))
	{
		UpgradeSpeed();
		//std::cout << "----------------" << std::endl;
		//std::cout << "SPD is now" << std::endl;
		//std::cout << speed << std::endl;
		//std::cout << "----------------" << std::endl;
	}
	if (input()->GetKeyDown(KEY_H))
	{
		UpgradeHitPoints();
		//std::cout << "----------------" << std::endl;
		//std::cout << "HP is now" << std::endl;
		//std::cout << health << std::endl;
		//std::cout << "----------------" << std::endl;
	}
	if (input()->GetKeyDown(KEY_Q))
	{
		UpgradeBulletDamage();
		//std::cout << "----------------" << std::endl;
		//std::cout << "BDMG is now" << std::endl;
		//std::cout << bulletdamage << std::endl;
		//std::cout << "----------------" << std::endl;
	}
	if (input()->GetKeyDown(KEY_E))
	{
		UpgradeBulletSpeed();
		//std::cout << "----------------" << std::endl;
		//std::cout << "BSPD is now" << std::endl;
		//std::cout << bulletspeed << std::endl;
		//std::cout << "----------------" << std::endl;
	}
	if (input()->GetKeyDown(KEY_X))
	{
		UpgradeBalloon();
		//std::cout << "----------------" << std::endl;
		//std::cout << "Upgraded Balloon to Level" << std::endl;
		//std::cout << level << std::endl;
		//std::cout << "----------------" << std::endl;
	}

	//Shooting bullets & LaserBeam
	if (input()->GetKeyDown(Space))
	{
		beamdelay->StartOverTimer();
		Shoot();	
		std::cout << beamdelay->Seconds() << std::endl;
	}
	if (input()->GetKey(Space))
	{
	/*	std::cout << beamdelay->Seconds() << std::endl;*/
		if (beamdelay->Seconds() >= 1)
		{
			this->sprite = new Sprite("assets/pencils.tga");
		}
	}
	if (input()->GetKeyUp(Space) && beamdelay->Seconds() >= 1)
	{
		beamdelay->StopTimer();
		ShootBeam();
		this->sprite = new Sprite("assets/Balloon.tga");

	}
}

void Player::ShootBeam()
{
	Bullet* sphere = new Bullet();
	sphere->AddSprite("assets/Sphere.tga");
	bulletoffset = glm::vec3(20.0f, 40.0f, 0);
	sphere->position = this->position + bulletoffset;
	sphere->speedx = 200;
	sphere->damage = 1;
	sphere->health = 100;
	bullets.push_back(sphere);
	this->parent->AddChild(sphere);
}


void Player::Shoot() 
{
	if (_level == 1)
	{
		Bullet* bullet = new Bullet();
		bullet->position = this->position + bulletoffset;
		bullet->speedx = _bulletspeed;
		bullet->damage = _bulletdamage;
		bullets.push_back(bullet);
		this->parent->AddChild(bullet);
		
	}
	if (_level == 2)
	{
		Bullet* bullet = new Bullet();
		bullet->position = this->position + bulletoffset;
		bullet->speedx = _bulletspeed;
		bullet->speedy = _bulletspeed / 2;
		bullet->damage = _bulletdamage;
		bullet->health = 2;
		bullets.push_back(bullet);
		this->parent->AddChild(bullet);

		Bullet* bullet2 = new Bullet();
		bullet2->position = this->position + bulletoffset;
		bullet2->speedx = _bulletspeed;
		bullet2->damage = _bulletdamage;
		bullet2->health = 2;
		bullets.push_back(bullet2);
		this->parent->AddChild(bullet2);
	}
	if (_level == 3)
	{
		Bullet* bullet = new Bullet();
		bullet->position = this->position + bulletoffset;
		bullet->speedx = _bulletspeed;
		bullet->speedy = _bulletspeed /2;
		bullet->damage = _bulletdamage;
		bullet->health = 3;
		bullets.push_back(bullet);
		this->parent->AddChild(bullet);

		Bullet* bullet2 = new Bullet();
		bullet2->position = this->position + bulletoffset;
		bullet2->speedx = _bulletspeed;
		bullet2->damage = _bulletdamage;
		bullet2->health = 3;
		bullets.push_back(bullet2);
		this->parent->AddChild(bullet2);

		Bullet* bullet3 = new Bullet();
		bullet3->position = this->position + bulletoffset;
		bullet3->speedx = _bulletspeed;
		bullet3->speedy = -_bulletspeed /2;
		bullet3->damage = _bulletdamage;
		bullet3->health = 3;
		bullets.push_back(bullet3);
		this->parent->AddChild(bullet3);
	}
	if (_level == 4)
	{
		Bullet* bullet = new Bullet();
		bullet->position = this->position + bulletoffset;
		bullet->speedx = _bulletspeed;
		bullet->speedy = _bulletspeed /2;
		bullet->damage = _bulletdamage;
		bullet->health = 5;
		bullets.push_back(bullet);
		this->parent->AddChild(bullet);

		Bullet* bullet2 = new Bullet();
		bullet2->position = this->position + bulletoffset;
		bullet2->speedx = _bulletspeed;
		bullet2->damage = _bulletdamage;
		bullet2->health = 5;
		bullets.push_back(bullet2);
		this->parent->AddChild(bullet2);

		Bullet* bullet3 = new Bullet();
		bullet3->position = this->position + bulletoffset;
		bullet3->speedx = _bulletspeed;
		bullet3->speedy = -_bulletspeed /2;
		bullet3->damage = _bulletdamage;
		bullet3->health = 5;
		bullets.push_back(bullet3);
		this->parent->AddChild(bullet3);

		Bullet* bullet4 = new Bullet();
		bulletoffset = glm::vec3(-10.0f, 40.0f, 0);
		bullet4->position = this->position + bulletoffset;
		bullet4->speedx = -_bulletspeed;
		bullet4->damage = _bulletdamage;
		bullet4->health = 5;
		bullets.push_back(bullet4);
		this->parent->AddChild(bullet4);
	}


}
int Player::UpgradeBalloon() 
{
	if (_level == 4)
	{
		std::cout << "MAXED OUT BALLOON" << std::endl;
		return _level;
	}
	_level += 1;
	return _level;
}
int Player::UpgradeBulletSpeed()
{
	if (_bulletspeed == 1000)
	{
		std::cout << "MAXED OUT BSPD" << std::endl;
		return _bulletspeed;
	}
	_bulletspeed += 100;
	return _bulletspeed;
}
int Player::UpgradeBulletDamage()
{
	if (_bulletdamage == 6)
	{
		std::cout << "MAXED OUT BDMG" << std::endl;
		return _bulletdamage;
	}
	_bulletdamage += 1;
	return _bulletdamage;
}
int Player::UpgradeFireRate()
{
	if (_fireRate == 6)
	{
		std::cout << "MAXED OUT FR" << std::endl;
		return _fireRate;
	}
	_fireRate += 1;
	return _fireRate;
}

int Player::UpgradeHitPoints()
{
	if (maxHealth == 6)
	{
		std::cout << "MAXED OUT HP" << std::endl;
		return maxHealth;
	}
	maxHealth += 1;
	return maxHealth;
}
int Player::UpgradeSpeed()
{
	if (_speed == 500.0f)
	{
		std::cout << "MAXED OUT SPD" << std::endl;
		return _speed;
	}
	_speed += 50.0f;
	return _speed;
}