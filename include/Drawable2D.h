/*
 *======================================================================*
 * This class is intended to serve as a base class for all drawable 2D  *
 * shapes. This class contains the essential functions and data needed  *
 * when drawing any 2D shape.                                           *
 *======================================================================*                                                                 
 */
#ifndef _DRAWABLE_2D_H_
#define _DRAWABLE_2D_H_

#include <glm/glm.hpp>
#include <iostream>

class Shader;
class Texture;
struct Vertex;

class Drawable2D
{
	public:
        Drawable2D();
        ~Drawable2D();
        virtual bool draw() = 0;
        bool bindShader(Shader& s);
        bool bindShader(const std::string&);
        Shader& getShader();
        
        bool bindTexture(Texture&);
        bool bindTexture(const std::string&);
               
	protected:
        Vertex* _vertices;
        unsigned int _numVertices;
        unsigned int* _indices;

        unsigned int _vbo;
        unsigned int _vao;
        unsigned int _ebo;

        Shader* _shader;
        Texture* _texture;
        bool _visible;

        glm::mat4 _projection;
};

#endif
