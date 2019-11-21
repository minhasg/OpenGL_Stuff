#define GLFW_STATIC
#include <GLFW/glfw3.h>
#include <glm/vec4.hpp>

#include "Triangle.h"

int main()
{
	if(!glfwInit())
	{
		return -1;
	}
	GLFWwindow* window = glfwCreateWindow(800, 600, "Hurh", NULL, NULL);
	glfwMakeContextCurrent(window);

    Triangle tri;
    
	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;

}
