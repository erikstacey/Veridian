#pragma once
#include <unordered_map>
#include <string>
#include "BasePrototype.h"

class PrototypeManager
	/* The prototype manager is principally responsible for holding BasePrototype objects, which define prototypical game objects in terms of their components and default data (e.g. a wall tile).
	The entity manager, when requested to create a new game object, references the prototypes here.*/
{
public:
	PrototypeManager();

	std::unordered_map<std::string, BasePrototype> m_prototypes;

	BasePrototype* lookupPrototype(std::string);
};

