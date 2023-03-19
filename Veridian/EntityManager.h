#pragma once
#include <unordered_map>
#include <string>
#include "ComponentBase.h"
#include "ComponentVector2.h"
/*
The class which stores components and an entity registry and is responsible for creating new entities and registering them
with the appropriate components.
*/


class EntityManager
{
public:
	EntityManager();
	// Components
	std::unordered_map<std::string, ComponentBase*> components;

	// this stores the next available entity id
	int nextId=0;
	// Master list of entity Ids
	std::vector<int> allEntityIds;
	// Methods for creating and destroying entities
	int CreateEntity();
	void DestroyEntity(int id);


	void InitComponentVector2(std::string name);
	// Functions for making new entities
	void AddComponent(int id, std::string componentName);
	void RemoveComponent(int id, std::string componentName);
};

