#include "Scene/Camera/Camera.h"
#include <GLFW/glfw3.h>
#include "Rendering/RenderConfigs.h"

float m_lastX = Rendering::SCREEN_WIDTH / 2.0f;
float m_lastY = Rendering::SCREEN_HEIGHT / 2.0f;

Scene::Camera::Camera(glm::vec3 cameraPosition, glm::vec3 cameraFront, glm::vec3 cameraUp, GLFWwindow* window, float cameraSpeed)
{
	m_window = window;
	m_cameraPosition = cameraPosition;
	m_cameraFront = cameraFront;
	m_cameraSpeed = cameraSpeed;
	m_cameraViewMatrix = glm::lookAt(cameraPosition, cameraFront, cameraUp);
	RotateCamera();
}

glm::mat4 Scene::Camera::GetViewMatrix()
{
	m_cameraViewMatrix = glm::lookAt(m_cameraPosition, m_cameraPosition + m_cameraFront, glm::vec3(0.0f, 1.0f, 0.0f));
	return m_cameraViewMatrix;
}

glm::vec3 Scene::Camera::GetCameraPosition() const
{
	return m_cameraPosition;
}

void Scene::Camera::ProcessInput(float deltaTime)
{
	MoveCamera(deltaTime);
	RotateCamera();
}

void Scene::Camera::MouseCallback(double xpos, double ypos)
{
	if (m_firstMouse)
	{
		m_lastX = xpos;
		m_lastY = ypos;
		m_firstMouse = false;
	}

	float xoffset = xpos - m_lastX;
	float yoffset = m_lastY - ypos;
	m_lastX = xpos;
	m_lastY = ypos;

	float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	m_yaw += xoffset;
	m_pitch += yoffset;

	if (m_pitch > 89.0f)
		m_pitch = 89.0f;
	if (m_pitch < -89.0f)
		m_pitch = -89.0f;
}

void Scene::Camera::MoveCamera(float deltaTime)
{
	if (glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS)
	{
		m_cameraPosition += m_cameraSpeed * m_cameraFront * deltaTime;
	}

	if (glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS)
	{
		m_cameraPosition -= m_cameraSpeed * m_cameraFront * deltaTime;
	}

	if (glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS)
	{
		m_cameraPosition -= glm::normalize(glm::cross(m_cameraFront,
			glm::vec3(0.0f, 1.0f, 0.0f))) * m_cameraSpeed * deltaTime;
	}

	if (glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS)
	{
		m_cameraPosition += glm::normalize(glm::cross(m_cameraFront,
			glm::vec3(0.0f, 1.0f, 0.0f))) * m_cameraSpeed * deltaTime;
	}
}

void Scene::Camera::RotateCamera()
{
	m_cameraFront.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));	
	m_cameraFront.y = sin(glm::radians(m_pitch));
	m_cameraFront.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	m_cameraFront = glm::normalize(m_cameraFront);
}
