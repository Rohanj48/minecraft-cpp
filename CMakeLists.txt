cmake_minimum_required(VERSION 3.20)
project(minecraft-cpp)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED )

add_executable(main
    src/main.cpp
    dependencies/glad/src/glad.c
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