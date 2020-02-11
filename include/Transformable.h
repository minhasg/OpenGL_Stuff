#ifndef _TRANSFORMABLE_H_
#define _TRANSFORMABLE_H_

#include <glm/glm.hpp>

class Transformable
{
    public:
        Transformable();
        ~Transformable();

        bool move(float dx, float dy, float dz);
        bool move(float dx, float dy);
        bool move(glm::vec2 trans);
        bool move(glm::vec3 trans);

        bool rotate(float rx, float ry, float rz);
        bool rotate(float rx);
        bool rotate(glm::vec3 rot);

        bool scale(float sx, float sy, float sz);
        bool scale(float sx, float sy);
        bool scale(glm::vec2 scale);
        bool scale(glm::vec3 scale);
         
    protected:
        glm::vec3 _translate;
        glm::vec3 _rotate;
        glm::vec3 _scale;
        glm::mat4 _transform;

        bool _calculateTransform();
};

#endif
