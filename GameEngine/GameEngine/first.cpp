#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW\n";
        return -1;
    }

    // Create a window (640x480 pixels)
    GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL Test Window", NULL, NULL);
    if (!window) {
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Keep running until you close the window
    while (!glfwWindowShouldClose(window)) {
        // Clear the screen with a nice dark green/blue color
        glClearColor(0.1f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap the screen buffers
        glfwSwapBuffers(window);

        // Check for inputs (like clicking the 'X' button)
        glfwPollEvents();
    }

    // Clean up and close
    glfwTerminate();
    return 0;
}