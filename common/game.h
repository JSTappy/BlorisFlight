/**
 * @file game.h
 *
 * @brief The game header file.
 *
 *
 * - Copyright 2023 Joas Sahetapy
 *
 */


#ifndef GAME_H 
#define GAME_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <common/config.h>
#include <common/renderer.h>
#include <common/camera.h>

 /// @brief the Game class is the class that will make sure that the scene is running correctly
class Game
{
public:
	/// @brief constructor
	Game();

	/// @brief destructor
	virtual ~Game(); 

	/// @brief method for running the scene
	/// @param scene the scene
	/// @return void
	void Run(Scene* scene); 

	/// @brief for instantiating the input
	InputManager* _inMan = InputManager::input(); 

	/// @brief Update Entity method
	/// @param e, deltaTime the entity you want to update, deltaTime
	/// @return void
	void UpdateEntity(Entity* e, float deltaTime); 

	/// @brief this is for getting the private boolean 'runnning'
	/// @return running
	bool IsRunning() { return running; } 


private:
	/// @brief renderer, we only need renderer in game
	Renderer renderer; 

	/// @brief private boolean to check if the game is running
	bool running; 
};

#endif // GAME_H 