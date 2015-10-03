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

Sprite::Sprite(): tex_coord_x(0.0f), tex_coord_y(0.0f), tex_coord_frame_x(0.0f), tex_coord_frame_y(0.0f), tex_sprites_x(0), tex_sprites_y(0) {
    
}

Sprite::~Sprite() {
    
}

void Sprite::draw(float size_x, float size_y, float *position_x, float *position_y, const char *file, int id) {
    
    image_ = SDL_LoadBMP(file);
    
    size_y += size_x/2;
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    
    glBindTexture(GL_TEXTURE_2D, id);
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    glTexImage2D(GL_TEXTURE_2D, 0, 2, image_->w, image_->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, image_->pixels);
    
    glBegin(GL_QUADS);
    
    glTexCoord2f(  tex_coord_frame_x,  tex_coord_frame_y);
    glVertex2f( -size_x + *position_x, -size_y + *position_y);
    
    glTexCoord2f(  tex_coord_frame_x,  tex_coord_frame_y);
    glVertex2f(  size_x + *position_x, -size_y + *position_y);
    
    glTexCoord2f(  tex_coord_frame_x,  tex_coord_frame_y);
    glVertex2f(  size_x + *position_x,  size_y + *position_y);
    
    glTexCoord2f(  tex_coord_frame_x,  tex_coord_frame_y);
    glVertex2f( -size_x + *position_x,  size_y + *position_y);
    
    glEnd();
}

void Sprite::animate(const int sprites_x, const int sprites_y, float velocity, int *current_frame_x, int *current_frame_y) {
    
}