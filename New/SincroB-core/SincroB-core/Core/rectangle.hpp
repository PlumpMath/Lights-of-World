#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#if defined(__APPLE_CC__)
    #include <OpenGL/OpenGL.h>
    #include <OpenGL/gl.h>
    #include <OpenGL/gl3.h>
#endif // defined(__APPLE_CC__)

#include "maths.hpp"
#include "texture.hpp"

namespace engine { using namespace maths; namespace graphics {
    
    struct Rect
    {
        Rect() { this->init(); };
        ~Rect() { this->destroy(); };
        
        // Textura;
        struct RectTexture
        {
            float width, height;
            bool TextureAlpha = false;
            
            const char* TexturePath;
            unsigned int TextureID;
            
            vec2 TextureCoords[4];
            texture::Texture TextureContext;
            
        } Texture;
        
        // Propriedades de Renderização;
        GLuint vbo;

        struct RectVertex
        {
            vec4 VertexColor[4];
            vec2 VertexPosition[4];
            
        } Vertex;
        
        vec2 worldPosition;
        vec2 worldScale;
        
        // Rectangle Metrics;
        vec2 localPosition;
        vec2 localScale;
        
        // Funções;
        bool rectVisible = true;
        void setColor(vec4 color);
        
        virtual void loadTexture(const char* texture_path);
        virtual void freeTexture();
        
        virtual void update();
        
        virtual void draw() const; // Não modifica valores;
        virtual void init();
        virtual void destroy();
    };
} }

#endif // __RECTANGLE_HPP__