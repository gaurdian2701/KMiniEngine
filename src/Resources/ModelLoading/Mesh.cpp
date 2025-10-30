#include "Resources/ModelLoading/Mesh.h"
#include "glad/glad.h"
#include "Rendering/Shading/ShaderProgram.h"

Resources::ModelLoading::Mesh::Mesh(VertexData vertexData,
                                    std::vector<unsigned int> indices,
                                    std::vector<Texture> textures)
{
	m_vertexData = vertexData;
	m_indices = indices;
	m_textures = textures;
}

void Resources::ModelLoading::Mesh::SetupMesh()
{
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);

    glBindVertexArray(m_VAO);

    size_t positionsArraySize = sizeof(glm::vec3) * m_vertexData.Positions.size();
    size_t normalsArraySize = sizeof(glm::vec3) * m_vertexData.Normals.size();
    size_t texCoordsArraySize = sizeof(glm::vec2) * m_vertexData.TexCoords.size();
    size_t offsetsArraySize = sizeof(glm::vec3) * m_offsets.size();

    if (offsetsArraySize > 0)
    {
        glGenBuffers(1, &m_IBO);
        glBindBuffer(GL_ARRAY_BUFFER, m_IBO);
        glBufferData(GL_ARRAY_BUFFER, offsetsArraySize, m_offsets.data(), GL_STATIC_DRAW);
        glEnableVertexAttribArray(3);
        glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
        glVertexAttribDivisor(3, 1);
    }

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER,
        positionsArraySize + normalsArraySize + texCoordsArraySize,
        nullptr, GL_STATIC_DRAW);

    if (positionsArraySize > 0)
    {
        glBufferSubData(GL_ARRAY_BUFFER, 0, positionsArraySize, m_vertexData.Positions.data());
    }

    if (normalsArraySize > 0)
    {
        glBufferSubData(GL_ARRAY_BUFFER, positionsArraySize, normalsArraySize, m_vertexData.Normals.data());
    }

    if (texCoordsArraySize > 0)
    {
        glBufferSubData(GL_ARRAY_BUFFER, positionsArraySize + normalsArraySize,
            texCoordsArraySize, m_vertexData.TexCoords.data());
    }

    // vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    // vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0,
        (void*)positionsArraySize);

    // vertex texture coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0,
        (void*)(positionsArraySize + normalsArraySize));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int),
        m_indices.data(), GL_STATIC_DRAW);

    glBindVertexArray(0);
}

void Resources::ModelLoading::Mesh::Draw(Rendering::Shading::ShaderProgram* shaderProgram, DrawMode drawMode)
{
    unsigned int diffuseNr = 1;
    unsigned int specularNr = 1;
    unsigned int normalNr = 1;
    unsigned int heightNr = 1;

    for (unsigned int i = 0; i < m_textures.size(); i++)
    {
        glActiveTexture(GL_TEXTURE0 + i);
        std::string number;
        std::string name = m_textures[i].type;
        if (name == "texture_diffuse")
            number = std::to_string(diffuseNr++);
        else if (name == "texture_specular")
            number = std::to_string(specularNr++);
        else if (name == "texture_normal")
            number = std::to_string(normalNr++);
        else if (name == "texture_height")
            number = std::to_string(heightNr++);

        shaderProgram->SetInt(("material." + name + number).c_str(), i);
        glBindTexture(GL_TEXTURE_2D, m_textures[i].id);
    }

    glBindVertexArray(m_VAO);

    if (drawMode == DrawMode::REGULAR)
    {
        glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);
    }
    else
    {
        glDrawElementsInstanced(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0, m_instanceCount);
    }

    glBindVertexArray(0);
    glActiveTexture(GL_TEXTURE0);
}

void Resources::ModelLoading::Mesh::SetupOffsets(std::vector<glm::vec3>* offsets)
{
    m_offsets = *offsets;
}

void Resources::ModelLoading::Mesh::SetupInstanceCount(unsigned int instanceCount)
{
    m_instanceCount = instanceCount;
}
