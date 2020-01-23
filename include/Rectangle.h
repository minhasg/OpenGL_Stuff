#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "Drawable2D.h"

class Rectangle : public Drawable2D
{
    public:
        Rectangle();
        ~Rectangle();
        bool draw();
};

#endif
