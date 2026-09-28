#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <chrono>
#include <thread>

#include "Player.h"

// Helper function to read .vert and .frag text files
std::string loadShaderSource(const char* filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cout << "ERROR: Could not open shader file: " << filePath << std::endl;
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

Player* playerObject;
int width = 800, height = 600;
const static int TARGET_FRAMERATE = 120;

int main()
{
    glfwInit(); //Initialize GLFW
   
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //Config GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Windows creation
    GLFWwindow* window = glfwCreateWindow(800, 600, "Convoy Action", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
  
    glfwMakeContextCurrent(window);

    //Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate(); // Make sure to clean up GLFW if we fail here
        return -1;
    }

    //viewport and callbacks
    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //------------------------------------------------------
    //1. Convert std::string to C-style strings for OpenGL
    std::string vertCode = loadShaderSource("shader.vert");
    std::string fragCode = loadShaderSource("shader.frag");
    const char* vertexShaderSource = vertCode.c_str();
    const char* fragmentShaderSource = fragCode.c_str();

    // 2. Compile Vertex and Fragment Shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // 3. Link into Shader Program
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Delete temporary shader objects
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    //------------------------------------------------------//

    playerObject = new Player(0.2f, 0, 0);

    //MAIN LOOP
    while (!glfwWindowShouldClose(window))
    {
        //input
        processInput(window);

        //rendering
        glClearColor(0.3f, 0.6f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        playerObject->draw(shaderProgram);

        //check and call for buffer swap
        glfwSwapBuffers(window);
        glfwPollEvents();

        std::this_thread::sleep_for(std::chrono::milliseconds(1000/TARGET_FRAMERATE));
    }

    glDeleteProgram(shaderProgram);
    delete playerObject;
    glfwTerminate(); // Clean up resources
    return 0;
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        playerObject->update(0.0001f, 0);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        playerObject->update(-0.0001f, 0);
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        playerObject->update(0, 0.0001f);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        playerObject->update(0, -0.0001f);
    }


    //Cursor pos
    double relativeCursorX = 0.0;
    double relativeCursorY = 0.0;
    glfwGetCursorPos(window, &relativeCursorX, &relativeCursorY);
    glfwGetWindowSize(window, &width, &height);
    float mouseXClamped = (2.0f * relativeCursorX / width) - 1.0f;
    float mouseYClamped = 1.0f - (2.0f * relativeCursorY / height); //invert bc otherwise broken

    playerObject->updateToCursor(mouseXClamped, mouseYClamped);
}