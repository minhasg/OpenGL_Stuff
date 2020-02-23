#define GLFW_STATIC
#define STB_IMAGE_IMPLEMENTATION
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec4.hpp>
#include <stb/stb_image.h>

#include "Triangle.h"
#include "Rectangle.h"
#include "Shader.h"
#include "Window.h"

#include <iostream>
#include <cmath>

void printOpenGLInfo()
{
    std::cout << "Printing OpenGL information:\n";
    std::cout << glGetString(GL_VERSION) << std::endl;
    std::cout << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

int main()
{
    std::cout << "Initializing glfw\n";
	if(!glfwInit())
	{
        std::cout << "Failed to initialize GLFW!\n";
		return -1;
	}
	Window window(800, 600, "Hurh");
    window.makeCurrent();    
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW!\n";
        return -2;
    }
    
    printOpenGLInfo();
    Triangle tri;
    tri.move(-0.5f, 0.0f);
    tri.bindShader("shaders/BasicTriangle");
    Rectangle rect;
    float startTime = glfwGetTime();
    float dt = 0;
    
    std::cout << "Entering main loop.\n";
	while(!window.shouldClose())
	{
        // Update time
        dt = glfwGetTime() - startTime;
        startTime = glfwGetTime();

        glfwPollEvents();
        window.clear();
        
        tri.getShader().setUniform("time", (0.5f + std::sin(startTime) * 0.5f)); 

        // Draw everything
        //std::cout << "Drawing triangle.\n";
        //tri.rotate(dt);
        tri.setPosition(1.0f * std::sin(2 * glfwGetTime()), 1.0f * std::cos(3 * glfwGetTime()));
        tri.setAngle(std::sin(2.5f * glfwGetTime()));
        tri.scale(std::sin(glfwGetTime()) + 1.0f, std::cos(glfwGetTime()) + 1.0f);
        tri.draw();
        //rect.draw();        

        // Swap buffers
        //std::cout << "Swapping buffers.\n";
		window.display();
	}
	glfwTerminate();
	return 0;

}
