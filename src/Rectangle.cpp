#include "Rectangle.h"
#include "Drawable2D.h"
#include "Shader.h"

#include <GL/glew.h>

Rectangle::Rectangle()
{
    _vertices = new glm::vec4[4];
    _vertices[0].w = 1;
    _vertices[0].x = -0.5f;
    _vertices[0].y = 0.5f;
    _vertices[0].z = 1.0f;
    
    _vertices[1].w = 1;
    _vertices[1].x = 0.5f;
    _vertices[1].y = 0.5f;
    _vertices[1].z = 1.0f;

    _vertices[2].w = 1;
    _vertices[2].x = 0.5f;
    _vertices[2].y = -0.5f;
    _vertices[2].z = 1.0f;

    _vertices[3].w = 1;
    _vertices[3].x = -0.5f;
    _vertices[3].y = -0.5f;
    _vertices[3].z = 1.0f;

    _indices = new unsigned int[6];
    _indices[0] = 0;
    _indices[1] = 2;
    _indices[2] = 3;
    _indices[3] = 0;
    _indices[4] = 1;
    _indices[5] = 2;


    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);

    glGenBuffers(1, &_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(glm::vec4), _vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(glm::vec4), (void*)0);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &_ebo);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), _indices, GL_STATIC_DRAW);

}

Rectangle::~Rectangle()
{
    delete[] _vertices;
    delete[] _indices;
}

bool Rectangle::draw()
{
    _shader->bind();
    glBindVertexArray(_vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    return true;
}
