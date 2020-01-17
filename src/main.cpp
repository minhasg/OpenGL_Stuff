#define GLFW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec4.hpp>

#include "Triangle.h"

#include <iostream>

int main()
{
    std::cout << "Initializing glfw\n";
	if(!glfwInit())
	{
        std::cout << "Failed to initialize GLFW!\n";
		return -1;
	}
	GLFWwindow* window = glfwCreateWindow(800, 600, "Hurh", NULL, NULL);
	glfwMakeContextCurrent(window);
    
    if(glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW!\n";
        return -2;
    }
    
    Triangle tri;
    
    std::cout << "Entering main loop.\n";
	while(!glfwWindowShouldClose(window))
	{   	
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        std::cout << "Drawing triangle.\n";
        tri.draw();
        

        std::cout << "Swapping buffers.\n";
		glfwSwapBuffers(window);
        
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;

}
