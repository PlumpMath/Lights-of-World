#ifndef __OBJECTS_HPP__
#define __OBJECTS_HPP__

#include <stdio.h>
#include <string>
#pragma once

#include <GLFW/glfw3.h>

#if defined(__APPLE_CC__)
    #include <OpenGL/gl.h>
    #include <OpenGL/gl3.h>
    #include <OpenGL/OpenGL.h>
#endif

#include "maths.hpp"
#include "rectangle.hpp"

namespace engine { using namespace maths; namespace graphics {
    
    // Estrutura da cena;
    //struct Scene;
    
    class Object
    {
    public:
        Object() {};
        ~Object() { this->destroy(); };
        
        // Index do objeto na cena;
        int object_index;
        const char* name;
        
        Rect Rectangle;
        
        vec2 localPosition = vec2(0.0f, 0.0f);
        vec2 localScale = vec2(1.0f, 1.0f);
        
        void loadImage(const char* image, bool alpha=false);
        void setColor(vec4 color);
        
        void init();
        void destroy();
        
        void update();
    };
    
} }

#endif // __OBJECTS_HPP__