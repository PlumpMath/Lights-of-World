//
//  graphics.hpp
//  Lights of World
//
//  Created by Vinicius A.M. Lobo on 22/09/15.
//  Copyright © 2015 Vinicius A.M. Lobo. All rights reserved.
//

#ifndef _GRAPHICS_HPP_
#define _GRAPHICS_HPP_

#include <stdio.h>

struct GLFWwindow;

struct Graphics {
    Graphics();
    ~Graphics();
    
    GLFWwindow* windowSpace;
    
    bool kGameGetEvents(int key);
};

#endif /* _GRAPHICS_HPP_ */