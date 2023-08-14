#include "Vector2.h"

void Vector2::add(Vector2* v2) {
	x += v2->x;
	y += v2->y;
	return;
}

void Vector2::subtract(Vector2* v2) {
	x -= v2->x;
	y -= v2->y;
	return;
}

void Vector2::dot(Vector2* v2) {
	x *= v2->x;
	y *= v2->y;
	return;
}

void Vector2::dot(float f) {
	x *= f;
	y *= f;
	return;
}