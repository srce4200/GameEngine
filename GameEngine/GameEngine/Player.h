#pragma once

#include <glad/glad.h>
#include <cmath>

struct  Player
{
private:
	unsigned int VAO, VBO;
public:
	float x, y;
	float zRotation;
	float speed;
	
	Player(float startX, float startY, float rotZ);
	~Player(); //destructor

	void update(float dirX, float dirY);
	void updateToCursor(float mouseX, float mouseY);
	void draw(unsigned int shaderProgram);
};