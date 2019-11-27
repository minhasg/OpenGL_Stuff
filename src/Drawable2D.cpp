#include "Drawable2D.h"
#include "Shader.h"

#include <glm/vec4.hpp>

Drawable2D::Drawable2D()
{
    _vertices = nullptr;    
}

Drawable2D::~Drawable2D()
{
    
}

bool Drawable2D::setShader(Shader s)
{
    _shader = s;
    return true;
}

