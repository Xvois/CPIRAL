#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "VAO.hpp"
#include "VBO.hpp"
#include "Shader.hpp"

std::string read_file(const char* filepath)
{
	std::ifstream file(filepath);
	if (!file.is_open())
	{
		std::cerr << "Failed to open file: " << filepath << std::endl;
		return "";
	}

	std::stringstream stream;
	stream << file.rdbuf();
	file.close();

	return stream.str();
}


int main() {

	// Define vertex positions for a triangle
	std::vector<glm::vec3> positions = {
		glm::vec3(0.0f, 0.0f, 0.0f),  // Vertex 0
		glm::vec3(-0.5f, -0.5f, -0.5f),  // Vertex 1
		glm::vec3(0.5f, 0.5f, 0.5f)  // Vertex 2
	};

	// Initialise GLFW for use
	glfwInit();

	// Set OpenGL context version to 4.6 and use core profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create window and make its context current
	GLFWwindow* window = glfwCreateWindow(800, 800, "CPIRAL", NULL, NULL);
	glfwMakeContextCurrent(window);

	// Load OpenGL function pointers with glad
	gladLoadGL();

	// Set viewport to match window size
	glViewport(0, 0, 800, 800);

	// Create and bind Vertex Array Object (VAO) and Vertex Buffer Object (VBO)
	VAO VAO;  // VAO is a custom class
	VBO VBO;  // VBO is a custom class
	VAO.bind();
	VBO.bind();

	// Set VBO data to the vertex positions
	const GLuint size = (GLsizei)(positions.size() * sizeof(glm::vec3));
	VBO.setData(size, &positions, GL_DYNAMIC_DRAW);

	// Add the VBO to the VAO at position 0, with 3 components per vertex (x, y, z)
	VAO.addVBO(VBO.id(), 0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// Unbind VBO and VAO
	VBO.unbind();
	VAO.unbind();

	GLfloat dotColor[] = { 1.0f, 1.0f, 1.0f };
	Shader shader("default.vert", "default.frag");
	glUniform3fv(glad_glGetUniformLocation(shader.id(), "dotColor"), 1, dotColor);

	

	while (!glfwWindowShouldClose(window)) {
		// Clear screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Use the shader
		shader.use();

		// Draw the VAO
		VAO.bind();
		glDrawArrays(GL_POINTS, 0, 3);
		VAO.unbind();

		// Swap buffers and poll events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	std::cout << "Hello, Universe!" << std::endl;
	return 0;
}