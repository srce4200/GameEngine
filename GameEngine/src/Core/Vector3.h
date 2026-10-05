#pragma once

struct Vector3 {
public:
	float x, y, z;
	
	Vector3();
	Vector3(float x,float y,float z);

	static Vector3 Zero() { return Vector3(0.0f, 0.0f, 0.0f); }
	static Vector3 Up() { return Vector3(0.0f, 1.0f, 0.0f); }
	static Vector3 Down() { return Vector3(0.0f, -1.0f, 0.0f); }
	static Vector3 Left() { return Vector3(-1.0f, 0.0f, 0.0f); }
	static Vector3 Right() { return Vector3(1.0f, 0.0f, 0.0f); }
	static Vector3 Forward() { return Vector3(0.0f, 0.0f, 1.0f); }
	static Vector3 Back() { return Vector3(0.0f, 0.0f, -1.0f); }

	static float Distance(Vector3 from, Vector3 to);
};