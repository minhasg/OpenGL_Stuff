#include "Drawable2D.h"
#include "Shader.h"

#include <iostream>
#include <glm/vec4.hpp>

Drawable2D::Drawable2D()
{
    _vertices = nullptr;
    _indices = nullptr;
    _shader = new Shader;
}

Drawable2D::~Drawable2D()
{

}

bool Drawable2D::bindShader(Shader& s)
{
    *_shader = s;
    return true;
}

bool Drawable2D::bindShader(const std::string& filename)
{
    return _shader->loadShaderFromFile(filename);
}
