#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#if defined(__APPLE_CC__)
    #include <OpenGL/OpenGL.h>
    #include <OpenGL/gl.h>
    #include <OpenGL/gl3.h>
#endif

#include "maths.hpp"
#include "objects.hpp"

namespace engine { using namespace maths; namespace graphics {
   
    class Camera
    {
    public:
        Camera(GLsizei* width, GLsizei* height);
        ~Camera() {};

        vec2 localPosition;
        vec2 localScale;
        
        void link(Object& object);
        void update();
    };
} }

#endif // __CAMERA_HPP