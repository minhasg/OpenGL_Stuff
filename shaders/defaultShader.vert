#version 330 core
layout (location = 0) in vec4 pos;

void main()
{
    gl_position = vec4(pos.x, pos.y, pos.z, 1);
}
