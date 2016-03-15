#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__

#include <vector>
#include "maths.hpp"
#include "bmpimage.hpp"

namespace engine { using namespace maths; namespace texture {
   
    struct TextureCoords
    {
        float x, y;
        
        TextureCoords(float x=0.0f, float y=0.0f) { this->x = x; this->y = y; };
        ~TextureCoords() {};
    };
    
    struct Texture
    {
        int TextureWidth, TextureHeight;
        unsigned int TextureID = NULL;
        
        // Funções de carregar as texturas e procura de arquivos;
        void loadImageTexture(const char* filename);
        static void loadTexture(const unsigned int* texture);
    };
} }

#endif // __TEXTURE_HPP__