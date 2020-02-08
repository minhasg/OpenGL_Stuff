#ifndef _GRAPHICSUTILS_H_
#define _GRAPHICSUTILS_H_

#include <glm/vec4.hpp>
#include <glm/vec2.hpp>

struct Vertex
{
    glm::vec4 position;
    glm::vec4 color;
    glm::vec2 texture;
};

#endif
