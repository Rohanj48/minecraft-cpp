cmake_minimum_required(VERSION 3.20)
project(minecraft-cpp)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED )

add_executable(main
    src/main.cpp
    dependencies/glad/src/glad.c
    src/engine/Engine.cpp
    src/engine/window.hpp
    src/engine/window.cpp
    src/engine/engine.hpp
    src/engine/shader.cpp
)

target_include_directories(main PRIVATE
    src/include
    dependencies/GLFW/include
    dependencies/glad/include
)

target_link_libraries(main PRIVATE
    ${CMAKE_SOURCE_DIR}/dependencies/GLFW/lib/glfw3.lib
    OpenGL::GL
)