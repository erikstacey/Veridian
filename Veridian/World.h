#pragma once
#include "EntityManager.h"
#include "SystemDisplay.h"

/*
A world is a self-contained gameworld, with a coordinate system, a tilemap, an entity system, and a set of behavioural systems.
They are unreliant on anything outside themself except for the SDL interfaces, which make them suitable for things like separate
dimensions, planets, levels, etc.
*/

class DisplayManager;

class World {
public:
	World(DisplayManager* displayManager);
	~World();
	// entity manager stores components and entities
	EntityManager* entityManager;
	// systems handle behaviour at the world level
	SystemDisplay* mainDisplaySystem;

	void Update(float deltaT);
};

