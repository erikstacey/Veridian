#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include "Vector2.h"
#include "ComponentBase.h"

class ComponentVector2 : public ComponentBase
{
public:
	ComponentVector2();
	~ComponentVector2();
	// component stores a pointer to the Vector2 data
	std::vector<Vector2> *component;
	// registry is a pointer to a map of entity id to index in component
	std::unordered_map<int, int> *registry;
	void RegisterEntity(int id) override;
	void UnregisterEntity(int id) override;

	Vector2* GetValue(int id);

};

