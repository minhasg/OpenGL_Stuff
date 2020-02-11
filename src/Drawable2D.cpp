#include "Drawable2D.h"
#include "Shader.h"
#include "Texture.h"

#include <iostream>
#include <glm/glm.hpp>

Drawable2D::Drawable2D() : _projection(1.0f)
{
    _vertices = nullptr;
    _indices = nullptr;
    _shader = new Shader;
    _texture = new Texture;
}

Drawable2D::~Drawable2D()
{
    delete _shader;
}

bool Drawable2D::bindShader(Shader& s)
{
    *_shader = s;
    return true;
}

bool Drawable2D::bindShader(const std::string& filename)
{
    return _shader->loadFromFile(filename);
}

bool Drawable2D::bindTexture(Texture& t)
{
    *_texture = t;
    return true;
}

bool Drawable2D::bindTexture(const std::string& filename)
{
    return _texture->loadFromFile(filename);
}

Shader& Drawable2D::getShader()
{
    return (*_shader);
}

