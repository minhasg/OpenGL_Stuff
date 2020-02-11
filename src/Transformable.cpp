#include "Transformable.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Transformable::Transformable() : _translate(0.0f), _rotate(0.0f), _scale(1.0f), _transform(1.0f)
{

}

Transformable::~Transformable()
{

}

bool Transformable::move(float dx, float dy, float dz)
{
    _translate.x += dx;
    _translate.y += dy;
    _translate.z += dz;
    return true;
}

bool Transformable::move(float dx, float dy)
{
    move(dx, dy, 0.0f);
    return true;
}

bool Transformable::move(glm::vec2 trans)
{
    move(trans.x, trans.y, 0.0f);
    return true;
}

bool Transformable::move(glm::vec3 trans)
{
    move(trans.x, trans.y, trans.z);
    return true;
}

bool Transformable::rotate(float rx, float ry, float rz)
{
    _rotate.x = rx;
    _rotate.y = ry;
    _rotate.z = rz;
    return true;
}

bool Transformable::rotate(float rz)
{
    rotate(0.0f, 0.0f, rz);
    return true;
}

bool Transformable::rotate(glm::vec3 rot)
{
    rotate(rot.z, rot.y, rot.z);
    return true;
}

bool Transformable::scale(float sx, float sy, float sz)
{
    _scale.x = sx;
    _scale.y = sy;
    _scale.z = sz;
    return true;
}

bool Transformable::scale(float sx, float sy)
{
    scale(sx, sy, 1.0f);
    return true;
}

bool Transformable::scale(glm::vec2 scl)
{
    scale(scl.x, scl.y, 1.0f);
    return true;
}

bool Transformable::scale(glm::vec3 scl)
{
    scale(scl.x, scl.y, scl.z);
    return true;
}

bool Transformable::_calculateTransform()
{
    _transform = glm::mat4(1.0f);
    _transform = glm::translate(_transform, _translate);
    _transform = glm::rotate(_transform, _rotate.x, glm::vec3(1.0f, 0, 0)); 
    _transform = glm::rotate(_transform, _rotate.y, glm::vec3(0, 1.0f, 0));
    _transform = glm::rotate(_transform, _rotate.z, glm::vec3(0, 0, 1.0f));
    _transform = glm::scale(_transform, _scale);
    return true;    
}
