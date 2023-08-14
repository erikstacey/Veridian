#pragma once

#include "Components.h"
#include "BasePrototype.h"
#include <vector>
#include <unordered_map>
#include "PrototypeManager.h"

class EntityManager
	/* The entity manager is responsible for managing a set of entities and storing all their components. Each entity is identified with an unsigned integer, and components are stored
	contiguously in vectors with unordered maps for quickly looking up the position of a component corresponding to a specific entity ID.
	Each component vector is named as m_[componentname]Components, and its lookup map has "Lookup" appended to the end.*/
{
public:
	EntityManager();

	PrototypeManager* m_prototypeManager;
	void setPrototypeManager(PrototypeManager* prototypeManager) { m_prototypeManager = prototypeManager; }

	unsigned int nextId = 0;
	unsigned int addEntity(std::string prototypeName);
	// components
	PositionComponent* addPositionComponent(unsigned int id, PositionComponent &component);
	std::vector<PositionComponent> m_positionComponents;
	std::unordered_map<int, PositionComponent*> m_positionComponentsLookup;

	RenderableComponent* addRenderableComponent(unsigned int id, RenderableComponent &component);
	std::vector<RenderableComponent> m_renderableComponents;
	std::unordered_map<int, RenderableComponent*> m_renderableComponentsLookup;

private:
	PositionComponent m_defaultPositionComponent;
};

