#pragma once

struct Shader
{
	unsigned int ID;
	float uOffsetPos;
	float uOffsetRot;

	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();

	void use() const;
};