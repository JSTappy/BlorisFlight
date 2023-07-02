/**
 * @file MyScene.h
 *
 * @brief The MyScene header file.
 *
 *
 * - Copyright 2023 Joas Sahetapy
 *
 */


#ifndef MYSCENE_H
#define MYSCENE_H

#include "common/scene.h"
#include "common/game.h"
#include "common/entity.h"
#include "common/timer.h"
#include "Bloris/Player.h"
#include "Bloris/Enemy.h"
#include "Bloris/Spawner.h"
#include "Bloris/TestEntity.h"

/// @brief The MyScene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();

	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update method
	/// @param deltaTime
	/// @return void
	virtual void update(float deltaTime);

	/// @brief List of Enemies
	std::vector <Enemy*> enemies;

	/// @brief player getter
	/// @return player
	Player* getPlayer() { return player; };

private:
	/// @brief Red Button Sprite
	TestEntity* redButton;

	/// @brief Red Digit for displaying the upgrade level
	TestEntity* redDigit;

	/// @brief Blue Sprite
	TestEntity* blueButton;

	/// @brief Blue Digit for displaying the upgrade level
	TestEntity* blueDigit;

	/// @brief Yellow Sprite
	TestEntity* yellowButton;

	/// @brief Yellow Digit for displaying the upgrade level
	TestEntity* yellowDigit;

	/// @brief Pink Sprite
	TestEntity* pinkButton;

	/// @brief Pink Digit for displaying the upgrade level
	TestEntity* pinkDigit;

	/// @brief Purple Sprite
	TestEntity* purpleButton;

	/// @brief Purple Digit for displaying the upgrade level
	TestEntity* purpleDigit;

	/// @brief the Player
	Player* player;

	/// @brief the Spawner
	Spawner* spawner;


};

#endif /* MYSCENE_H */
