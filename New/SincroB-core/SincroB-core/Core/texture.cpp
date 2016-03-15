#include "texture.hpp"

namespace engine { namespace texture {
    
    void Texture::loadImageTexture(const char *filename)
    {
        this->TextureID = loadBMPTexture_ARGB(filename, this->TextureWidth, this->TextureHeight);
    }
    
    void Texture::loadTexture(const unsigned int* texture)
    {
        glBindTexture(GL_TEXTURE_2D, *texture);
    }
    
} }