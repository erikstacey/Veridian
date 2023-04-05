#pragma once
#include "World.h"
#include <unordered_map>
#include <string>

class WorldFactory
{
public:
	// map of worldnames to pointers to world objects
	std::unordered_map<std::string, World*> worlds;
	DisplayManager* displayManager;

	WorldFactory();
	// creates a new world with the specified name
	void CreateWorld(std::string name);
	// deletes a world with the specified name, if it exists
	void DeleteWorld(std::string name);
	// checks if a world exists
	bool WorldExists(std::string name);
	// returns a pointer to the world with the specified name, if it exists. If not, returns nullptr
	World* GetWorld(std::string name);

};

