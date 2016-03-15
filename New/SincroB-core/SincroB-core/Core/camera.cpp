#include "camera.hpp"

namespace engine { using namespace maths; namespace graphics {
   
    Camera::Camera(GLsizei* width, GLsizei* height)
    {
        glViewport(0, 0, *width, *height);
    }
    
    void Camera::update()
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        //
    }
    
} }