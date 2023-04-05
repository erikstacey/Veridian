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
#include "ComponentSprite.h"
#include "Vector2.h"
#include "SystemDisplay.h"
#include <chrono>
#include <thread>
#include "WorldFactory.h"

WorldFactory gWorldFactory;
DisplayManager gDisplayManager;


int main(int argc, char* args[]) {
	// start up the display
	gDisplayManager.Initialize(1920, 1080);

	// pre-engine loop code
	SDL_Event e;
	bool quit = false;
	// set up time tracking
	std::chrono::steady_clock::time_point lastFrameTimestamp = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point curFrameTimestamp = std::chrono::steady_clock::now();
	std::chrono::microseconds lastFrameTime;
	float lastFrameTimeMsFloat;


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
		// get time since last frame
		lastFrameTimestamp = curFrameTimestamp;
		curFrameTimestamp = std::chrono::steady_clock::now();
		lastFrameTime = std::chrono::duration_cast<std::chrono::microseconds> (curFrameTimestamp - lastFrameTimestamp);
		lastFrameTimeMsFloat = static_cast<float>(lastFrameTime.count()) / 1000;

		// process game logic

		
		// draw to the screen
		gDisplayManager.FrameSetup();
		gDisplayManager.FramePush();


	}
	return 0;
}