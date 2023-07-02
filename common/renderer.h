#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <common/scene.h>
#include <common/camera.h>
#include <common/sprite.h>
#include <common/resourcemanager.h>
#include <common/inputmanager.h>

 /// @brief The Renderer Class will make sure that everything will render correctly
class Renderer
{
public:
	/// @brief constructor
	Renderer(); 

	/// @brief destructor
	virtual ~Renderer(); 

	/// @brief Renders the Scene including childeren
	/// @param scene the scene that has to be rendered
	/// @return void
	void renderScene(Scene* scene); 

	/// @brief Renders the Entities including Sprites
	/// @param entity the entity that has to be rendered
	/// @return void
	void renderEntity(Entity* entity); 

	/// @brief Renders the Sprites
	/// @param sprite the sprite that has to be rendered
	/// @return void
	void renderSprite(Sprite* sprite); 

	/// @brief _window getter
	/// @return _window
	GLFWwindow* window() { return _window; }; 

	/// @brief method for updating deltatime
	/// @return float
	float updateDeltaTime(); 


private:
	// Only renderer needs access to the ResourceManager
	/// @brief The ResourceManager of the Renderer
	ResourceManager _resman; 

	/// @brief initialisation method of renderer
	int init(); 

	/// @brief private member window
	GLFWwindow* _window; 

	/// @brief method for loading shaders
	/// @param vertex_file_path, fragment_file_path
	/// @return GLUint
	GLuint loadShaders(
		const std::string& vertex_file_path,
		const std::string& fragment_file_path
	); 

	/// @brief this will be the Program ID
	GLuint _programID; 

	/// @brief reference to scene->camera
	Camera* _camera; 
};

#endif /* RENDERER_H */
