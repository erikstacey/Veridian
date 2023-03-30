#pragma once
#include "ComponentBase.h"
#include <vector>
#include "Vector2.h"
class ComponentPosition : public ComponentBase
{
public:
	std::vector<Vector2>* data;

	ComponentPosition();
	~ComponentPosition();

	void RegisterEntity(int id) override;
	void SetValue(int id, Vector2 v);
	Vector2* GetValue(int id);
	void UnregisterEntity(int id) override;
};

