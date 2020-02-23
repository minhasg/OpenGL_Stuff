#include "Window.h"
#include <GLFW/glfw3.h>

Window::Window(unsigned int width, unsigned int height, std::string title)
{
    _width = width;
    _height = height;
    _title = title;

    _window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
}

Window::~Window()
{
    glfwDestroyWindow(_window);
}

void Window::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::display()
{
    glfwSwapBuffers(_window);
}

void Window::makeCurrent()
{
    glfwMakeContextCurrent(_window);
}

bool Window::shouldClose()
{
    return glfwWindowShouldClose(_window);
}
