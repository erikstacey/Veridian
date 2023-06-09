#include "World.h"

World::World() {
	entityManager = new EntityManager();
	mainDisplaySystem = new SystemDisplay(
		dynamic_cast<ComponentPosition*>(entityManager->components["position"]),
		dynamic_cast<ComponentSprite*>(entityManager->components["sprite"]), 
		NULL);
}

World::~World() {

}

void World::Update(float deltaT) {
	mainDisplaySystem->Update(deltaT);
}
