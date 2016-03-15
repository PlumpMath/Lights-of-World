#include "mouse.hpp"

namespace engine { namespace input {
    
    Mouse::Mouse()
    {
        // Inicialização dos botões como false;
        for (int button=0; button<MAX_MOUSE_BUTTONS; button++)
            mouse_buttons[button] = false;
    }
    
} }