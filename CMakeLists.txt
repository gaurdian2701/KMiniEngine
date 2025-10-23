cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 23)
project(KMiniEngine)
add_subdirectory(KMiniEngine/src/)

target_include_directories(KMiniEngine
PUBLIC
    KMiniEngine/vendor/include)