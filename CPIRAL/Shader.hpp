#pragma once
#include <string>
#include <glad/glad.h>

class Shader {
	public:
		Shader(const char* vertexFile, const char* fragmentFile);
		GLuint id();
		void use();
	private:
		std::string get_file_contents(const char* filename);
		GLuint s_id;
};