#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <common/scene.h>
#include <common/camera.h>
#include <common/sprite.h>
#include <common/resourcemanager.h>
#include <common/inputmanager.h>

class Renderer
{
public:
	Renderer(); //constructor
	virtual ~Renderer(); //destructor

	void renderScene(Scene* scene); //method for rendering the scene
	void renderSprite(Sprite* sprite); //method for rendering the sprite
	void renderEntity(Entity* entity); /*not yet implemented method for rendering the entities*/
	GLFWwindow* window() { return _window; }; //this is for getting the private member '_window'

	float updateDeltaTime(); //update method for renderer

private:
	// Only renderer needs access to the ResourceManager
	ResourceManager _resman; ///< @brief The ResourceManager of the Renderer
	int init(); //initialisation method of renderer

	GLFWwindow* _window; //private member window

	GLuint loadShaders(
		const std::string& vertex_file_path,
		const std::string& fragment_file_path
	); //method for loading shaders

	GLuint _programID; 

	Camera* _camera; // reference to scene->camera
};

#endif /* RENDERER_H */
