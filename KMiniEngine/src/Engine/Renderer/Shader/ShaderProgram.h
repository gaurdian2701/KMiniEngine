#pragma once
class Shader;
#include <string>
#include <glm/glm.hpp>
#include <unordered_map>
#include "glad/glad.h"

class ShaderProgram
{
public:
	ShaderProgram(Shader* vertexShader, Shader* fragmentShader);
	~ShaderProgram();
	void Use() const;
	unsigned int GetID() const;
	void SetBool(const std::string& name, bool value);
	void SetInt(const std::string& name, int value);
	void SetFloat(const std::string& name, float value);
	void SetMat4(const std::string& name, const float* value);
	void SetVec2Float(const std::string& name, glm::vec2 floatVec);
	void SetVec3Float(const std::string& name, glm::vec3 floatVec);

private:
	unsigned int m_shaderProgramID = 0;
	std::unordered_map<std::string, GLint> m_uniformMap;

	GLint GetUniformLocation(const std::string& uniformName);
};

