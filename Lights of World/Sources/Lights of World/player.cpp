//
//  player.cpp
//  Lights of World
//
//  Created by Vinicius A.M. Lobo on 24/09/15.
//  Copyright © 2015 Vinicius A.M. Lobo. All rights reserved.
//

#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

#include "image.hpp"

#include "graphics.hpp"
#include "object.hpp"
#include "player.hpp"

Player::Player() {
    // Position && Scale
    localScale[0] = 0.1f;
    localScale[1] = 0.3f;
    
    localPosition[0] = 0.5f;
    localPosition[1] = 0.0f;

	// Color
	playerColor[0] = 1.0f;
	playerColor[1] = 1.0f;
	playerColor[2] = 1.0f;
	playerColor[3] = 1.0f;
}

Player::~Player() {
    
}

bool Player::kColisionDetect(GameObject *object) {
    
    bool left_right = ((localPosition[0] + localScale[0]) >= object->localPosition[0]) && (localPosition[0] <= (object->localPosition[0] + object->localScale[0]));
    bool up_down = ((localPosition[1] + localScale[1]) >= object->localPosition[1]) && (localPosition[1] <= (object->localPosition[1] + object->localScale[1]));
    
    return (left_right && up_down);
}

// voids
void Player::kDraw(void) {
    
	//image::loadImage("image.png", 300, 400);
	int x_size_tex=70;
	int y_size_tex=47;

	std::vector<unsigned char> player_texture=image_loader::loadImage("./bandeira.png", &x_size_tex, &y_size_tex);

	std::cout << player_texture << "testes" << std::endl;

    // Anexos Iniciais;
    glColor4f(playerColor[0], playerColor[1], playerColor[2], playerColor[3]);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_ALPHA);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //GL_NEAREST = no smoothing
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, x_size_tex, y_size_tex, 0, GL_RGBA, GL_UNSIGNED_BYTE, &player_texture[0]);
    
    glBegin(GL_QUADS);
    
    // Inicialização do Desenho;
    for (int _vertex=0; _vertex<4; _vertex++) {
        
        float _vertex_x = (_vertex==0 | _vertex==3) * localScale[0];
        float _vertex_y = (_vertex==2 | _vertex==3) * localScale[1];
        
		glTexCoord2f(!(_vertex==0 | _vertex==3), !(_vertex==2 | _vertex==3));
        glVertex2f(_vertex_x + localPosition[0], _vertex_y + localPosition[1]);
    }
    
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_ALPHA);
    
    glFlush();
    
}

void Player::kEvents(Graphics *graphics) {
    
    /* Verifica Todos os Eventos */
    if (graphics->kGameGetEvents(GLFW_KEY_W)) {
        localPosition[1] += 0.005f;
        
    } if (graphics->kGameGetEvents(GLFW_KEY_A)) {
        localPosition[0] -= 0.005f;
        
    } if (graphics->kGameGetEvents(GLFW_KEY_S)) {
        localPosition[1] -= 0.005f;
        
    } if (graphics->kGameGetEvents(GLFW_KEY_D)) {
        localPosition[0] += 0.005f;
        
    }
}