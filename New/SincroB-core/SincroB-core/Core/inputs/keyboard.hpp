#ifndef _KEYBOARD_MODULES_
#define _KEYBOARD_MODULES_

#include <stdio.h>
#include <GLFW/glfw3.h>

namespace engine { namespace input {
    
    #define MAX_KEYBOARD_KEYS 1024
    
    enum KeyActions
    {
        NONE      = 0, /* Tecla Mantida Solta;     */
        PRESS     = 1, /* Tecla Precionada;        */
        HELD      = 2, /* Tecla Mantida Precionada */
        RELEASED  = 3, /* Tecla Solta;             */
    };
    
    typedef KeyActions keyActions;
    
    struct Keyboard
    {
        Keyboard();
        
        bool pressed = false;
        bool released = true;
        bool keyboard_keys[MAX_KEYBOARD_KEYS];
    };
} }

#endif // _KEYBOARD_MODULES_
