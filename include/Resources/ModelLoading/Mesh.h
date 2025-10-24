#pragma once
#include <glm/glm.hpp>
#include <vector>
#include <string>

class ShaderProgram;

enum DrawMode
{
	REGULAR,
	INSTANCED
};

struct VertexData {
	std::vector<glm::vec3> Positions;
	std::vector<glm::vec3> Normals;
	std::vector<glm::vec2> TexCoords;
};

struct Texture {
	unsigned int id;
	std::string type;
	std::string path;
};

class Mesh
{
public:
	Mesh(VertexData vertexData, std::vector<unsigned int> indices, std::vector<Texture> textures);
	void Draw(ShaderProgram* shaderProgram, DrawMode drawMode);
	void SetupOffsets(std::vector<glm::vec3>* offsets);
	void SetupInstanceCount(unsigned int instanceCount);
	void SetupMesh();

	VertexData m_vertexData;
	std::vector<unsigned int> m_indices;
	std::vector<Texture> m_textures;
	std::vector<glm::vec3> m_offsets;

private:
	unsigned int m_VAO, m_VBO, m_EBO, m_IBO;
	unsigned int m_instanceCount;
};

