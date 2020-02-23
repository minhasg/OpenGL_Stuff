#ifndef _SHADER_H_
#define _SHADER_H_

#include <iostream>

#include <glm/glm.hpp>

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
        bool loadFromFile(const std::string&);
        bool compile();   
        bool bind();        
        
        Shader& operator=(const Shader& val);

        bool setUniform(const std::string&, bool);
        bool setUniform(const std::string&, int);
        bool setUniform(const std::string&, float);
        bool setUniform(const std::string&, glm::vec2);
        bool setUniform(const std::string&, glm::vec3);
        bool setUniform(const std::string&, glm::vec4);
        bool setUniform(const std::string&, glm::mat4);
        
        static unsigned int _currentShader;

    private:
        // Filenames for the currently bound shaders
        std::string _source;
        // ID for compiled shader
        unsigned int _shaderId;
        
        bool _printErrors(unsigned int shader);
};

#endif
