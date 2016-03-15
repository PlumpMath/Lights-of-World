#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

#include "texture.hpp"
#include "maths.hpp"

namespace engine { using namespace maths; namespace texture {
   
    struct Sprite
    {
        Sprite(TextureCoords& coords, const int* xframes, const int* yframes, vec2 position, float timer);
    };
    
} }

#endif // __SPRITE_HPP__