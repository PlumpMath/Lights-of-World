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
#include "objects.hpp"

Game::Game(): k_game_running(true) {
    kGameLoop();
}

Game::~Game() {
    
}

void Game::kGameLoop() {
    
    Graphics graphics;
    Player player;
    
    //SimpleBox box;
    FinderLine player_finder;
    FinderLine ground_simulation;
    float ground_endl=1.0f;
    
    while (k_game_running) {
        
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);
        
        kGameEvents(&graphics, &player);
        
        
        // Desenho da caixa;
        // box.kObjectDraw(0.10f, 0.15f);
        player_finder.kDrawLine(&player.position_x, &player.position_y);
        
        player.kDrawPlayer(0.075f+0.025f, 0.2f);
        player.kUpdatePlayer();
        
        ground_simulation.start_x_ = -1.00f;
        ground_simulation.start_y_ = -0.95f;
        
        ground_simulation.kDrawLine(&ground_endl, &ground_simulation.start_y_);
        
        glfwSwapBuffers(graphics.windowSpace);
        glfwPollEvents();
        
    }
    glfwTerminate();
}

void Game::kGameEvents(Graphics *graphics, Player *player) {
    /* Verifica Todos os Eventos */
    if (graphics->kGameGetEvents(GLFW_KEY_ESCAPE)) {
        k_game_running = false;
    }
    
    player->kPlayerEvents(graphics);
}