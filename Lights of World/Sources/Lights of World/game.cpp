//
//  Game.cpp
//  Lights of World
//
//  Created by Vinicius A.M. Lobo on 21/09/15.
//  Copyright © 2015 Vinicius A.M. Lobo. All rights reserved.
//

#include <iostream>

#include "graphics.hpp"
#include "game.hpp"

Game::Game() {
    kGameLoop();
}

Game::~Game() {
    
}

void Game::kGameLoop() {
    Graphics graphics;
    
    while (k_game_running) {
        
        glfwSwapBuffers(graphics.windowSpace);
        glfwPollEvents();
    }
}

void Game::kGameEvents() {
}