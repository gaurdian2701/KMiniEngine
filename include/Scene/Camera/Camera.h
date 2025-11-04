#pragma once
#include "GLFW/glfw3.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Core
{
	class Camera
	{
	public:
		Camera(glm::vec3 cameraPosition, glm::vec3 cameraFront, glm::vec3 cameraUp, GLFWwindow* window, float cameraSpeed);
		void ProcessInput(float deltaTime);
		void MouseCallback(double xpos, double ypos);
		glm::mat4 GetViewMatrix();
		glm::vec3 GetCameraPosition() const;

	private:
		glm::mat4 m_cameraViewMatrix;
		glm::vec3 m_cameraPosition;
		glm::vec3 m_cameraFront;

		GLFWwindow* m_window;

		float m_cameraSpeed = 0.0f;
		float m_yaw = -90.0f;
		float m_pitch = 0.0f;
		const float m_cameraSensitivity = 0.1f;

		bool m_firstMouse = true;


		void MoveCamera(float deltaTime);
		void RotateCamera();
	};
}
