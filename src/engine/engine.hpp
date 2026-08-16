#pragma once
#include <glad/glad.h>
#include <glfw3.h>
#include "shader.hpp"
#include "window.hpp"

class Engine
{
private:
    Window window_;
    Shader shadder_;

public:
    void initialize();
    void run();
};
