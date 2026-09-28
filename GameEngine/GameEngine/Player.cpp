#include "Player.h"
#include <iostream>
#include <windows.h>

Player::Player(float startX, float startY, float rotZ) 
    : x(startX), y(startY), zRotation(rotZ) {
    speed = 6;

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
    x += dirX * speed * 60;
    y += dirY * speed * 60;
};
void Player::updateToCursor(float mouseX, float mouseY) {
    if (true) {
        float dx = (mouseX - x);
        float dy = (mouseY - y);
        zRotation = (atan2f(dy, dx));
        std::cout << dx << " " << dy << "::" << zRotation << "\n";
    }
};

void Player::draw(unsigned int shaderProgram) {
    glUseProgram(shaderProgram);

    int offsetXnY = glGetUniformLocation(shaderProgram, "uOffset");
    glUniform2f(offsetXnY, x, y);

    int rotationZ = glGetUniformLocation(shaderProgram, "uRotZ");
    glUniform1f(rotationZ, zRotation);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
};