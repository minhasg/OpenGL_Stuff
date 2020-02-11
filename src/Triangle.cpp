#include "Triangle.h"
#include "Shader.h"
#include "GraphicsUtils.h"
#include "Texture.h"

#include <GL/glew.h>

#include <glm/glm.hpp>


Triangle::Triangle()
{
    _numVertices = 3;
    _vertices = new Vertex[_numVertices];
    
    // Equilateral triangles only for now
    _vertices[0].position.x = -0.5f; 
    _vertices[0].position.y = -0.5f;
    _vertices[0].position.z = 0;

    _vertices[1].position.x = 0;
    _vertices[1].position.y = 0.5f;
    _vertices[1].position.z = 0;

    _vertices[2].position.x = 0.5f;
    _vertices[2].position.y = -0.5f;
    _vertices[2].position.z = 0;

    // Colours
    _vertices[0].color.r = 1.0f; 
    _vertices[0].color.g = 0;
    _vertices[0].color.b = 0;

    _vertices[1].color.r = 0;
    _vertices[1].color.g = 1.0f;
    _vertices[1].color.b = 0;

    _vertices[2].color.r = 0;
    _vertices[2].color.g = 0;
    _vertices[2].color.b = 1.0f;
   
    // Texture
    _vertices[0].texture.s = 0; 
    _vertices[0].texture.t = 0;
   
    _vertices[1].texture.s = 0.5; 
    _vertices[1].texture.t = 1;
    
    _vertices[2].texture.s = 1.0f; 
    _vertices[2].texture.t = 0;
 
    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);
    
    glGenBuffers(1, &_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, (_numVertices * sizeof(Vertex)), _vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec4)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(2 * sizeof(glm::vec4)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);
}


Triangle::~Triangle()
{
    delete[] _vertices;
}

bool Triangle::draw()
{
    _shader->bind();
    _texture->bind();
    _calculateTransform();
    _shader->setUniform("tex", 0);
    _shader->setUniform("transform", _transform);
    
    glBindVertexArray(_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3); 
 
    return true;
}
