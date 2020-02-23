#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <iostream>
#include <GLFW/glfw3.h>

class Window
{
    public:
        Window(unsigned int, unsigned int, std::string);
        ~Window();        

        void clear();
        void display();
        void makeCurrent();
        bool shouldClose();        

    private:
        unsigned int _width;
        unsigned int _height;
        std::string _title;

        GLFWwindow* _window;
};

#endif
