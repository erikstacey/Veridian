#pragma once
class Vector2
{
public:
	float x{ 0 };
	float y{ 0 };
	
	Vector2();
	Vector2(float x, float y);
	void Add(Vector2 v);
	void Subtract(Vector2 v);
	void Dot(Vector2 v);
	void Dot(float f);
	void Norm();

	float Mag();
};

