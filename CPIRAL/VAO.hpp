#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VAO {
    public:
        VAO(); // constructor
        ~VAO(); // destructor

        void bind(); // bind the VAO
        void unbind(); // unbind the VAO
        void addVBO(GLuint vbo, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* offset); // add a VBO to the VAO

    private:
        GLuint m_vaoID; // ID of the VAO
};

