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

Graphics::Graphics() {
    if (!glfwInit()) {
        std::cout << "Erro com Frameworks" << std::endl;
    }
    glfwShowWindow(windowSpace);
}

Graphics::~Graphics() {
    /* Destrução de Janelas e Funções com o GLFW */
    glfwTerminate();
}

void Graphics::kGameWindow() {
    
}