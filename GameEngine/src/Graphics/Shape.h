#pragma once

#include <glad/glad.h>
#include <cmath>
#include "../Core/Vector3.h"

struct Shape {
public:
	void draw(unsigned int shaderProgram, Vector3 position, Vector3 rotation);
	Shape(const float* firstVertical, size_t arraySize);
	~Shape();
private:
	unsigned int VAO, VBO;
	int numOfVert;
};