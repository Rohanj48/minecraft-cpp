#pragma once

#include <iostream>
#include <glad/glad.h>
#include <glfw3.h>

// Lets Assume Only Window for now
class Window
{
public:
    Window(const char *title, int width, int height);
    ~Window();

    GLFWwindow *handle() const;

    bool shoudlClose() const;
    void pollEvents();
    void swapBuffers();
    void processInputs();

private:
    GLFWwindow *window_;
    int width_;
    int height_;
};