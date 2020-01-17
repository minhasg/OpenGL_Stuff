/*
 *======================================================================*
 * This class is intended to serve as a base class for all drawable 2D  *
 * shapes. This class contains the essential functions and data needed  *
 * when drawing any 2D shape.                                           *
 *======================================================================*                                                                 
 */
#ifndef _DRAWABLE_2D_H_
#define _DRAWABLE_2D_H_

#include <glm/vec4.hpp>
#include <iostream>

class Shader;

class Drawable2D
{
	public:
        Drawable2D();
        ~Drawable2D();
        virtual bool draw() = 0;
        bool bindShader(Shader& s);
        bool bindShader(const std::string&);        

	protected:
        glm::vec4* _vertices;
        unsigned int _numVertices;
        unsigned int _vbo;
        unsigned int _vao;        

        Shader* _shader;
        bool _visible;
};

#endif
