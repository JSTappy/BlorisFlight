#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <string>
#include <common/sprite.h>
#include <GL/glew.h>

class ResourceManager
{
public:
	ResourceManager();//constructor
	virtual ~ResourceManager(); //destructor

	Sprite* GetTarga(const std::string& fileName); //Get Targa Method

private:
	std::map<std::string, Sprite*> _targas; //list of sprite pointers
};

#endif // !RESOURCEMANAGER_H
