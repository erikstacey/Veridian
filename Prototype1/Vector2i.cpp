#include "Vector2i.h"

void Vector2i::add(Vector2i* v2) {
	x += v2->x;
	y += v2->y;
	return;
}

void Vector2i::subtract(Vector2i* v2) {
	x -= v2->x;
	y -= v2->y;
	return;
}

void Vector2i::dot(Vector2i* v2) {
	x *= v2->x;
	y *= v2->y;
	return;
}

void Vector2i::dot(int i) {
	x *= i;
	y *= i;
	return;
}