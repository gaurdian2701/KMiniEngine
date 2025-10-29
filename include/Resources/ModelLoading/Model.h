#pragma once
#include <vector>
#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include "assimp/postprocess.h"
#include "Mesh.h"

namespace Rendering::Shading
{
	class ShaderProgram;
}

namespace Resources::ModelLoading
{
	class Model
	{
	public:
		Model(const char* modelPath);
		void Draw(Rendering::Shading::ShaderProgram* shaderProgram, DrawMode drawMode);
		void SetupMeshes();
		void SetupOffsets(std::vector<glm::vec3>* offsets);
		void SetupInstanceCount(unsigned int instancedCount);

	private:
		std::vector<Mesh> m_meshes;
		std::vector<Texture> m_loadedTextures;
		std::string m_meshDirectory = "";

		void LoadModel(std::string modelPath);
		void ProcessNode(aiNode* node, const aiScene* scene);
		Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
		std::vector<Texture> LoadMaterialTextures(aiMaterial* material, aiTextureType textureType, std::string textureTypename);
		unsigned int TextureFromFile(const char* path, const std::string& directory, bool gamma);
	};
}

