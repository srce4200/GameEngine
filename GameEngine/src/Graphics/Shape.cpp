
#include "Shape.h"

Shape::Shape() {
	float verticals[] = {
      -0.1f, 0.1f, 0.0f,  // Top-left
      0.1f, 0.1f, 0.0f,  // Top-right
      -0.1f, -0.1f, 0.0f,   // Bottom-left

     -0.1f, -0.1f, 0.0f,  // Bottom-left
      0.1f, 0.1f, 0.0f,  // Top-right
      0.1f, -0.1f, 0.0f  // Bottom-right
	};
    numOfVert = sizeof(verticals) / 3;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticals), verticals, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
};
Shape::~Shape() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}
void Shape::draw(unsigned int shaderProgram, Vector3 position, Vector3 rotation) {
    glUseProgram(shaderProgram);

    int offsetXnY = glGetUniformLocation(shaderProgram, "uOffset");
    glUniform2f(offsetXnY, position.x, position.y);

    int rotationZ = glGetUniformLocation(shaderProgram, "uRotZ");
    glUniform1f(rotationZ, rotation.z);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, numOfVert);
    glBindVertexArray(0);
};