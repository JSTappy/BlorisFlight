#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <common/camera.h>
#include <common/sprite.h>
#include <common/entity.h>

/// @brief The Scene class is the base class for making your own scenes
class Scene : public Entity
{
public:
	/// @brief constructor
	Scene(); 

	/// @brief destructor
	virtual ~Scene(); 

	/// @brief update method
	/// @param deltaTime
	/// @return void
	virtual void update(float deltaTime) = 0;

	/// @brief _camera getter
	/// @return _camera
	Camera* camera() { return _camera; }; 


private:
	/// @brief private camera, the only camera that will be made
	Camera* _camera; 
};

#endif /* SCENE_H */
