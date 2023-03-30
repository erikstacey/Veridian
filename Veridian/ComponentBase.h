#pragma once
#include <unordered_map>
#include <vector>
#include <string>
class ComponentBase
{
public:
	// Should have attributes registry, component
	// registry stores a map of entity Id to vector index
	std::unordered_map<int, int> registry;
	// component stores a pointer to the vector of actual component data. This doesn't have to be
	// floats, float is just used as a datatype placeholder for the abstract class
	std::vector<float> *data;

	// Function that adds this component to an entity with id specified.
	virtual void RegisterEntity(int id) = 0;
	// Function that removes this component from an entity with the id specified.
	virtual void UnregisterEntity(int id) = 0;

};

