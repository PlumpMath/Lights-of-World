//
//  graphics.hpp
//  Lights of World
//
//  Created by Vinicius A.M. Lobo on 22/09/15.
//  Copyright © 2015 Vinicius A.M. Lobo. All rights reserved.
//

#ifndef graphics_hpp
#define graphics_hpp

#include <stdio.h>

struct GLFWwindow;

struct Graphics {
    Graphics();
    ~Graphics();
    
    GLFWwindow *windowSpace;
    
    void kGameWindow();
    
private:
    char *windowTitle[50];
};

#endif /* graphics_hpp */
