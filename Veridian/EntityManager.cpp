#include "EntityManager.h"

EntityManager::EntityManager() {
	InitComponentVector2("position");
	InitComponentVector2("velocity");
}

void EntityManager::InitComponentVector2(std::string name) {
	components[name] = new ComponentVector2();
}

void EntityManager::AddComponent(int id, std::string componentName) {
	components[componentName]->RegisterEntity(id);
}

void EntityManager::RemoveComponent(int id, std::string componentName) {
	components[componentName]->UnregisterEntity(id);
}

int EntityManager::CreateEntity() {
	allEntityIds.push_back(nextId);
	nextId++;
	return nextId - 1;
}

void EntityManager::DestroyEntity(int id) {
	// iterate over all components and call their unregister methods
	for (const auto& pair: components) {
		pair.second->UnregisterEntity(id);
	}
}