#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <common/camera.h>
#include <common/sprite.h>
#include <common/entity.h>
#include <Bloris/TestEntity.h>

class Scene : public Entity
{
public:
	Scene(); //constructor
	virtual ~Scene(); //destructor

	virtual void update(float deltaTime) = 0; //update method
	//void addSpriteAsChild(Sprite* sprite);

	Camera* camera() { return _camera; }; //this is for getting the private camera '_camera'

private:
	Camera* _camera; //private camera, the only camera that will be made
};

#endif /* SCENE_H */
