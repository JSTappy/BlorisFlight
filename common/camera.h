#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> // glm::lookAt()

class Camera
{
public:
	Camera(); //constructor
	virtual ~Camera(); //destructor

	void computeViewMatrixFromInput(GLFWwindow* window, float deltaTime); 
	glm::mat4 getViewMatrix() { return _viewMatrix; };  //this is for getting the private member '_viewMatrix'
	glm::mat4 getProjectionMatrix() { return _projectionMatrix; };  //this is for getting the private member '_projectionMatrix'
	glm::vec3 getCursor() { return _cursor; };  //this is for getting the private member '_cursor'

private:
	glm::mat4 _viewMatrix; //private member '_viewMatrix'
	glm::mat4 _projectionMatrix; // private member '_projectionMatrix'
	glm::vec3 _cursor; // private member '_cursor'
};

#endif
