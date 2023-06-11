#ifndef GAME_H 
#define GAME_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <common/config.h>
#include <common/renderer.h>
#include <common/camera.h>

class Game
{
public:
	Game(); //constructor
	virtual ~Game(); //destructor

	void Run(Scene* scene); //method for running the scene

	InputManager* _inMan = InputManager::input(); //for instantiating the input
	void UpdateEntity(Entity* e, float deltaTime);
	bool IsRunning() { return running; } //this is for getting the private boolean 'runnning'

private:
	Renderer renderer; //private renderer, we only need renderer in game
	bool running; //private boolean to check if the game is running
};

#endif // GAME_H 