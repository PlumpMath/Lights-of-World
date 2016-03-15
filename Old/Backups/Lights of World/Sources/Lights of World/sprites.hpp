//
//  sprites.hpp
//  Lights of World
//
//  Created by Vinicius A.M. Lobo on 29/09/15.
//  Copyright © 2015 Vinicius A.M. Lobo. All rights reserved.
//

#ifndef sprites_hpp
#define sprites_hpp

#include <stdio.h>

struct Sprite {
    Sprite();
    ~Sprite();
    
    void draw(float size_x, float size_y, float *position_x, float *position_y, const char *file, int id=0);
    void animate(const int sprites_x, const int sprites_y, float velocity, int *current_frame_x, int *current_frame_y);
    
private:
    
    SDL_Surface *image_;
    
    int tex_sprites_x;
    int tex_sprites_y;
    
    float tex_coord_x;
    float tex_coord_y;
    
    float tex_coord_frame_x;
    float tex_coord_frame_y;
};

#endif /* sprites_hpp */
