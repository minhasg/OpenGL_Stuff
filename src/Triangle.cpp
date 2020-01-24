#include "Triangle.h"
#include "Shader.h"
#include <GL/glew.h>
#include <glm/vec4.hpp>



Triangle::Triangle()
{
    const NUM_ATTRIBUTES = 2;
    const NUM_VERTICES = 3;
    _numVertices = NUM_VERTICES * NUM_ATTRIBUTES;
    glm::vec4* vertices = new glm::vec4[_numVertices];
    
    // Equilateral triangles only for now
    vertices[0].x = -0.5f; 
    vertices[0].y = -0.5f;
    vertices[0].z = 0;

    vertices[2].x = 0;
    vertices[2].y = 0.5f;
    vertices[2].z = 0;

    vertices[4].x = 0.5f;
    vertices[4].y = -0.5f;
    vertices[4].z = 0;

    // Colours
    vertices[1].x = 1.0f; 
    vertices[1].y = 0;
    vertices[1].z = 0;

    vertices[3].x = 0;
    vertices[3].y = 1.0f;
    vertices[3].z = 0;

    vertices[5].x = 0;
    vertices[5].y = 0;
    vertices[5].z = 1.0f;

    _vertices = vertices;
   
    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);
    
    glGenBuffers(1, &_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, (_numVertices * sizeof(glm::vec4)), _vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 2 * sizeof(glm::vec4), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 2 * sizeof(glm::vec4), (void*)(sizeof(glm::vec4)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}


Triangle::~Triangle()
{
    delete[] _vertices;
}

bool Triangle::draw()
{
    _shader->bind();
    glBindVertexArray(_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3); 
 
    return true;
}
