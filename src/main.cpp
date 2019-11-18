#define GLFW_STATIC
#include <GLFW/glfw3.h>

int main()
{
	if(!glfwInit())
	{
		return -1;
	}
	GLFWwindow* window = glfwCreateWindow(800, 600, "Hurh", NULL, NULL);
	glfwMakeContextCurrent(window);

	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glfwSwapBuffers();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;

}
