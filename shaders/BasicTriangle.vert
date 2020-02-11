#version 330 core

layout (location = 0) in vec3 inPos;
layout (location = 1) in vec3 inColor;
layout (location = 2) in vec2 inTexCoords;

uniform float time;
uniform mat4 transform;

out vec3 vertexColor;
out vec2 texCoords;

void main()
{
    gl_Position = vec4(inPos.x, inPos.y, inPos.z, 1);
    vertexColor = inColor;
    texCoords = inTexCoords;
}
