#include "window.hpp"

namespace engine { namespace graphics {
    
    // Declaração dos Callbacks;
    void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
    void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
    void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
    
    Window::Window()
    {
        _title = "Window";
        _width = 800;
        _height = 600;
        
        if (!initWindow())
            std::cout << "Ouve um erro ao inicializar a janela!" << std::endl;
        
        glfwMakeContextCurrent(_window);
        glfwSetWindowUserPointer(_window, this);
        
        // Callbacks;
        glfwSetKeyCallback(_window, key_callback);
        glfwSetMouseButtonCallback(_window, mouse_button_callback);
        glfwSetCursorPosCallback(_window, cursor_position_callback);
    }

    Window::Window(const char *title, int width, int height)
    {
        _title = title;
        _width = width;
        _height = height;
        
        if (!initWindow())
            std::cout << "Ouve um erro ao inicializar a janela!" << std::endl;
        
        glfwMakeContextCurrent(_window);
        glfwSetWindowUserPointer(_window, this);
        
        // Callbacks principais (Keyboard; Mouse e Posição do Cursor);
        glfwSetKeyCallback(_window, key_callback);
        glfwSetMouseButtonCallback(_window, mouse_button_callback);
        glfwSetCursorPosCallback(_window, cursor_position_callback);
    }

    Window::~Window()
    {
        glfwTerminate();
    }

    bool Window::initWindow()
    {
        /*
         
         Caso ocorra qualquer erro na inicialização do GLFW ou na
         criação da janela, essa função ira impedir que o programa
         fique em loop e trave o computador;
         
         */

        // Inicializa o GLFW;
        if (!glfwInit())
        {
            std::cout << "Erro ao inicializar o GLFW!" << std::endl;
            return false;
        }
        
        // Criação da janela;
        _window = glfwCreateWindow(_width, _height, _title, NULL, NULL);
        
        // Verifica se o valor da janela não é nulo;
        if (!_window)
        {
            printf("Erro ao setar janela!");
            glfwTerminate();
            return false;
        }
        
        return true;
    }

    bool Window::closedWindow() const
    {
        return !glfwWindowShouldClose(_window);
    }

    void Window::updateWindow() const
    {
        glfwSwapBuffers(_window);
        glfwPollEvents();
    }

    void Window::clearWindow() const
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }
    
    // Eventos;
    int Window::isKeyPressed(unsigned int key)
    {
        return this->_keyboard->keyboard_keys[key];
    }

    int Window::isMouseButtonPressed(unsigned int button) const
    {
        return this->_mouse->mouse_buttons[button];
    }
    
    // Definição dos Callbacks;
    void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        Window *_window = (Window *) glfwGetWindowUserPointer(window);
        _window->_keyboard->keyboard_keys[key] = action;
    }

    void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
    {
        Window *_window = (Window *) glfwGetWindowUserPointer(window);
        _window->_mouse->mouse_buttons[button] = action;
    }

    void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
    {
        Window *_window = (Window *) glfwGetWindowUserPointer(window);
        
        // Evita passar o limite da tela;
        if (xpos>_window->_width) xpos = _window->_width;
        if (xpos<0.0) xpos = 0.0;
        
        if (ypos>_window->_height) ypos = _window->_height;
        if (ypos<0.0) ypos = 0.0;
        
        _window->_mouse->position.x = (float) xpos;
        _window->_mouse->position.y = (float) ypos;
    }
} }