#include "VAO.hpp"

VAO::VAO() {
    glGenVertexArrays(1, &m_vaoID);
}

VAO::~VAO() {
    glDeleteVertexArrays(1, &m_vaoID);
}

void VAO::bind() {
    glBindVertexArray(m_vaoID);
}

void VAO::unbind() {
    glBindVertexArray(0);
}

void VAO::addVBO(GLuint vbo, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* offset) {
    bind();
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(index, size, type, normalized, stride, offset);
    glEnableVertexAttribArray(index);
    unbind();
}