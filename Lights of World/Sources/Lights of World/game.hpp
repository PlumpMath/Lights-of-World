//
//  Game.hpp
//  Lights of World
//
//  Created by Vinicius A.M. Lobo on 21/09/15.
//  Copyright © 2015 Vinicius A.M. Lobo. All rights reserved.
//

#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <GLFW/glfw3.h>
#include <stdio.h>

struct Graphics;

struct Game {
    Game();
    ~Game();
    
    void kGameLoop();
    void kGameEvents(Graphics *graphics);
    
    //INTER
    float interColor[4];
    
private:
    bool k_game_running;
    
};

#endif /* _GAME_HPP_ */