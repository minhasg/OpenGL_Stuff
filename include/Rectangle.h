#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "Drawable.h"

class Rectangle : public Drawable
{
    public:
        Rectangle();
        ~Rectangle();
        bool draw();
};

#endif
