#pragma once
#include <glad/glad.h>
#include <glfw3.h>
#include <fstream>
#include <iostream>
class Shader
{
public:
    Shader();
    ~Shader();

    void load(const char *vertexPath, const char *fragmentPath);
    void useProgram();

private:
    GLuint shaderProgram_;
};