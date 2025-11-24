#pragma once
#include <string>
#include <filesystem>
#include "glm/glm.hpp"

namespace Rendering
{
    //SCREEN CONFIGS
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 800;
    const glm::vec4 BACKGROUND_COLOUR(0.0f, 0.0f, 0.0f, 1.0f);

    //CAMERA CONFIGS
    const float CAMERA_SPEED = 5.0f;
    const glm::vec3 CAMERA_STARTING_POSITION(0.0, 0.0f, 3.0f);
    const float RENDER_DISTANCE = 0;

    //MATERIAL CONFIGS
    const glm::vec3 AMBIENT_MATERIAL_COLOR(1.0f, 0.5f, 0.31f);
    const glm::vec3 DIFFUSE_MATERIAL_COLOR(1.0f, 0.5f, 0.31f);
    const glm::vec3 SPECULAR_MATERIAL_COLOR(0.5f, 0.5f, 0.5f);
    const float SPECULAR_MATERIAL_SHININESS = 8.0f;
}
