#include <common/resourcemanager.h>
#include <common/config.h>
#include <iostream>

ResourceManager::ResourceManager()
{
	std::cout << "resourcemanager created" << std::endl;
}

ResourceManager::~ResourceManager()
{
	std::cout << "resourcemanager closed" << std::endl;
}

Sprite* ResourceManager::GetTarga(const std::string& fileName) //Getting Targas
{
	if (_targas[fileName] != NULL) //If the Targas name isnt nothing, Return the Targa. If it is null and this method is called, make amake the sprite, load it and return it
	{
		return _targas[fileName];
	}
	Sprite* s = new Sprite(fileName);
	s->loadTGA(fileName);
	_targas[fileName] = s;
	return s;
}