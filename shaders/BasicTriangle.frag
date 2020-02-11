#version 330 core

out vec4 FragColor;

in vec3 vertexColor;
in vec2 texCoords;

uniform float time;
uniform sampler2D tex;

void main()
{
    FragColor = vec4(vertexColor, 1.0);
}
