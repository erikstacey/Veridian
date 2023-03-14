#include "Rectangle.h"

Rectangle::Rectangle() {
}
Rectangle::Rectangle(float x, float y, float w, float h) {
	pos = Vector2(x, y);
	span = Vector2(w, h);
}

Rectangle::Rectangle(Vector2 pos, Vector2 span) : pos(pos), span(span) {}