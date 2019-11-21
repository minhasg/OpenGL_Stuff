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

class Drawable2D
{
	public:
        Drawable2D();
        ~Drawable2D();
        virtual bool draw();
        
	protected:
        glm::vec4* _vertices;
        unsigned int _numVertices;
        unsigned int _vbo;
        
        bool _visible;
};

#endif
