#include "Vector2.h"
#include <cmath>

Vector2::Vector2() : x(0), y(0){
}

Vector2::Vector2(float x, float y) : x(x), y(y){
}

void Vector2::Add(Vector2 v) {
	// Add a vector v to this vector
	x = x + v.x; y = y + v.y;
}

void Vector2::Subtract(Vector2 v) {
	// Subtract a vector v from this vector. 
	x = x - v.x; y = y - v.y;
}

void Vector2::Dot(Vector2 v) {
	// Component-wise multiplication of this vector with another vector v
	x = x * v.x; y = y * v.y;
}
void Vector2::Dot(float f) {
	// Component-wise multiplication of this vector with a scalar quantity f
	x = x * f; y = y * f;
}
float Vector2::Mag() {
	// Returns the magnitude (length) of the vector
	return pow(pow(x, 2) + pow(y, 2), 0.5);
}
void Vector2::Norm() {
	// normalizes the vector, such that its length/magnitude is equal to 1
	x = x / this->Mag();
	y = y / this->Mag();
}
