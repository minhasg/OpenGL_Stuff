#include "Triangle.h"
#include "Shader.h"
#include <GL/glew.h>
#include <glm/vec4.hpp>

Triangle::Triangle()
{
    glm::vec4* vertices = new glm::vec4[3];
    
    // Equilateral triangles only for now
    vertices[0].x = -0.5f; 
    vertices[0].y = -0.5f;
    vertices[0].z = 0;

    vertices[1].x = 0;
    vertices[1].y = 0.5f;
    vertices[1].z = 0;

    vertices[2].x = 0.5f;
    vertices[2].y = -0.5f;
    vertices[2].z = 0;

    _vertices = vertices;
    _numVertices = 3;
   
    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);
    
    glGenBuffers(1, &_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, (_numVertices * sizeof(glm::vec4)), _vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec4), (void*) 0);
    glEnableVertexAttribArray(0);

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
