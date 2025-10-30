#include <iostream>
#include <glad/glad.h>
#include "Resources/ModelLoading/Model.h"
#include "Rendering/Shading/ShaderProgram.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


Resources::ModelLoading::Model::Model(const char* modelPath)
{
	LoadModel(modelPath);
}

void Resources::ModelLoading::Model::Draw(Rendering::Shading::ShaderProgram* shaderProgram, DrawMode drawMode)
{
	for(unsigned int i = 0; i < m_meshes.size(); i++)
	{
		m_meshes[i].Draw(shaderProgram, drawMode);
	}
}

void Resources::ModelLoading::Model::SetupMeshes()
{
	for (unsigned int i = 0; i < m_meshes.size(); i++)
	{
		m_meshes[i].SetupMesh();
	}
}

void Resources::ModelLoading::Model::SetupOffsets(std::vector<glm::vec3>* offsets)
{
	for (unsigned int i = 0; i < m_meshes.size(); i++)
	{
		m_meshes[i].SetupOffsets(offsets);
	}
}

void Resources::ModelLoading::Model::SetupInstanceCount(unsigned int instanceCount)
{
	for (unsigned int i = 0; i < m_meshes.size(); i++)
	{
		m_meshes[i].SetupInstanceCount(instanceCount);
	}
}

void Resources::ModelLoading::Model::LoadModel(std::string modelPath)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(modelPath, aiProcess_Triangulate | aiProcess_GenNormals);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
		return;
	}

	m_meshDirectory = modelPath.substr(0, modelPath.find_last_of('/'));
	ProcessNode(scene->mRootNode, scene);
}



void Resources::ModelLoading::Model::ProcessNode(aiNode* node, const aiScene* scene)
{
	for(unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		m_meshes.push_back(ProcessMesh(mesh, scene));
	}

	for (unsigned int i = 0; i < node->mNumChildren; i++)
	{
		ProcessNode(node->mChildren[i], scene);
	}
}

Resources::ModelLoading::Mesh Resources::ModelLoading::Model::ProcessMesh(aiMesh* mesh, const aiScene* scene)
{
	VertexData vertexData;
	std::vector<unsigned int> indices = {};
	std::vector<Texture> textures = {};

	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
	{
		glm::vec3 tempVec3 = {};
		glm::vec2 tempVec2 = {};

		tempVec3.x = mesh->mVertices[i].x;
		tempVec3.y = mesh->mVertices[i].y;
		tempVec3.z = mesh->mVertices[i].z;

		vertexData.Positions.push_back(tempVec3);

		tempVec3.x = mesh->mNormals[i].x;
		tempVec3.y = mesh->mNormals[i].y;
		tempVec3.z = mesh->mNormals[i].z;

		vertexData.Normals.push_back(tempVec3);

		if (mesh->mTextureCoords[0])
		{
			tempVec2.x = mesh->mTextureCoords[0][i].x;
			tempVec2.y = mesh->mTextureCoords[0][i].y;
			vertexData.TexCoords.push_back(tempVec2);
		}
		else
		{
			vertexData.TexCoords.push_back(glm::vec2(0.0f));
		}
	}

	for(unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for(unsigned int j = 0; j < face.mNumIndices; j++)
		{
			indices.push_back(face.mIndices[j]);
		}
	}

	if (mesh->mMaterialIndex >= 0)
	{
		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

		std::vector<Texture> diffuseMaps = LoadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
		textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
		std::vector<Texture> specularMaps = LoadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
		textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
		std::vector<Texture> normalMaps = LoadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
		textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
		std::vector<Texture> heightMaps = LoadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");
		textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());
	}

	return Mesh(vertexData, indices, textures);
}

std::vector<Resources::ModelLoading::Texture> Resources::ModelLoading::Model::LoadMaterialTextures(aiMaterial* material,
                                                                                                   aiTextureType textureType, std::string textureTypeName)
{
	std::vector<Texture> textures = {};
	for(unsigned int i = 0; i < material->GetTextureCount(textureType); i++)
	{
		aiString str;
		material->GetTexture(textureType, i, &str);
		bool skip = false;
		for(unsigned int j = 0; j < m_loadedTextures.size(); j++)
		{
			if(std::strcmp(m_loadedTextures[j].path.data(), str.C_Str()) == 0)
			{
				textures.push_back(m_loadedTextures[j]);
				skip = true;
				break;
			}
		}
		if(!skip)
		{
			Texture texture = {};
			texture.id = TextureFromFile(str.C_Str(), m_meshDirectory, false);
			texture.type = textureTypeName;
			texture.path = str.C_Str();
			textures.push_back(texture);
			m_loadedTextures.push_back(texture);
		}
	}
	return textures;
}

unsigned int Resources::ModelLoading::Model::TextureFromFile(const char* path, const std::string& directory, bool gamma)
{
	std::string filename = std::string(path);
	filename = directory + '/' + filename;

	unsigned int textureID;
	glGenTextures(1, &textureID);

	int width, height, nrComponents;
	unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
	if (data)
	{
		GLenum format{};
		if (nrComponents == 1)
			format = GL_RED;
		else if (nrComponents == 3)
			format = GL_RGB;
		else if (nrComponents == 4)
			format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_image_free(data);
	}
	else
	{
		std::cout << "Texture failed to load at path: " << path << std::endl;
		stbi_image_free(data);
	}

	return textureID;
}

