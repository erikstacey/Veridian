#pragma once
class Vector2
	/* This is a basic 2-D vector class with floating point values. Its methods act in-place on the calling vector.*/
{
public:
	float x = 0;
	float y = 0;

	void add(Vector2* v2);
	void subtract(Vector2* v2);
	void dot(Vector2* v2);
	void dot(float f);
};

