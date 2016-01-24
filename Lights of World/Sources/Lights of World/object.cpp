//
//  object.cpp
//  Lights of World
//
//  Created by Vinicius A.M. Lobo on 24/01/16.
//  Copyright © 2016 Vinicius A.M. Lobo. All rights reserved.
//

#include <GLFW/glfw3.h>
#include "object.hpp"

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
        
        float _vertex_x = (_vertex==0 | _vertex==3) * localScale[0];
        float _vertex_y = (_vertex==2 | _vertex==3) * localScale[1];
        
        glVertex2f(_vertex_x + localPosition[0], _vertex_y + localPosition[1]);
        
    }
    
    glEnd();
    glFlush();
}