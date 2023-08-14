#include "EntityManager.h"


EntityManager::EntityManager() {}

unsigned int EntityManager::addEntity(std::string prototypeName) {
	BasePrototype* prototype = m_prototypeManager->lookupPrototype(prototypeName);

	unsigned int id = nextId;
	nextId++;
	// add position component
	if (prototype->position) {
		addPositionComponent(id, m_defaultPositionComponent);
	}
	// renderable component
	if (prototype->renderable) {
		addRenderableComponent(id, prototype->renderableComponent);
	}

	return id;
}

PositionComponent* EntityManager::addPositionComponent(unsigned int id, PositionComponent &component) {
	m_positionComponents.push_back(component);
	m_positionComponentsLookup[id] = &m_positionComponents[m_positionComponents.size() - 1];
	return m_positionComponentsLookup[id];
}

RenderableComponent* EntityManager::addRenderableComponent(unsigned int id, RenderableComponent &component) {
	m_renderableComponents.push_back(component);
	m_renderableComponentsLookup[id] = &m_renderableComponents[m_renderableComponents.size() - 1];
	m_renderableComponentsLookup[id]->worldPosition = m_positionComponentsLookup[id];
	return m_renderableComponentsLookup[id];
}