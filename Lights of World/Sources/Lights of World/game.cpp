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
#include "player.hpp"

Game::Game(): k_game_running(true) {
    kGameLoop();
}

Game::~Game() {
    
}

void Game::kGameLoop() {
    
    Graphics graphics;
    Player player;
    
    while (k_game_running) {
        glClear(GL_COLOR_BUFFER_BIT);

        kGameEvents(&graphics, &player);
        
        player.kDrawPlayer(0.075f+0.02f, 0.2f+0.05f);
        player.kUpdatePlayer();
        
        glfwSwapBuffers(graphics.windowSpace);
        glfwPollEvents();
    }
}

void Game::kGameEvents(Graphics *graphics, Player *player) {
    /* Verifica Todos os Eventos */
    if (graphics->kGameGetEvents(GLFW_KEY_ESCAPE)) {
        k_game_running = false;
    }
    player->kPlayerEvents(graphics);
}