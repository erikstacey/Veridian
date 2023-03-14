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


	// start main loop
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}
		// test moving the camera around
		// draw to the screen
		gDisplayManager.frameSetup();
		gDisplayManager.drawWorld(world);
		gDisplayManager.framePush();

	}
	return 0;
}