#pragma once
#include "Vector2.h"
class Rectangle
{	public:
		Vector2 pos = Vector2(0, 0); // vector to bottom left corner
		Vector2 span = Vector2(1, 1); // vector from bottom left corner to top right corner
		Rectangle();
		Rectangle(float x, float y, float w, float h);
		Rectangle(Vector2 pos, Vector2 span);
};

