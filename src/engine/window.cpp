#include "window.hpp"

Window::Window(const char *title, int width, int height)
{
    window_ = glfwCreateWindow(width, height, "title", NULL, NULL);
    glfwMakeContextCurrent(window_);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "ERR\n";
        glfwTerminate();
    }

    glViewport(0, 0, 640, 480);
}

GLFWwindow *Window::handle() const
{
    return window_;
}

bool Window::shoudlClose() const
{
    return glfwWindowShouldClose(window_);
}

void Window::pollEvents()
{
    glfwPollEvents();
}

void Window::swapBuffers()
{
    glfwSwapBuffers(window_);
}

void Window::processInputs()
{
}
