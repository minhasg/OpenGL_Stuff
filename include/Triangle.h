#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Drawable.h"
#include "Transformable.h"

class Triangle : public Drawable, public Transformable
{
    public:
        Triangle();
        ~Triangle();
        bool draw();
    private:
        
};

#endif
