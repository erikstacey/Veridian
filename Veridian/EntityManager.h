#pragma once
#include <unordered_map>
#include <string>
#include "ComponentBase.h"
/*
The class which stores components and an entity registry and is responsible for creating new entities and registering them
with the appropriate components.
*/


class EntityManager
{
public:
	EntityManager();
	// ADD A DESTRUCTOR THAT DESTROYS THE COMPONENTS
	// OR YOU'LL BE LEAKIN MEMORY LIKE A SIEVE
	// Components
	std::unordered_map<std::string, ComponentBase*> components;

	// this stores the next available entity id
	int nextId=0;
	// Master list of entity Ids
	std::vector<int> allEntityIds;
	// Methods for creating and destroying entities
	int CreateEntity();
	void DestroyEntity(int id);


	// Functions for making new entities
	void AddComponent(int id, std::string componentName);
	void RemoveComponent(int id, std::string componentName);
};

