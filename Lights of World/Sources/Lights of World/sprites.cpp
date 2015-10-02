//
//  sprites.cpp
//  Lights of World
//
//  Created by Vinicius A.M. Lobo on 29/09/15.
//  Copyright © 2015 Vinicius A.M. Lobo. All rights reserved.
//

#include <GLFW/glfw3.h>
#include <OpenGL/OpenGL.h>
#include <SDL/SDL.h>

#include "sprites.hpp"

Sprite::Sprite() {
    
}

Sprite::~Sprite() {
    
}

void Sprite::draw(float size_x, float size_y, float *position_x, float *position_y, const char *file) {
    //image_ = SDL_LoadBMP(file);
    
    glBegin(GL_QUADS);
    
    glVertex2f( -size_x + *position_x, -size_y + *position_y);
    glVertex2f(  size_x + *position_x, -size_y + *position_y);
    glVertex2f(  size_x + *position_x,  size_y + *position_y);
    glVertex2f( -size_x + *position_x,  size_y + *position_y);
    
    glEnd();
}

void Sprite::animate() {
    
}