#pragma once
#include "glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>
#include <glm/ext/matrix_transform.hpp>
#include "../../Renderer/Shader/ShaderProgram.h"

class StaticObject
{
public:
	StaticObject(const glm::vec3& objectColor,
		const glm::vec3& objectPosition,
		const glm::mat4& projectionTransformationMatrix,
		ShaderProgram* shaderProgram)
	{
		glm::mat4 modelTransformationMatrix = glm::mat4(1.0f);
		modelTransformationMatrix = glm::translate(modelTransformationMatrix, objectPosition);

		shaderProgram->Use();
		shaderProgram->SetVec3Float("aColor", objectColor);
		shaderProgram->SetMat4("modelTransformationMatrix", glm::value_ptr(modelTransformationMatrix));
		shaderProgram->SetMat4("projectionTransformationMatrix", glm::value_ptr(projectionTransformationMatrix));
	}

	void Draw(ShaderProgram* shaderProgram,
		glm::mat4& viewTransformationMatrix)
	{
		shaderProgram->Use();
		shaderProgram->SetMat4("viewTransformationMatrix", glm::value_ptr(viewTransformationMatrix));
	}
};
