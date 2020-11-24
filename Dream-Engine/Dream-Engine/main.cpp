//Main source file for Dream-Engine

#include <iostream>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include "main.h"


// Initializing OpenGL and Creating a window using GLFW

void InitGL()
{
	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
	{
		// Initialization failed
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
	if (!window)
	{
		// Window or context creation failed
	}
	

}
void main()
{
	
}
