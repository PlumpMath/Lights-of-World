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
    
    bool kGameGetEvents(int key);
    
private:
    
};

#endif /* graphics_hpp */
