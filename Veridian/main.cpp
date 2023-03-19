#include <stdio.h>
#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "DisplayManager.h"
#include "Rectangle.h"
#include "Camera.h"
#include "World.h"
#include <math.h>
#include "EntityManager.h"


DisplayManager gDisplayManager(1920, 1080);


int main(int argc, char* args[]) {
	SDL_Event e;
	bool quit = false;

	Rectangle test_rect;

	// make a camera

	Camera* camera = new Camera(Vector2(0, 0), 1920, 1080);
	camera->zoom = 0.5;
	gDisplayManager.activeCamera = camera;
	World* world = new World();

	EntityManager* entityManager = new EntityManager;

	int entityId1 = entityManager->CreateEntity();
	entityManager->AddComponent(entityId1, "position");
	entityManager->AddComponent(entityId1, "velocity");


	// start main loop
	while (!quit) {
		// handle SDL event stack
		while (SDL_PollEvent(&e) != 0) {
			// handle exit event
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			else if(e.type == SDL_KEYDOWN) {

			}
		}
		
		// draw to the screen
		gDisplayManager.frameSetup();
		gDisplayManager.drawWorld(world);
		gDisplayManager.framePush();

	}
	return 0;
}