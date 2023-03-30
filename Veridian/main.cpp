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
#include "ComponentPosition.h"
#include "Vector2.h"


int main(int argc, char* args[]) {
	DisplayManager displayManager(1920, 1080);

	ComponentPosition testComponentPosition;
	testComponentPosition.RegisterEntity(1);
	testComponentPosition.SetValue(1, Vector2(0, 3.2));
	Vector2* testVector = testComponentPosition.GetValue(1);
	printf("%f, %f", testVector->x, testVector->y);

	testComponentPosition.UnregisterEntity(1);

	SDL_Event e;
	bool quit = false;
	World* world = new World();
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
		displayManager.frameSetup();
		displayManager.framePush();

	}
	return 0;
}