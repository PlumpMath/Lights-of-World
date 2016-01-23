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
    
    while (k_game_running) {
        
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);

        glBegin(GL_LINES);
        
        glVertex2f(0.0f, 0.0f);
        glVertex2f(1.0f, 1.0f);
        
        glEnd();
        glFlush();
        
        kGameEvents(&graphics); /* Eventos */
        
        glfwSwapBuffers(graphics.windowSpace);
        glfwPollEvents();
        
    }
    glfwTerminate();
}

void Game::kGameEvents(Graphics *graphics) {
    /* Verifica Todos os Eventos */
    if (graphics->kGameGetEvents(GLFW_KEY_ESCAPE)) {
        k_game_running = false;
    }
}