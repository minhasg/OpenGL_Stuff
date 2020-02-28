#include "Camera.h"

#include <glm/glm.hpp>

glm::mat4 Camera::_view = glm::mat4(0);
glm::mat4 Camera::_model = glm::mat4(0);

Camera::Camera()
{
    
}

Camera(glm::mat4 view, glm::mat4 projection)
{
    _view = view;
    _projection = projection;
}

glm::mat4 Camera::getViewMatrix();
{
    return _view;
}

bool Camera::setViewMatrix(glm::mat4 view);
{
    _view = view;
}

glm::mat4 Camera::getProjectionMatrix();
{
    return _projection;
}

bool Camera::setProjectionMatrix(glm::mat4 proj);
{
    _projection = proj;
}



