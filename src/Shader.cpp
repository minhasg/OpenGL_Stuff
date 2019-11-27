#include "Shader.h"
#include "Utils.h"

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
    if(_vertSource == "" || _fragSource == "")
    {
        std::cout << "Failed to compile shader - missing vertex or fragment shader source file." << std::endl;
        return false;
    }

    unsigned int vertexShader = 0;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    
    std::string vertexShaderSource = readTextFromFile(_vertSource);
    glShaderSource(vertexShader, 1, &vertexShaderSource.c_str(), NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "FAILED TO COMPILE VERTEX SHADER: " << infoLog << std::endl;
    }

    unsigned int fragmentShader = 0;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    std::string fragmentShaderSource = readTextFromFile(_fragSource);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource.c_str(), NULL);
    glCompileShader(fragmentShader);

    success = 0;
    char infoLog[512];
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "FAILED TO COMPILE FRAGMENT SHADER: " << infoLog << std::endl;
    }

    // TODO: Add compilation for geometry shader
    
    _shaderId = glCreateProgram();
    glAttachShader(_shaderId, vertexShader);
    glAttachShader(_shaderId, fragmentShader);
    glLinkProgram(_shaderId);
   
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    return true; 
}

bool Shader::use()
{
    glUseProgram(_shaderId);
    return true;
}

bool Shader::isCompiled() { return _isCompiled; }
