/**
 * @file entity.h
 *
 * @brief The entity header file.
 *
 *
 * - Copyright 2023 Joas Sahetapy
 *
 */


#ifndef ENTITY_H
#define ENTITY_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <common/sprite.h>
#include <common/config.h>
#include <common/inputmanager.h>
#include <common/keyconfig.h>
#include <glm/glm.hpp>

 /// @brief The Base object/element class for in your scene. This class also has children/parent relations
class Entity
{
public:
	/// @brief constructor
	Entity(); 

	/// @brief destructor
	virtual ~Entity(); 

	/// @brief update function
	/// @param deltaTime
	/// @return void
	virtual void update(float deltaTime) = 0;

	/// @brief _input getter
	/// @return _input
	InputManager* input() { return _input; };

	/// @brief AddChild for adding a child
	/// @param c The Entity you want to add as a child of this Entity
	/// @return void
	void AddChild(Entity* c); 

	/// @brief RemoveChild for removing a child
	/// @param c The Child you want to remoce from this Entity
	/// @return void
	void RemoveChild(Entity* c);

	/// @brief AddSprite for adding a sprite to your entity
	/// @param fileName The name of the file
	/// @return void
	void AddSprite(const std::string& fileName);

	/// @brief children getter
	/// @return children
	std::vector<Entity*> Children() { return children; }; 

	/// @brief sprite getter
	/// @return sprite
	Sprite* eSprite() { return sprite; } 

	/// @brief the parent of this entity
	Entity* parent; 

	/// @brief position
	glm::vec3 position; 

	/// @brief scale
	glm::vec3 scale; 
	
	/// /// @brief rotation
	float rotation; 

protected:
	/// @brief list of children 
	std::vector<Entity*> children; 

	/// @brief the sprite of this entity
	Sprite* sprite; 

	/// @brief instance of InputManager
	InputManager* _input = InputManager::input();


};
#endif // !ENTITY_H