cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 23)
set(PROJECT_NAME KMiniEngine)

project(${PROJECT_NAME})

set(PROJECT_BINARY_NAME KMiniEngineLib)

add_library(${PROJECT_BINARY_NAME} STATIC

        include/Application/Application.h
        include/Application/Window.h
        include/Core/EngineMain.h
        include/Core/Layer.h
        "include/Assets/Primitive Geometry/StaticObject.h"
        include/Debugging/ImGUI/ImGUILayer.h
        include/IO/FileSystem/FileHandler.h
        include/Renderer/Shader/Shader.h
        include/Renderer/Shader/ShaderHandler.h
        include/Renderer/Shader/ShaderProgram.h
        include/Renderer/RenderConfigs.h
        include/Renderer/Renderer.h
        include/Resources/ModelLoading/Mesh.h
        include/Resources/ModelLoading/Model.h
        include/Scene/Camera/Camera.h
        include/KMiniEngine.h
        src/Application/Application.cpp
        src/Application/Window.cpp
        src/Debugging/ImGUI/ImGUILayer.cpp
        src/IO/FileSystem/FileHandler.cpp
        src/Renderer/Renderer.cpp
        src/Resources/ModelLoading/Mesh.cpp
        src/Resources/ModelLoading/Model.cpp
        src/Scene/Camera/Camera.cpp)

target_include_directories(${PROJECT_BINARY_NAME}
        PUBLIC
            include
            vendor/include)

target_link_libraries(${PROJECT_BINARY_NAME}
            PUBLIC
                vendor/lib/assimp-vc143-mtd.lib
                vendor/lib/glfw3.lib)

set_target_properties(${PROJECT_BINARY_NAME}
        PROPERTIES
            LINKER_LANGUAGE CXX)
