#ifndef _SHADER_H_
#define _SHADER_H_

namespace std { class string; };

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
        Shader(std::string, std::string, std::string);
        bool loadShaderFromFile(ShaderType_e, std::string);

    private:
        // ID for compiled shader
        unsigned int _shaderId;
};

#endif
