//
//  objects.cpp
//  Lights of World
//
//  Created by Vinicius A.M. Lobo on 20/01/16.
//  Copyright © 2016 Vinicius A.M. Lobo. All rights reserved.
//

#include "objects.hpp"

#include <iostream>
#include <GLUT/glut.h>

SimpleBox::SimpleBox() {
    
}

SimpleBox::~SimpleBox() {
    
}

void SimpleBox::kApplyMovement() {
    
}

void SimpleBox::kObjectDraw(float _x_size_, float _y_size_) {
    
    glBegin(GL_QUADS);
    
    for (int _vert=0; _vert<4; _vert++) {
        float _x_vert_, _y_vert_;
        
        _x_vert_ = (_vert==0 | _vert==3) * _x_size_;
        _y_vert_ = (_vert==2 | _vert==3) * _y_size_;
        
        if (!(_vert==0 | _vert==3)) { _x_vert_ -= _x_size_; }
        if (!(_vert==2 | _vert==3)) { _y_vert_ -= _y_size_; }
        
        glVertex2d(_x_vert_ + x_, _y_vert_ + y_);
    }
    
    glEnd();
    glFlush();
    
}

// Desenho da Linha;
FinderLine::FinderLine() {
    std::cout << "Finder Line OK" << std::endl;
}

FinderLine::~FinderLine() {
    
}

void FinderLine::kDrawLine(float* find_x_, float* find_y_) {
    
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    
    glVertex2d(start_x_, start_y_); // Ponto Inicial da Linha;
    glVertex2d(*find_x_, *find_y_); // Ponto Final da Linha;
    
    glEnd();
    glFlush();
    
}



// Criação de Objetos Complexos;
ObjectComplex::ObjectComplex() {
    
}

ObjectComplex::~ObjectComplex() {
    
}

/* == Estruturas iniciais, estruturas de movimentação e desenhos == */
void ObjectComplex::kObjectDraw(float _x_size_, float _y_size) {
    
}

void ObjectComplex::kApplyMovement(float _x_, float _y_) {
    
}

void ObjectComplex::kApplyRotation(float _force_) {
    
}

void ObjectComplex::kRunPhysics(void) {
    
}

/* == Estruturas privadas == */
















