#pragma once
#include "Rectangle.h"
/*
Camera class defines a coordinate system corresponding to the display window (which may be different
from the actual screen window, e.g. a subwindow), and handles coordinate transformations from world coordinates
to local camera coordinates.
*/


class Camera
{
public:
	Vector2 pos; // bottom left
	Vector2 transformVector; // stores results of coordinate transforms
	int w = 0;
	int h = 0;
	float zoom = 1;
	Camera();
	Camera(Vector2 pos, int spanX, int spanY);

	Vector2 transformWorldToLocal(Vector2 worldCoordinates);

	void updatePos(Vector2 vecCenter);
};

