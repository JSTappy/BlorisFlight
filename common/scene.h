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

	virtual void update(float deltaTime); //update method
	void addSprite(Sprite* sprite); //method for affing a sprite to the scene, not to be confused with AddSprite
	//void addSpriteAsChild(Sprite* sprite);

	Camera* camera() { return _camera; }; //this is for getting the private camera '_camera'
	std::vector<Sprite*>& sprites() { return _sprites; }; //this is for getting the private list '_sprites'

private:
	Camera* _camera; //private camera, the only camera that will be made
	std::vector<Sprite*> _sprites; //private list of sprites
};

#endif /* SCENE_H */
