//
//  player.hpp
//  Lights of World
//
//  Created by Vinicius A.M. Lobo on 24/09/15.
//  Copyright © 2015 Vinicius A.M. Lobo. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <SDL/SDL.h>
#include <math.h>
#include "sprites.hpp"

struct Graphics;

struct PlayerFlags {
    bool is_alive_=true;
    int life_count_=100;
    
    int max_life_=100;
};

struct Player {
    Player();
    ~Player();
    
    void KillPlayer();
    void DamagePlayer(int damage);
    void LifePlayer(int life);
    void kDrawPlayer(float x_size, float y_size);
    void kUpdatePlayer();
    
    void kMovingLeft();
    void kMovingRight();
    void kMovingStopped();
    
    void kStartJump();
    void kStopJump();
    
    void kDeactivateColision();
    void kActivateColision();
    
    bool kLeftColisionWall();
    bool kRightColisionWall();
    
    void kJump(float gforce);
    
    void kPlayerEvents(Graphics *graphics);
    
public:
    float position_x, position_y;
    
    float x_=0.0f;
    float y_=0.0f;
    
private:
    enum PlayerFacing {
        LEFT, RIGHT
    };
    
    enum PlayerStatus {
        STOPPED, WALKING, DEAD
    };
    
    enum PlayerColision {
        ON_WALL, OFF_WALL, ON_GROUND, OFF_GROUND, NO_COLISION
    };
    
    SDL_Surface *player_image_;
    
    float current_position_x_=0.0f;
    float current_position_y_=0.0f;
    
    float current_frame_x_=1.0f;
    float current_frame_y_=0.0f;
    
    float acceleration_x_=0.0f;
    float acceleration_y_=0.0f;
    
    float velocity_x_=0.0f;
    float velocity_y_=0.0f;
    
    float tex_frames_x_ = 19.0f;
    float tex_frames_y_ =  4.0f;
    
    float tex_coord_x_ = (1.0f/tex_frames_x_);
    float tex_coord_y_ = (1.0f/tex_frames_y_);
    
    // Padronizadas
    float tex_coord_x_pos = tex_coord_x_ * current_frame_x_;
    float tex_coord_y_pos = tex_coord_y_ * current_frame_y_;
    
    PlayerFacing player_horizontal_facing_;
    PlayerFlags  player_flags;
    PlayerStatus player_current_status_=STOPPED;
    
    PlayerColision player_colision_y_=OFF_GROUND;
    PlayerColision player_colision_x_=OFF_WALL;
    
    Sprite *player_spr;
};

#endif /* player_hpp */
