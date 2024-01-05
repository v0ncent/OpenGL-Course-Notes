#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

const char* vertexShaderSource = "#version 330 core\n"  "layout (location = 0) in vec3 aPos;\n"  "void main()\n"  "{\n"  "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"  "}\0";
const char* fragmentShaderSource = "#version 330 core\n"  "out vec4 FragColor;\n"  "void main()\n"  "{\n"  "   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"  "}\n\0";
const char* windowName = "OpenGLCourseNotes";

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

	// Specify the color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
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