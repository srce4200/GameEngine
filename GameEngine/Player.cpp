#include "Player.h"
#include <iostream>
#include <windows.h>

Triangle* tr;

Player::Player(float startX, float startY, float rotZ)  {
    speed = 6;

    tr = new Triangle();

    transform.position.x = startX;
    transform.position.y = startY;
    transform.position.z = 0;
    transform.rotation.z = rotZ;
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
    tr->draw(shaderProgram, transform.position, transform.rotation);
};