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

Shader::Shader(const std::string& filename)
{
    loadShaderFromFile(filename);
}

bool Shader::loadShaderFromFile(const std::string& filename)
{
    _vertSource = filename + ".vert";
    _fragSource = filename + ".frag";
    _geoSource = filename + ".geo";

    _isCompiled = compile();
    return _isCompiled;
}

bool Shader::compile()
{
    bool failed = false;

    if(_vertSource == "" || _fragSource == "")
    {
        std::cout << "Failed to compile shader - missing vertex or fragment shader source file." << std::endl;
        return false;
    }

    unsigned int vertexShader = 0;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    
    const char* vertexShaderSource = readTextFromFile(_vertSource).c_str();

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    failed |= _printErrors(vertexShader);

    unsigned int fragmentShader = 0;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    const char* fragmentShaderSource = readTextFromFile(_fragSource).c_str();
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    failed |= _printErrors(fragmentShader);

    // TODO: Add compilation for geometry shader
    
    _isCompiled = (!failed);

    if(failed)
    {
        return false;
    }

    _shaderId = glCreateProgram();
    glAttachShader(_shaderId, vertexShader);
    glAttachShader(_shaderId, fragmentShader);
    glLinkProgram(_shaderId);
   
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    return true; 
}

bool Shader::_printErrors(unsigned int shader)
{
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "FAILED TO COMPILE VERTEX SHADER: " << infoLog << std::endl;
    }
    return (bool) success;
}

bool Shader::bind()
{
    glUseProgram(_shaderId);
    return true;
}

bool Shader::isCompiled()
{
    return _isCompiled;
}
