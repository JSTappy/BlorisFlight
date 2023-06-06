#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

class Sprite
{
public:
	Sprite(const std::string& imagepath); //constructor but with a reference to the image path (assets/kingkong.tga) for example
	virtual ~Sprite(); //destructor

	GLuint vertexbuffer() { return _vertexbuffer; }; //this is for getting the GLuint '_vertexbuffer'
	GLuint uvbuffer() { return _uvbuffer; }; //this is for getting the private GLuint '_uvbuffer'
	GLuint gettexture() { return _texture; }; //this is for getting the private GLuint '_texture'
	unsigned int width() { return _width; }; //this is for getting the private uint '_width'
	unsigned int height() { return _height; }; //this is for getting the private uint '_height'

	void SetUp(GLuint vb, GLuint uvb, GLuint texture, unsigned int width ,unsigned int height); //this method is for initializing the sprite
	std::string TextureName() { return _texturename; }; //this is for getting the private string '_texturename'

	//position rotation scale
	glm::vec3 position;
	glm::vec3 scale;
	float rotation;

	void createFromBuffer(); //this method is for defining the vertex and uv buffer data


	GLuint loadTGA(const std::string& imagepath); //method for loading Targas

private:

	std::string _texturename; //private string texturename, you use this in renderer to know what targa to load. You use this together with the TextureName string
	GLuint _vertexbuffer;  //GLuint _vertexbuffer
	GLuint _uvbuffer; ///GLuint _uvbuffer for
	GLuint _texture; ///GLuint '_vertexbuffer'

	unsigned int _width; // this will be the sprite width
	unsigned int _height; // this will be the sprite height

	bool setup = false; //this is a boolean to see if the initialisation has already been done, if true: then you cant setup anymore

};

#endif /* SPRITE_H */
