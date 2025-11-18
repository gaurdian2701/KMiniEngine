cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 23)
set(PROJECT_NAME KMiniEngine)

project(${PROJECT_NAME})

set(ENGINE_BINARY_NAME KMiniEngineLib)
set(VENDOR_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor/include)

add_library(
        ${ENGINE_BINARY_NAME}
            STATIC
                ${CMAKE_CURRENT_SOURCE_DIR}/src/Application/Application.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/src/Application/Window.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/src/Debugging/ImGUI/ImGUILayer.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/src/IO/FileSystem/FileHandler.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/src/Rendering/Renderer.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/src/Resources/ModelLoading/Mesh.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/src/Resources/ModelLoading/Model.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/src/Scene/Camera/Camera.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/src/Rendering/Shading/ShaderProgram.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/src/IO/Input/InputSystem.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Events/EventSystem.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/GameScene.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/ECS/ECSManager.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/ECS/Systems/MovementSystem.cpp
                ${VENDOR_INCLUDE_DIR}/imgui/imgui.cpp
                ${VENDOR_INCLUDE_DIR}/imgui/imgui_demo.cpp
                ${VENDOR_INCLUDE_DIR}/imgui/imgui_draw.cpp
                ${VENDOR_INCLUDE_DIR}/imgui/imgui_impl_glfw.cpp
                ${VENDOR_INCLUDE_DIR}/imgui/imgui_impl_opengl3.cpp
                ${VENDOR_INCLUDE_DIR}/imgui/imgui_tables.cpp
                ${VENDOR_INCLUDE_DIR}/glad/glad.c
                ${VENDOR_INCLUDE_DIR}/imgui/imgui_widgets.cpp
        include/Core/ECS/Components/ComponentFactory.h
        include/Core/ECS/Components/Rigidbody.h
        include/Core/ECS/Components/ComponentBitset.h
        include/Core/ECS/Systems/ISystem.h)

target_include_directories(
        ${ENGINE_BINARY_NAME}
            PUBLIC
                ${CMAKE_CURRENT_SOURCE_DIR}/include
                ${CMAKE_CURRENT_SOURCE_DIR}/vendor/include)

target_link_libraries(
        ${ENGINE_BINARY_NAME}
            PUBLIC
                ${CMAKE_CURRENT_SOURCE_DIR}/vendor/lib/glfw3.lib
                ${CMAKE_CURRENT_SOURCE_DIR}/vendor/lib/assimp-vc143-mtd.lib)

set_target_properties(${ENGINE_BINARY_NAME}
        PROPERTIES
            LINKER_LANGUAGE CXX)
