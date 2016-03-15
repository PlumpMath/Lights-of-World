#ifndef _MOUSE_MODULES_
#define _MOUSE_MODULES_

#include <stdio.h>
#include "../maths.hpp"

namespace engine { namespace input {

#define MAX_MOUSE_BUTTONS 32
    
    struct Mouse
    {
        Mouse();
        
        maths::vec2 position;
        maths::vec2 raySource;
        
        bool mouse_buttons[MAX_MOUSE_BUTTONS];
    };
    
} }

#endif // _MOUSE_MODULES_
