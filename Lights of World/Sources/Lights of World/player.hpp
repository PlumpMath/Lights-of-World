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
    
    void kMovingLeft();
    void kMovingRight();
    void kMovingStopped();
    
    void kPlayerEvents(Graphics *graphics);
    
private:
    enum PlayerFacing {
        LEFT, RIGHT
    };
    
    PlayerFacing player_horizontal_facing_;
    PlayerFlags  player_flags;
};

#endif /* player_hpp */
