#include <glad/glad.h>
#include <glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

void readVertexFromFile(const char *filename)
{
}

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                   "}\n\0";

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f};

int main()
{
    GLFWwindow *window;

    // init GLFW
    if (!glfwInit())
    {
        std::cout << "GLFW failed to Initialize\n";
        return -1;
    }

    window = glfwCreateWindow(1200, 800, "Minecraft", NULL, NULL);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        glfwTerminate();
        return -1;
    }

    glViewport(0, 0, 640, 480);
    glClearColor(0.25f, 0.5f, 0.75f, 1.0f);

    // Vertex shader parts
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // fragment Shader parts
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // create shader program
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();

    // Attach our Shaders to this program
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Use this new program and delete the older ones

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Vertex Buffer Obj Data parts
    GLuint vbo_id;
    glGenBuffers(1, &vbo_id);

    // Vertex Buffer Arrary
    unsigned int vao_id;
    glGenVertexArrays(1, &vao_id);

    // 1. bind Vertex Array Object
    glBindVertexArray(vao_id);
    // 2. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // 3. then set our vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        processInput(window);

        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(vao_id);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}