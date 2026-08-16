#include "shader.hpp"

Shader::Shader()
{
}

void Shader::load(const char *vertexPath, const char *fragmentPath)
{
    // load char from file create source files

    std::string line;

    std::string vertexSource;
    std::string fragmentSource;
    const char *vertexShaderSource;
    const char *fragmentShaderSource;

    std::ifstream vertexFileStream(vertexPath);
    std::ifstream fragmentFileStream(fragmentPath);

    // TODO : clean up logs
    if (!vertexFileStream.is_open())
    {
        std::cout << "Cant open vertex shader file\n";
    }
    if (!fragmentFileStream.is_open())
    {
        std::cout << "Cant open fragment shader file\n";
    }
    while (getline(vertexFileStream, line))
    {
        vertexSource += line;
        vertexSource += "\n";
    }
    while (getline(fragmentFileStream, line))
    {
        fragmentSource += line;
        fragmentSource += "\n";
    }

    vertexShaderSource = vertexSource.c_str();
    fragmentShaderSource = fragmentSource.c_str();

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // create the program
    shaderProgram_ = glCreateProgram();

    // Attach our Shaders to this program
    glAttachShader(shaderProgram_, vertexShader);
    glAttachShader(shaderProgram_, fragmentShader);
    glLinkProgram(shaderProgram_);

    // delete OpenGL
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::useProgram()
{
    glUseProgram(shaderProgram_);
}