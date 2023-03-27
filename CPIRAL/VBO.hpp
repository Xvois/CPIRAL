#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VBO {
	public:
		void bind();
		void unbind();
		GLuint id();
		void setData(GLsizei size, const void* data, GLenum usage);
		VBO();
		~VBO();
	private:
		GLuint m_vboID;
};