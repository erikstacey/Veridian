#pragma once
#include <string>
#include <cstdint>
#include "Components.h"

class BasePrototype
	/* This class is used to provide a description of a type of game object, in terms of its components and basic data. The prototype is fully specified, as
	in each component is either explicitely described as present or not present, and those which are present should be fully described (all the associated
	variables should be set). */
{
public:
	// Position Component
	bool position = false;

	// Renderable Component
	bool renderable = false;
	std::string textureName;
	int textureID;
	RenderableComponent renderableComponent;
	
};

