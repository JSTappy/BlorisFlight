#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <map>
#include <string>
#include <common/sprite.h>
#include <GL/glew.h>

class InputManager
{
public:
	InputManager();//constructor
	virtual ~InputManager(); //destructor

private:

	InputManager* const InputManager::input = new InputManager();
};

#endif // !INPUTMANAGER_H
