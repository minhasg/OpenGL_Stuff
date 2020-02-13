#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

class Drawable2D;

#include "Drawable2D.h"
#include "Transformable.h"

class Triangle : public Drawable2D, public Transformable
{
    public:
        Triangle();
        ~Triangle();
        bool draw();
    private:
        
};

#endif
