#include "Renderer/Shader/ShaderProgram.h"
#include "Renderer/Shader/Shader.h"

ShaderProgram::ShaderProgram(Shader* vertexShader, Shader* fragmentShader)
{
	m_shaderProgramID = glCreateProgram();
	glAttachShader(m_shaderProgramID, vertexShader->GetShaderID());
	glAttachShader(m_shaderProgramID, fragmentShader->GetShaderID());
	glLinkProgram(m_shaderProgramID);
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(m_shaderProgramID);
}

void ShaderProgram::Use() const
{
	glUseProgram(m_shaderProgramID);
}

unsigned int ShaderProgram::GetID() const
{
	return m_shaderProgramID;
}

void ShaderProgram::SetBool(const std::string& name, bool value)
{
	glUniform1i(GetUniformLocation(name), (int)value);
}

void ShaderProgram::SetInt(const std::string& name, int value)
{
	glUniform1i(GetUniformLocation(name), value);
}

void ShaderProgram::SetFloat(const std::string& name, float value)
{
	glUniform1f(GetUniformLocation(name), value);
}

void ShaderProgram::SetMat4(const std::string& name, const float* value)
{
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, value);
}

void ShaderProgram::SetVec2Float(const std::string& name, glm::vec2 floatVec)
{
	glUniform2f(GetUniformLocation(name), floatVec.x, floatVec.y);
}

void ShaderProgram::SetVec3Float(const std::string& name, glm::vec3 floatVec)
{
	glUniform3f(GetUniformLocation(name), floatVec.x, floatVec.y, floatVec.z);
}

GLint ShaderProgram::GetUniformLocation(const std::string& uniformName)
{
	if (m_uniformMap.find(uniformName) != m_uniformMap.end())
	{
		return m_uniformMap[uniformName];
	}
	m_uniformMap[uniformName] = glGetUniformLocation(m_shaderProgramID, uniformName.c_str());
	return m_uniformMap[uniformName];
}

