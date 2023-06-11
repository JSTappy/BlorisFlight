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

class Entity
{
public:
	Entity(); //constructor
	virtual ~Entity(); //destructor

	virtual void update(float deltaTime) = 0; //update

	InputManager* input() { return _input; };

	void AddChild(Entity* c); //AddChild for Parent Child relations between entities
	void RemoveChild(Entity* c);//Remove child for.. well, removing the child

	void AddSprite(const std::string& fileName);//AddSprite for adding a sprite to your entity

	std::vector<Entity*> Children() { return children; }; //this is for getting  the value of the private member 'children'
	Sprite* eSprite() { return sprite; } //this is for getting the value of the private member 'sprite'

	Entity* parent; //Entity pointer parent because parent is an entity

	//position rotation scale
	glm::vec3 position;
	float rotation;
	glm::vec3 scale;

protected:
	std::vector<Entity*> children; //list of children 
	Sprite* sprite; //sprite pointer sprite for the AddSprite method
	InputManager* _input = InputManager::input();


};
#endif // !ENTITY_H