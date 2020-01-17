#ifndef _SHADER_H_
#define _SHADER_H_

#include <iostream>

typedef enum
{
    SHADER_VERTEX,
    SHADER_FRAGMENT,
    SHADER_GEOMETRY
} ShaderType_e;

class Shader
{
    public:
        Shader();
        Shader(const std::string&);
        bool loadShaderFromFile(const std::string&);
        bool compile();   
        bool bind();        
        
        Shader& operator=(const Shader& val);

    private:
        // Filenames for the currently bound shaders
        std::string _source;
        // ID for compiled shader
        unsigned int _shaderId;

        bool _printErrors(unsigned int shader);
};

#endif
