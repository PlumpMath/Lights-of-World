//
//  graphics.cpp
//  Lights of World
//
//  Created by Vinicius A.M. Lobo on 22/09/15.
//  Copyright © 2015 Vinicius A.M. Lobo. All rights reserved.
//

#include <GLFW/glfw3.h>
#include <iostream>

#include "graphics.hpp"

namespace {
    const int kWindowWidth=1280;
    const int kWindowHeight=800;
}

Graphics::Graphics() {
    
    if (!glfwInit()) {
        std::cout << "Erro com Frameworks" << std::endl;
    }
    
    windowSpace = glfwCreateWindow(kWindowWidth, kWindowHeight, "Lights of World", glfwGetPrimaryMonitor(), NULL);
    glfwMakeContextCurrent(windowSpace);
}

Graphics::~Graphics() {
    /* Destrução de Janelas e Funções com o GLFW */
    glfwTerminate();
}

bool Graphics::kGameGetEvents(int key) {
    return glfwGetKey(windowSpace, key);
}