#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include "ComponentBase.h"
/* Defines the basic structure of a system. the update method is called on each game tick with deltaT
being the time difference from the last frame. requiredComponents defines the component types required with
strings, and components is intended to hold maps of the component names to the components.*/

class SystemBase
{
public:
	virtual void Update(float deltaT) = 0;
};

