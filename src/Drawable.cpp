#include "Drawable.h"
#include "Shader.h"
#include "Texture.h"

#include <iostream>
#include <glm/glm.hpp>

Drawable::Drawable() : _model(1.0f)
{
    _vertices = nullptr;
    _indices = nullptr;
    _shader = new Shader;
    _texture = new Texture;
}

Drawable::~Drawable()
{
    delete _shader;
}

bool Drawable::bindShader(Shader& s)
{
    *_shader = s;
    return true;
}

bool Drawable::bindShader(const std::string& filename)
{
    return _shader->loadFromFile(filename);
}

bool Drawable::bindTexture(Texture& t)
{
    *_texture = t;
    return true;
}

bool Drawable::bindTexture(const std::string& filename)
{
    return _texture->loadFromFile(filename);
}

Shader& Drawable::getShader()
{
    return (*_shader);
}

