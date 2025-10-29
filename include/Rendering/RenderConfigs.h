#pragma once
#include <string>
#include <filesystem>
#include "glm/glm.hpp"

namespace Rendering
{
    //SCREEN CONFIGS
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 800;
    const glm::vec4 BACKGROUND_COLOUR(0.7f, 0.6f, 0.3f, 0.9f);

    //CAMERA CONFIGS
    const float CAMERA_SPEED = 5.0f;
    const glm::vec3 CAMERA_STARTING_POSITION(0.0, 0.0f, 3.0f);
    const float RENDER_DISTANCE = 0;

    //LIGHT CONFIGS
    const glm::vec3 LIGHT_SOURCE_POSITION(0.0f, 0.0, -10.0f);
    const glm::vec3 LIGHT_SOURCE_COLOR(0.5f, 1.0f, 1.0f);

    //MATERIAL CONFIGS
    const glm::vec3 AMBIENT_MATERIAL_COLOR(1.0f, 0.5f, 0.31f);
    const glm::vec3 DIFFUSE_MATERIAL_COLOR(1.0f, 0.5f, 0.31f);
    const glm::vec3 SPECULAR_MATERIAL_COLOR(0.5f, 0.5f, 0.5f);
    const float SPECULAR_MATERIAL_SHININESS = 8.0f;

    //MODEL CONFIGS
    const std::string MODEL_PATH = std::filesystem::path{"3DModels/grass/grass.obj"}.string();

    //VERTEX SHADER FILE PATHS
    const std::string SIMPLE_OBJECT_VERTEX_SHADER_FILEPATH = "shaders/simpleObject.vert";
    const std::string SWAYING_OBJECT_VERTEX_SHADER_FILEPATH = "shaders/swayingObject.vert";

    //FRAGMENT SHADER FILE PATHS
    const std::string SIMPLE_OBJECT_FRAGMENT_SHADER_FILEPATH = "shaders/simpleObject.frag";
    const std::string PHONG_LIGHTING_FRAGMENT_SHADER_FILEPATH = "shaders/phongLighting.frag";
    const std::string GRASS_RENDER_FRAGMENT_SHADER_FILEPATH = "shaders/grassRender.frag";


    //TEXTURE FILE PATHS
    const std::string CONTAINER_TEXTURE_FILEPATH = "textures/container.png";
    const std::string CONTAINER_SPECULAR_TEXTURE_FILEPATH = "textures/container_specular.png";

    //GRASS CONFIGS
    constexpr unsigned int NUMBER_OF_ROWS = 1000;
    constexpr unsigned int NUMBER_OF_COLUMNS = 1000;
    constexpr float MIN_LATERAL_RANDOM_OFFSET = 0.5f;
    constexpr float MAX_LATERAL_RANDOM_OFFSET = 0.8f;
    constexpr float MIN_VERTICAL_RANDOM_OFFSET = 0.0f;
    constexpr float MAX_VERTICAL_RANDOM_OFFSET = 0.5f;
    constexpr unsigned int NUMBER_OF_OBJECTS = NUMBER_OF_ROWS * NUMBER_OF_COLUMNS;

}
