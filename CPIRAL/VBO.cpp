#include "VBO.hpp"

VBO::VBO() {
	glGenBuffers(1, &m_vboID);
}

VBO::~VBO() {
	glDeleteBuffers(1, &m_vboID);
}

void VBO::bind() {
	glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
}

void VBO::unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::setData(GLsizei size, const void* data, GLenum usage) {
	bind();
	glBufferData(GL_ARRAY_BUFFER, size, data, usage);
	unbind();
}

GLuint VBO::id() {
	return m_vboID;
}