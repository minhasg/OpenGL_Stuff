#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <iostream>

#include <glm/vec4.hpp>

const std::string DEFAULT_TEXTURE_SOURCE = "assets/images/harambe_real.jpeg";

class Texture
{
    public:
        Texture();
        Texture(std::string&);
        bool setBorderColor(glm::vec4&);
        bool loadFromFile(const std::string&);
        bool bind();
        
        Texture& operator=(const Texture&); 
    private:
        std::string _source;
        unsigned int _textureId;
        
        glm::vec4 _borderColor;
};

#endif
