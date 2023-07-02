#include "game.h" 

Game::Game()
{
	running = false;
}
Game::~Game()
{

}

void Game::Run(Scene* scene)
{
	// get deltaTime and update camera
	float dt = renderer.updateDeltaTime();
	scene->camera()->computeViewMatrixFromInput(renderer.window(), dt);
	_inMan->InputUpdate(renderer.window());

	this->UpdateEntity(scene, dt);
	
	// Render the scene
	renderer.renderScene(scene);

	if (glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(renderer.window()) == 0)
	{
		running = true;
	}
	else
	{
		running = false;
	}

}
void Game::UpdateEntity(Entity* e, float deltaTime)
{
	e->update(deltaTime);
	for (Entity* ce : e->Children())
	{
		UpdateEntity(ce, deltaTime);
	}
}