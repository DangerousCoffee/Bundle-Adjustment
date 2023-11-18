#include "BA_Algorithm.h";

struct Point {
	int id;
	float x;
	float y;
	float z;

	Point(int id, float x, float y, float z) {
		this->id = id;
		this->x = x;
		this->y = y;
		this->z = z;
	}
};