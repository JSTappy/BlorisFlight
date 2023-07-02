#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> // glm::lookAt()

 /// @brief The Camera Class for a Camera in the scene
class Camera
{
public:
	/// @brief constructor
	Camera();

	/// @brief destructor
	virtual ~Camera(); 

	/// @brief Computing the viewmatrix form input
	/// @param window, deltaTime
	/// @return void
	void computeViewMatrixFromInput(GLFWwindow* window, float deltaTime); 

	/// @brief _viewMatrix getter
	/// @return _viewmatrix
	glm::mat4 getViewMatrix() { return _viewMatrix; };  

	/// @brief _projectionMatrix getter
	/// @return _projectionMatrix
	glm::mat4 getProjectionMatrix() { return _projectionMatrix; }; 

	/// @brief _cursor getter
	/// @return _cursor
	glm::vec3 getCursor() { return _cursor; };  



private:
	/// @brief The view Matrix of the camera
	glm::mat4 _viewMatrix; 

	/// @brief The projection Matrix of the camera
	glm::mat4 _projectionMatrix; 

	/// @brief The Cursor
	glm::vec3 _cursor;

};

#endif
