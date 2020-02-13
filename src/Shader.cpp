#include "Shader.h"
#include "Utils.h"

#include <GL/glew.h>
#include <iostream>
#include <cstdio>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader()
{
    _source = "";
    _shaderId = 0;
}

Shader::Shader(const std::string& filename)
{
    _shaderId = 0;
    loadFromFile(filename);
}

bool Shader::loadFromFile(const std::string& filename)
{
    _source = filename;
    return compile();
}

bool Shader::compile()
{
    bool passed = true;

    if(_source == "")
    {
        std::cout << "Shader source not specified! Compiling with default shader." << std::endl;
        _source = "shaders/defaultShader";
    }

    unsigned int vertexShader = 0;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    
    std::string vertexShaderSource = readTextFromFile(_source + ".vert");
    const char* src = vertexShaderSource.c_str();    

    //std::cout << src << std::endl;

    glShaderSource(vertexShader, 1, &src, NULL);
    glCompileShader(vertexShader);

    passed &= _printErrors(vertexShader);

    unsigned int fragmentShader = 0;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    std::string fragmentShaderSource = readTextFromFile(_source + ".frag");
    src = fragmentShaderSource.c_str();
    glShaderSource(fragmentShader, 1, &src, NULL);
    glCompileShader(fragmentShader);

    passed &= _printErrors(fragmentShader);

    // TODO: Add compilation for geometry shader
    
    if(passed)
    {
        _shaderId = glCreateProgram();
        glAttachShader(_shaderId, vertexShader);
        glAttachShader(_shaderId, fragmentShader);
        glLinkProgram(_shaderId);
   
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);    
    } 
    return passed;
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
    if(!_shaderId)
    {
        std::cout << "Attempting to bind uncompiled shader! Compiling first." << std::endl;
        compile();
    }
    glUseProgram(_shaderId);
    return true;
}

Shader& Shader::operator=(const Shader& val)
{
    _shaderId = val._shaderId;
    _source = val._source;

    return *this;
}

bool Shader::setUniform(const std::string& name, bool value)
{
    glUseProgram(_shaderId);
    int uniformLocation = glGetUniformLocation(_shaderId, name.c_str());
    glUniform1i(uniformLocation, (int) value);
    glUseProgram(0);
    return true;
}

bool Shader::setUniform(const std::string& name, int value)
{
    glUseProgram(_shaderId);
    int uniformLocation = glGetUniformLocation(_shaderId, name.c_str());
    glUniform1i(uniformLocation, value);
    glUseProgram(0);
    return true;
}

bool Shader::setUniform(const std::string& name, float value)
{
    glUseProgram(_shaderId);
    int uniformLocation = glGetUniformLocation(_shaderId, name.c_str());
    glUniform1f(uniformLocation, value);
    glUseProgram(0);
    return true;
}

bool Shader::setUniform(const std::string& name, glm::vec2 value)
{
    glUseProgram(_shaderId);
    int uniformLocation = glGetUniformLocation(_shaderId, name.c_str());
    glUniform2f(uniformLocation, value.x, value.y);
    glUseProgram(0);
    return true;
}

bool Shader::setUniform(const std::string& name, glm::vec3 value)
{
    glUseProgram(_shaderId);
    int uniformLocation = glGetUniformLocation(_shaderId, name.c_str());
    glUniform3f(uniformLocation, value.x, value.y, value.z);
    glUseProgram(0);
    return true;
}

bool Shader::setUniform(const std::string& name, glm::vec4 value)
{
    glUseProgram(_shaderId);
    int uniformLocation = glGetUniformLocation(_shaderId, name.c_str());
    glUniform4f(uniformLocation, value.x, value.y, value.z, value.w);
    glUseProgram(0);
    return true;
}


bool Shader::setUniform(const std::string& name, glm::mat4 value)
{
    glUseProgram(_shaderId);
    int uniformLocation = glGetUniformLocation(_shaderId, name.c_str());
    glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(value));
    glUseProgram(0);
    return true;
}
