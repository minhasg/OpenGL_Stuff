#include "Shader.h"

#include <GL/glew.h>
#include <iostream>

Shader::Shader()
{
    _vertSource = "";
    _fragSource = "";
    _geoSource  = "";
    _shaderId = 0;
    _isCompiled = false;
}

Shader::Shader(std::string vertexShader, std::string fragmentShader, std::string geometryShader = "")
{
    _vertSource = vertexShader;
    _fragSource = fragmentShader;
    _geoSource  = geometryShader;

    _shaderId = 0;
    _isCompiled = false;    
}

bool Shader::loadShaderFromFile(ShaderType_e type, std::string filename)
{
    switch(type)
    {
        case SHADER_VERTEX:
        _vertSource = filename;
        break;

        case SHADER_FRAGMENT:
        _fragSource = filename;
        break;

        case SHADER_GEOMETRY:
        _geoSource = filename;
        break;

        default:
            std::cout << "Error: Invalid shader type selected!" << std::endl;
            return false;
    };

    // New shader, need to recompile
    _isCompiled = false;
    return true;
}

bool Shader::compile()
{

}

bool Shader::isCompiled() { return _isCompiled; }
