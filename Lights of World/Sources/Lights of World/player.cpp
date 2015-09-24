//
//  player.cpp
//  Lights of World
//
//  Created by Vinicius A.M. Lobo on 24/09/15.
//  Copyright © 2015 Vinicius A.M. Lobo. All rights reserved.
//

#include <iostream>

#include "player.hpp"
#include "graphics.hpp"
#include <GLFW/glfw3.h>

namespace {
    const float kPlayerAcceleration = 0.0012f;
    const float kPlayerVelocity = 0.02;
}

Player::Player() {
    
}

Player::~Player() {
    
}

void Player::KillPlayer() {
    player_flags.is_alive_ = false;
}

void Player::DamagePlayer(int damage) {
    player_flags.life_count_ -= damage;
    
    if (player_flags.life_count_ < 0) {
        player_flags.life_count_ = 0;
        KillPlayer();
    }
}

void Player::LifePlayer(int life) {
    player_flags.life_count_ += life;
    
    if (player_flags.life_count_ > player_flags.max_life_) {
        player_flags.life_count_ -= (player_flags.max_life_ - player_flags.life_count_);
    }
}

void Player::kMovingLeft() {
    std::cout << "Moving Left" << std::endl;
}

void Player::kMovingRight() {
    std::cout << "Moving Right" << std::endl;
}

void Player::kMovingStopped() {
    std::cout << "Moving Stopped" << std::endl;
}

void Player::kPlayerEvents(Graphics *graphics) {
    if (graphics->kGameGetEvents(GLFW_KEY_RIGHT)) {
        kMovingRight();
    } else if (graphics->kGameGetEvents(GLFW_KEY_LEFT)) {
        kMovingLeft();
    } else {
        kMovingStopped();
    }
}