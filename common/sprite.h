#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

/// @brief The Sprite class defines the vertexes, uv, width, height, texture and shader of a sprite
class Sprite
{
public:
	/// @brief constructor 
	/// @param imagepath the path to the image
	Sprite(const std::string& imagepath);

	/// @brief destructor
	virtual ~Sprite();


	/// @brief _vertexbuffer getter
	/// @return _vertexbuffer
	GLuint vertexbuffer() { return _vertexbuffer; }; 

	/// @brief _uvbuffer getter
	/// @return _uvbuffer
	GLuint uvbuffer() { return _uvbuffer; }; 

	/// @brief _texture getter
	/// @return _texture
	GLuint gettexture() { return _texture; }; 

	/// @brief _width getter
	/// @return _width
	unsigned int width() { return _width; };

	/// @brief _height getter
	/// @return _height
	unsigned int height() { return _height; }; 

	/// @brief this method is for initializing the sprite
	/// @param vb, uvb, texture, width, height Vertex buffer, UV buffer, Texture, width and height
	/// @return void
	void SetUp(GLuint vb, GLuint uvb, GLuint texture, unsigned int width ,unsigned int height); 

	/// @brief _texturename getter
	/// @return _texturename 
	std::string TextureName() { return _texturename; }; 


	/// @brief position
	glm::vec3 position; 

	/// @brief scale
	glm::vec3 scale; 

	/// @brief rotation
	float rotation; 


	/// @brief this method is for defining the vertex and uv buffer data
	/// @return void
	void createFromBuffer(); 


	/// @brief method for loading Targas
	/// @param imagepath the path to the image
	/// return GLUint
	GLuint loadTGA(const std::string& imagepath); 


private:
	/// @brief name of the texture
	std::string _texturename; 

	/// @brief this will determine the vertices of the sprite
	GLuint _vertexbuffer;  

	/// @brief this will determine the UV's of the sprite
	GLuint _uvbuffer; 

	/// @brief this will determine the texture of the sprite
	GLuint _texture; 


	/// @brief this will be the sprite width
	unsigned int _width;

	/// @brief this will be the sprite height
	unsigned int _height; 


	/// @brief this is a boolean to see if the initialisation has already been done
	bool setup = false; 


};

#endif /* SPRITE_H */
