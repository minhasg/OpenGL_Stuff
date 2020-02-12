#include <GL/glew.h>

#include "Texture.h"
#include "stb/stb_image.h"

#include <glm/vec4.hpp>
#include <glm/gtc/type_ptr.hpp>

Texture::Texture()
{
    _source = "";
    _textureId = 0;
    _borderColor.r = 0.0f;
    _borderColor.g = 0.0f;
    _borderColor.b = 0.0f;
    _borderColor.a = 0.0f;
}

Texture::Texture(std::string& source)
{   
    _borderColor.r = 0.0f;
    _borderColor.g = 0.0f;
    _borderColor.b = 0.0f;
    _borderColor.a = 0.0f;
   
    this->loadFromFile(source);
}

bool Texture::loadFromFile(const std::string& source)
{
    _source = source;
    int width, height, numChannels;

    stbi_set_flip_vertically_on_load(true);
    unsigned char* image = stbi_load(source.c_str(), &width, &height, &numChannels, 0);
    for(int i = 0; i < 100; i++)
    {
        std::cout << image[i] << ' ';
        if(i % 20 == 0)
        {
            std::cout << std::endl;
        }
    }

    glGenTextures(1, &_textureId);    

    glBindTexture(GL_TEXTURE_2D, _textureId);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    
    stbi_image_free(image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, glm::value_ptr(_borderColor) );

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    std::cout << "Texture " << _source << " loaded.\n";

    return true;
}

bool Texture::bind()
{
    // Load default texture if none is specified
    if(_source.empty())
    {
        std::cout << "Attempting to bind a texture with no source specified! Loading default texture." << std::endl;
        _source = DEFAULT_TEXTURE_SOURCE;
        this->loadFromFile(_source);
    }
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _textureId);
    return true;
}

bool Texture::setBorderColor(glm::vec4& color)
{
    _borderColor = color;
    return true;
}

Texture& Texture::operator=(const Texture& val)
{
    _textureId = val._textureId;
    _source = val._source;

    return *this;
}
