#pragma once
class Vector2i
	/* This is a basic 2-D vector class with integer values. Its methods act in-place on the calling vector.*/
{
public:
	int x;
	int y;

	void add(Vector2i* v2);
	void subtract(Vector2i* v2);
	void dot(Vector2i* v2);
	void dot(int i);

	Vector2i(int x, int y) : x(x), y(y) {};
};

