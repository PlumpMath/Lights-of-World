//
//  object.cpp
//  Lights of World
//
//  Created by Vinicius A.M. Lobo on 24/01/16.
//  Copyright © 2016 Vinicius A.M. Lobo. All rights reserved.
//

#include <GLFW/glfw3.h>
#include <GLUT/glut.h>

#include <iostream>
#include <string>

#include "object.hpp"

// Game Object
GameObject::GameObject() {
    // Position && Scale;
	localPosition[0] = 0.0f;
	localPosition[1] = 0.0f;

	localScale[0] = 0.2f;
	localScale[1] = 0.2f;
}

GameObject::~GameObject() {
    
}

bool GameObject::kColisionDetect(GameObject *object) {
    bool left_right = ((localPosition[0] + localScale[0]) >= object->localPosition[0]) && (localPosition[0] <= (object->localPosition[0] + object->localScale[0]));
    bool up_down = ((localPosition[1] + localScale[1]) >= object->localPosition[1]) && (localPosition[1] <= (object->localPosition[1] + object->localScale[1]));
    
    return (left_right && up_down);
}

void GameObject::kDraw() {

    glBegin(GL_QUADS);
    
    for (int _vertex=0; _vertex<4; _vertex++) {
        
        float _vertex_x = (_vertex==0 || _vertex==3) * localScale[0];
        float _vertex_y = (_vertex==2 || _vertex==3) * localScale[1];
        
        glVertex2f(_vertex_x + localPosition[0], _vertex_y + localPosition[1]);
        
    }
    
    glEnd();
    glFlush();
}


// Text Object
TextObject::TextObject() {
    
    // Inicializações;
    kSetColor(1.0f, 1.0f, 1.0f, 1.0f);
    
    Text = "TextObject";
    Font = GLUT_BITMAP_HELVETICA_12;
}

TextObject::~TextObject() {
    
}

void TextObject::kDraw() {
    
    glBegin(GL_BITMAP);
    glColor4f(textColor[0], textColor[1], textColor[2], textColor[3]);
    glRasterPos2f(localPosition[0], localPosition[1]);
    
    for (int _index=0; _index<std::strlen(Text); _index++) {
        glutBitmapCharacter(Font, Text[_index]);
    }
    
    glEnd();
    glFlush();
}

// Funções Continuas;
void TextObject::kSetColor(float red, float green, float blue, float alpha) {
    
    textColor[0] = red;
    textColor[1] = green;
    textColor[2] = blue;
    textColor[3] = alpha;
}

void TextObject::kFadeToColor(float red, float green, float blue, float alpha) {
    
    textColor[0] += (red   - textColor[0]);
    textColor[1] += (green - textColor[1]);
    textColor[2] += (blue  - textColor[2]);
    textColor[3] += (alpha - textColor[3]);
}
