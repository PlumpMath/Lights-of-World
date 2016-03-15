#ifndef __BMPIMAGE_HPP__
#define __BMPIMAGE_HPP__

#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

namespace engine { namespace texture {
    
    unsigned int loadBMPTexture_ARGB(const char* filename, int& width, int& height);
    unsigned char* loadBMPFile_ARGB(const char* filename, int& width, int& height);
    
} }

#endif // __BMPIMAGE_HPP__