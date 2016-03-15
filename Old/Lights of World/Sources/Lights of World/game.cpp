//
//  Game.cpp
//  Lights of World
//
//  Created by Vinicius A.M. Lobo on 21/09/15.
//  Copyright © 2015 Vinicius A.M. Lobo. All rights reserved.
//

#include <GLFW/glfw3.h>
#include <GLUT/glut.h>

#include <iostream>

#include "game.hpp"

#include "graphics.hpp"
#include "object.hpp"
#include "player.hpp"

Game::Game(): k_game_running(true) {
    kGameLoop();
}

Game::~Game() {
    
}

void Game::kGameLoop() {
    
    Graphics graphics;
    Player player;

	// Objetos de Interação;
    GameObject box;
    GameObject red_box;
    
    // Texts
    TextObject simple_text;
    TextObject framerate_per_second;
    
    box.localPosition[0] = -0.3f;
    box.localPosition[1] = -0.3f;
    
    box.localScale[0] = 0.3f;
    box.localScale[1] = 0.3f;
    
    while (k_game_running) {
        
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);
        
        box.kDraw();
        player.kDraw();
        
        float fator=0.025f;
        
        simple_text.localPosition[0] = -1.00f;
        simple_text.localPosition[1] = -0.98f;
        
        simple_text.kDraw();
        
        framerate_per_second.localPosition[0] = -1.0f;
        framerate_per_second.localPosition[1] =  0.97;
        
        framerate_per_second.Text = "Operacional System: MacOS X 10.11.3 (El Capitan) ::1280x800::";
        
        framerate_per_second.kDraw();
        
        // Detecção de Colisão;
        if (player.kColisionDetect(&box)) {
            
            simple_text.Text = "SincroB Engine v0.0.1 <SmartObject player> ColisionDetect <GameObject box>";
            
            // Coloração do Player;
            player.playerColor[0] += (0.0f - player.playerColor[0]) * fator;
            player.playerColor[1] += (0.0f - player.playerColor[1]) * fator;
            player.playerColor[2] += (1.0f - player.playerColor[2]) * fator;
            player.playerColor[3] += (1.0f - player.playerColor[3]) * fator;
            
			// Criação da Intersection;
            glColor4f(player.playerColor[2], player.playerColor[1], player.playerColor[0], player.playerColor[3]);
            glBegin(GL_QUADS);
            
            float inter_x0, inter_x1;
            float inter_y0, inter_y1;
            
            if ((player.localPosition[0] + player.localScale[0]) <= (box.localPosition[0] + box.localScale[0])) {
                inter_x0 = player.localPosition[0] + player.localScale[0];} else {
                inter_x0 = 0.0f;}
            if (player.localPosition[0] >= box.localPosition[0]) {
                inter_x1 = player.localPosition[0]; } else {
                inter_x1 = box.localPosition[0];}
            
            if ((player.localPosition[1] + player.localScale[1]) <= (box.localPosition[1] + box.localScale[1])) {
                inter_y0 = player.localPosition[1] + player.localScale[1];} else {
                inter_y0 = 0.0f;}
            if (player.localPosition[1] >= box.localPosition[1]) {
                inter_y1 = player.localPosition[1]; } else {
                inter_y1 = box.localPosition[1];}
            
            glVertex2d(inter_x1, inter_y1);
            glVertex2d(inter_x0, inter_y1);
            glVertex2d(inter_x0, inter_y0);
            glVertex2d(inter_x1, inter_y0);
            
            glEnd();
            glFlush();
            
        } else {
            
            simple_text.Text = "SincroB Engine v0.0.1";
            
            player.playerColor[0] += (1.0f - player.playerColor[0]) * fator;
            player.playerColor[1] += (1.0f - player.playerColor[1]) * fator;
            player.playerColor[2] += (1.0f - player.playerColor[2]) * fator;
            player.playerColor[3] += (1.0f - player.playerColor[3]) * fator;
        }
        
        kGameEvents(&graphics); /* Eventos Gerais */
        player.kEvents(&graphics); /* Eventos do Jogo */
        
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