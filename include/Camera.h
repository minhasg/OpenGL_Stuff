#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <glm/glm.hpp>

class Camera
{
    public:
        Camera(glm::mat4, glm::mat4);
        Camera();
        static glm::mat4 getViewMatrix();
        bool setViewMatrix(glm::mat4);

        static glm::mat4 getProjectionMatrix();
        bool setProjectionMatrix(glm::mat4);

    private:
        static glm::mat4 _view;
        static glm::mat4 _projection;    


};

#endif
