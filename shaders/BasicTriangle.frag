#version 330 core

out vec4 FragColor;

in vec3 vertexColor;

uniform float time;

void main()
{
    FragColor = vec4(vertexColor, time);
}
