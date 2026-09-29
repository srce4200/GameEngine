#include "Player.h"
#include <iostream>
#include <windows.h>

Player::Player(float startX, float startY, float rotZ)  {
    speed = 6;

    transform.position.x = startX;
    transform.position.y = startY;
    transform.rotation.z = rotZ;

    float vertices[] = {
      0.1f,  0.0f, 0.0f,  // Top-left
     -0.1f,  -0.1f, 0.0f,  // Top-right
     -0.1f, 0.1f, 0.0f   // Bottom-right
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
};

Player::~Player() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
};

void Player::update(float dirX, float dirY) {
    transform.position.x += dirX * speed * 60;
    transform.position.y += dirY * speed * 60;
};
void Player::updateToCursor(float mouseX, float mouseY) {
    if (true) {
        float dx = (mouseX - transform.position.x);
        float dy = (mouseY - transform.position.y);
        transform.rotation.z = (atan2f(dy, dx));
    }
};

void Player::draw(unsigned int shaderProgram) {
    glUseProgram(shaderProgram);

    int offsetXnY = glGetUniformLocation(shaderProgram, "uOffset");
    glUniform2f(offsetXnY, transform.position.x, transform.position.y);

    int rotationZ = glGetUniformLocation(shaderProgram, "uRotZ");
    glUniform1f(rotationZ, transform.rotation.z);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
};