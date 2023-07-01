#include <common/entity.h>

Entity::Entity()
{
	//no sprite and no parents
	parent = nullptr;
	sprite = nullptr;

	//position scale rotation
	position = glm::vec3(0, 0, 0);
	scale = glm::vec3(1.0f, 1.0f, 1.0f);
	rotation = 0;
}

Entity::~Entity()
{
	parent = nullptr;
	sprite = nullptr;
}

void Entity::AddChild(Entity* c) //Add child method, if the parent is not a nullptr Remove the child from its old parent and make 'this' the new parent
{
	if (c->parent != nullptr)
	{
		c->parent->RemoveChild(c);
	}
	children.push_back(c);
	c->parent = this;
}

void Entity::RemoveChild(Entity* c) {
	for (size_t i = 0; i < children.size(); i++)
	{
		if (children[i] == c)
		{
			children.erase(children.begin() + i);
			return;
		}
	}
}

void Entity::AddSprite(const std::string& fileName) //Adding a sprite to your entity (which won't render just yet)
{
	if (sprite != nullptr)
	{
		delete sprite;
		sprite = nullptr;
	}
	sprite = new Sprite(fileName);
}