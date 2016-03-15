#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <GLFW/glfw3.h>

#include <OpenGL/gl.h>
#include <OpenGL/gl3.h>

#include <iostream>

#include "inputs.hpp"

namespace engine { namespace graphics {
  
    class Window
    {
    private:
        GLFWwindow *_window;
        int _width, _height;
        const char *_title;

        input::Keyboard *_keyboard = new input::Keyboard();
        input::Mouse *_mouse = new input::Mouse();
        
    public:
        Window(); // Construtor default;
        Window(const char *title, int width, int height); // Construtor;
        
        ~Window(); // Destrutor;
        
        // Funções para limpeza e atualização de janela;
        bool closedWindow() const;
        void updateWindow() const;
        void clearWindow() const;
        
        // Eventos;
        int isKeyPressed(unsigned int key);
        int isMouseButtonPressed(unsigned int button) const;
        
        // Vetores do Mouse;
        inline maths::vec2 getMousePosition() { return _mouse->position; };
        inline maths::vec2 getMouseRaySource() { return _mouse->raySource; };
        
    private:
        bool initWindow();
        
        // Declaração dos Callbacks como friends;
        friend void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
        friend void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
        friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
    };
    
} }
#endif // __WINDOW_HPP__