#include "keyboard.hpp"

namespace engine { namespace input {
    
    Keyboard::Keyboard()
    {
        for (int key=0; key<MAX_KEYBOARD_KEYS; key++)
            keyboard_keys[key] = false;
    }
    
} }