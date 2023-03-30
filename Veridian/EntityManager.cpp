#include "EntityManager.h"
#include "ComponentPosition.h"
#include "ComponentSprite.h"

EntityManager::EntityManager() {
	components["position"] = new ComponentPosition();
	components["sprite"] = new ComponentSprite();
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