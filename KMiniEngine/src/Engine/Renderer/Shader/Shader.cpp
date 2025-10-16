#include "Shader.h"	
#include <iostream>
#include <glad/glad.h>
#include <cassert>


Shader::Shader(const char* shaderSource, SHADER_TYPE shaderType)
{
	if (shaderType == SHADER_TYPE::VERTEX)
	{
		m_shaderID = glCreateShader(GL_VERTEX_SHADER);
	}
	else
	{
		m_shaderID = glCreateShader(GL_FRAGMENT_SHADER);
	}

	glShaderSource(m_shaderID, 1, &shaderSource, nullptr);
	m_shaderSource = shaderSource;
	TryShaderCompilation();
}

Shader::~Shader()
{
	glDeleteShader(m_shaderID);
}

unsigned int Shader::GetShaderID() const
{
	return m_shaderID;
}

void Shader::TryShaderCompilation()
{
	glCompileShader(m_shaderID);
	GLint shaderDidCompile = 0;
	GLint shaderType = 0;
	glGetShaderiv(m_shaderID, GL_COMPILE_STATUS, &shaderDidCompile);
	glGetShaderiv(m_shaderID, GL_SHADER_TYPE, &shaderType);
	if (shaderDidCompile == GL_FALSE)
	{
		GLint infoLogLength = 0;
		glGetShaderiv(m_shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
		char errorMessage[512];
		glGetShaderInfoLog(m_shaderID, infoLogLength, &infoLogLength, &errorMessage[0]);
		std::cout << "ERROR: Shader compilation failed:\n" << errorMessage
			<< "Shader type: " << (shaderType == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") << "\n"
			<< "Source: " << m_shaderSource << "\n\n";
	}
	assert(shaderDidCompile);
}