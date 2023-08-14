#include "PrototypeManager.h"

PrototypeManager::PrototypeManager() {
	
	m_prototypes["TestPrototype"].position = true;
	m_prototypes["TestPrototype"].renderable = true;
	m_prototypes["TestPrototype"].renderableComponent.textureID=0;
	
}

BasePrototype* PrototypeManager::lookupPrototype(std::string name) {
	return &m_prototypes[name];
}