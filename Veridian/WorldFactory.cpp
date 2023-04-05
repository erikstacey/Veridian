#include "WorldFactory.h"
#include <iostream>

WorldFactory::WorldFactory() {
	// Doesn't need much construction
}

bool WorldFactory::WorldExists(std::string name) {
	// Returns a boolean value indicating if a world with the specified name already exists
	return (worlds.find(name) != worlds.end());
}

void WorldFactory::CreateWorld(std::string name) {
	if (WorldExists(name)) {
		std::cout << "[WARNING] Tried to create world " << name << " but a world with that name already exists" << std::endl;
	}
	else {
		worlds[name] = new World(displayManager);
	}
}

void WorldFactory::DeleteWorld(std::string name) {
	if (WorldExists(name)) {
		delete worlds[name];
		worlds.erase(name);
	}
	else {
		std::cout << "[WARNING] Tried to delete world " << name << " but a world with that name was not found" << std::endl;
	}
}

World* WorldFactory::GetWorld(std::string name) {
	return worlds[name];
}