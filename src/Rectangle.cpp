#include "Rectangle.h"
#include "GraphicsUtils.h"
#include "Shader.h"

#include <GL/glew.h>

Rectangle::Rectangle()
{
    _numVertices = 4;
    _vertices = new Vertex[_numVertices];
    _vertices[0].position.x = -0.5f;
    _vertices[0].position.y = 0.5f;
    _vertices[0].position.z = 1.0f;
    
    _vertices[1].position.x = 0.5f;
    _vertices[1].position.y = 0.5f;
    _vertices[1].position.z = 1.0f;

    _vertices[2].position.x = 0.5f;
    _vertices[2].position.y = -0.5f;
    _vertices[2].position.z = 1.0f;

    _vertices[3].position.x = -0.5f;
    _vertices[3].position.y = -0.5f;
    _vertices[3].position.z = 1.0f;

    // Set colour
    _vertices[0].color.r = 0.5f;
    _vertices[0].color.g = 0;
    _vertices[0].color.b = 1.0f;
    
    _vertices[1].color.r = 0;
    _vertices[1].color.g = 0.5;
    _vertices[1].color.b = 1.0f;

    _vertices[2].color.r = 1.0f;
    _vertices[2].color.g = 0;
    _vertices[2].color.b = 0;

    _vertices[3].color.r = 0.5f;
    _vertices[3].color.g = 1.0f;
    _vertices[3].color.b = 0;
    
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

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
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
