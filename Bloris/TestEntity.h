/**
 * @file TestEntity.h
 *
 * @brief The TestEntity header file.
 *
 *
 * - Copyright 2023 Joas Sahetapy
 *
 */


#ifndef TESTENTITY_H
#define TESTENTITY_H

#include <common/entity.h>

/// @brief TestEntity used for testing, this entity is abstract so we can use it in our scene
class TestEntity : public Entity
{
public:
	/// @brief Constructor
	TestEntity(); 

	/// @brief Destructor
	~TestEntity(); 
	
	/// @brief Changing Sprites
	/// @param imagepath the path to the image
	/// @return void
	void ChangeSprite(const std::string& imagepath); 

	/// @brief update method
	/// @param deltaTime
	/// @return void
	virtual void update(float deltaTime); //update

private:

};
#endif // !TESTENTITY_H
