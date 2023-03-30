#include "World.h"
#include <math.h>

World::World() {
	entityManager = new EntityManager();
}

World::World(DisplayManager* displayManager) : displayManager(displayManager) {
	entityManager = new EntityManager();
}

World::~World() {
	delete entityManager;
}

