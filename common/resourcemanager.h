/**
 * @file resourcemanager.h
 *
 * @brief The resourcemanager header file.
 *
 *
 * - Copyright 2023 Joas Sahetapy
 *
 */


#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <string>
#include <common/sprite.h>
#include <GL/glew.h>

 /// @brief The Resourcemanager Class is for managing the sprites and making sure they are loaded in correctly.
class ResourceManager
{
public:
	///@brief constructor
	ResourceManager(); 

	/// @brief destructor
	virtual ~ResourceManager(); 

	/// @brief Method for getting targas
	/// @param fileName the filename
	/// @return filename
	Sprite* GetTarga(const std::string& fileName); 


private:
	/// @brief list of sprites
	std::map<std::string, Sprite*> _targas; 

};

#endif // !RESOURCEMANAGER_H
