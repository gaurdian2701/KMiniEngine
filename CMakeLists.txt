cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 23)
project(KMiniEngine)

add_library(KMiniEngineLib

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
        include/KMiniEngine.h)

target_include_directories(KMiniEngineLib
        PUBLIC
            vendor/include)

set_target_properties(KMiniEngineLib
        PROPERTIES
            LINKER_LANGUAGE CXX)
