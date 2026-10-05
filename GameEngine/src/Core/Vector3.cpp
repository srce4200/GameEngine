#include "Vector3.h"
#include <cmath>



Vector3::Vector3() {};
Vector3::Vector3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
};

float Vector3::Distance(Vector3 from, Vector3 to) {
	float dx = to.x - from.x;
	float dy = to.y - from.y;
	float dz = to.z - from.z;

	return (dx*dx+dy*dy+dz*dz);
}