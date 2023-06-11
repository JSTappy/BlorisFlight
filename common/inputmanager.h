#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <map>
#include <string>
#include <common/sprite.h>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class InputManager
{
public:
	InputManager();//constructor
	virtual ~InputManager(); //destructor

	static InputManager* input();

	void InputUpdate(GLFWwindow* w); // update for getting the for loop going

	bool GetKey(int k); 
	bool GetKeyDown(int k); 
	bool GetKeyUp(int k); 

private:
	GLFWwindow* _window; 
	static InputManager* _instance; 
	void _handleKey(int key); //for checking if the keys are pressed

	//the integers are for the keys because keys are integers and the bools are for checking if it is pressed
	std::map<int, bool> _keys;
	std::map<int, bool> _keysDown;
	std::map<int, bool> _keysUp; 

};

#endif // !INPUTMANAGER_H
