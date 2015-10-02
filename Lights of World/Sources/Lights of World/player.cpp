//
//  player.cpp
//  Lights of World
//
//  Created by Vinicius A.M. Lobo on 24/09/15.
//  Copyright © 2015 Vinicius A.M. Lobo. All rights reserved.
//

#include <iostream>
#include <math.h>

#include "player.hpp"
#include "game.hpp"
#include "graphics.hpp"
#include "sprites.hpp"

#include <GLFW/glfw3.h>

namespace {
    const float kSlowdownFactor=0.7f;
    const float kWalkingAcceleration=0.01f;
    const float kMaxSpeedX=0.6f;
    
    /*
    const float kAccelerationY=0.8;
    const float kMaxSpeedY=9.8f;
    */
}

Player::Player()
{
    
}

Player::~Player()
{
    
}

void Player::KillPlayer()
{
    player_flags.is_alive_ = false;
    player_current_status_ = DEAD;
    
    // As condições para que funcione as mortes do personagem;
}

void Player::DamagePlayer(int damage)
{
    player_flags.life_count_ -= damage;
    
    if (player_flags.life_count_ < 0) {
        player_flags.life_count_ = 0;
        KillPlayer();
    }
}

void Player::LifePlayer(int life)
{
    player_flags.life_count_ += life;
    
    if (player_flags.life_count_ > player_flags.max_life_) {
        player_flags.life_count_ -= (player_flags.max_life_ - player_flags.life_count_);
    }
}

void Player::kDrawPlayer(float x_size, float y_size)
{
    /*
    player_image_ = SDL_LoadBMP("/Users/Programmer/Desktop/data.bmp");
    
    int id=0;
    y_size += x_size/2;
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    
    glBindTexture(GL_TEXTURE_2D, id);
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    glTexImage2D(GL_TEXTURE_2D, 0, 2, player_image_->w, player_image_->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, player_image_->pixels);

    glBegin(GL_QUADS);

    glTexCoord2f(tex_coord_x_pos-(1.0f/19), tex_coord_y_pos);
    glVertex2d( -x_size+x_, -y_size);

    glTexCoord2f(tex_coord_x_pos, tex_coord_y_pos);
    glVertex2d(  x_size+x_, -y_size);

    glTexCoord2f(tex_coord_x_pos, tex_coord_y_pos-(1.0f/tex_frames_y_));
    glVertex2d(  x_size+x_,  y_size);

    glTexCoord2f(tex_coord_x_pos-(1.0f/19), tex_coord_y_pos-(1.0f/tex_frames_y_));
    glVertex2d( -x_size+x_,  y_size);

    glEnd();

    delete player_image_; */
    
    player_spr->draw(x_size, y_size, &x_, &y_, "contents/player.bmp");
    
}

void Player::kStartJump()
{
    if (player_colision_y_==ON_GROUND) {
        
    } else if (player_colision_y_==OFF_GROUND) {
        
    } else {
        
    }
}

void Player::kStopJump()
{
    player_colision_y_=OFF_GROUND;
}

void Player::kDeactivateColision()
{
}

void Player::kActivateColision()
{
}

bool Player::kLeftColisionWall()
{
    player_colision_x_=ON_WALL;
    return true;
}

bool Player::kRightColisionWall()
{
    player_colision_x_=ON_WALL;
    return true;
}

void Player::kUpdatePlayer()
{
    x_ += velocity_x_;
    velocity_x_ += acceleration_x_;
    
    if (acceleration_x_ < 0.0f) {
        velocity_x_ = std::max(acceleration_x_, -kMaxSpeedX);
    } else if (acceleration_x_ > 0.0f) {
        velocity_x_ = std::min(acceleration_x_,  kMaxSpeedX);
    } else {
        velocity_x_ *= kSlowdownFactor;
    }
    
    if (player_horizontal_facing_ == LEFT) {
        if (player_current_status_==WALKING) {
            current_frame_y_ = 2.0f;
            
            if (current_frame_x_ > -(tex_frames_x_-1)) {
                current_frame_x_ -= 0.5f;
            }
            else
                current_frame_x_ = 0.0f;
            
        } else if (player_current_status_==STOPPED) {
            current_frame_y_ = 4.0f;
            
            if (current_frame_x_ > -(tex_frames_x_-1)) {
                current_frame_x_ -= 0.2f;
            }
            else
                current_frame_x_ = 0.0f;
            
        }
        
    } else if (player_horizontal_facing_ == RIGHT) {
        if (player_current_status_==WALKING) {
            current_frame_y_ = 1.0f;
            
            if (current_frame_x_ < (tex_frames_x_-1)) {
                current_frame_x_ += 0.5f;
            }
            else
                current_frame_x_ = 0.0f;
            
        } else if (player_current_status_==STOPPED) {
            current_frame_y_ = 3.0f;
            
            if (current_frame_x_ < (tex_frames_x_-1)) {
                current_frame_x_ += 0.2f;
            }
            else
                current_frame_x_ = 0.0f;
            
        }
    }
}

void Player::kMovingLeft()
{
    acceleration_x_ = -kWalkingAcceleration;
    
    player_horizontal_facing_ = LEFT;
    player_current_status_ = WALKING;
    
    tex_coord_y_pos = tex_coord_y_ * current_frame_y_;
    tex_coord_x_pos = tex_coord_x_ * round(current_frame_x_);
}

void Player::kMovingRight()
{
    acceleration_x_ = kWalkingAcceleration;
    
    player_horizontal_facing_ = RIGHT;
    player_current_status_ = WALKING;
    
    tex_coord_y_pos = tex_coord_y_ * current_frame_y_;
    tex_coord_x_pos = tex_coord_x_ * round(current_frame_x_);
}

void Player::kMovingStopped()
{
    acceleration_x_ = 0.0f;
    
    player_current_status_ = STOPPED;
    
    tex_coord_y_pos = tex_coord_y_ * current_frame_y_;
    tex_coord_x_pos = tex_coord_x_ * round(current_frame_x_);
}

void Player::kPlayerEvents(Graphics *graphics)
{
    if (graphics->kGameGetEvents(GLFW_KEY_RIGHT)) {
        kMovingRight();
    } else if (graphics->kGameGetEvents(GLFW_KEY_LEFT)) {
        kMovingLeft();
    } else {
        kMovingStopped();
    }

    if (graphics->kGameGetEvents(GLFW_KEY_UP)) {
        
    } else if (!graphics->kGameGetEvents(GLFW_KEY_UP)) {
        
    } else {
        
    }
}