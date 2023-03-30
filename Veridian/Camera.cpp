#include "Camera.h"

Camera::Camera(Vector2* pos, int w, int h) : pos(pos), w(w), h(h) {}

Vector2 Camera::TransformWorldToLocal(Vector2 worldCoordinates) {
	transformVector = worldCoordinates;
	transformVector.Subtract(*pos);
	transformVector.Dot(zoom*16);
	return transformVector;
}


