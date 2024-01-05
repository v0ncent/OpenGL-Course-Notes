#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "Constants.h"

int main() {
	// init glfw
	glfwInit();

	// Tell glfw what version of OpenGL we are using
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create glfw window
	GLFWwindow* window = glfwCreateWindow(800, 800, windowName, NULL, NULL);

	// Error check if the window fails to create
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// set wwindow into current context
	glfwMakeContextCurrent(window);

	//Load glad so it configures OpenGL
	gladLoadGL();

	// Specify the viewport of OpenGL in the Window
	// In this casee the viewport (fromX fromY, toX toY)
	glViewport(0, 0, 800, 800);

	backgroundColor -> R = 0.07f;
	backgroundColor -> G = 0.13f;
	backgroundColor -> B = 0.17f;
	backgroundColor -> C  = 1.0f;

	// Specify the color of the background
	glClearColor(backgroundColor -> R, backgroundColor -> G, backgroundColor -> B, backgroundColor -> C);
	// Clean the back buffer and assign a new color to it
	glClear(GL_COLOR_BUFFER_BIT);
	// Swap the back buffer with the front buffer
	glfwSwapBuffers(window);

	// Main while loop
	while (!glfwWindowShouldClose(window)) {

		// Take care of all GLFW events
		glfwPollEvents();
	}

	// delete window when done
	glfwDestroyWindow(window);
	// Terminate glfw
	glfwTerminate();
	return 0;
}