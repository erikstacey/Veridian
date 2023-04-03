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


int main(int argc, char* args[]) {
	DisplayManager displayManager(1920, 1080);


	// Test Code
	ComponentPosition testCPosition;
	testCPosition.RegisterEntity(1);
	testCPosition.SetValue(1, Vector2(0.1, 0.3));
	testCPosition.RegisterEntity(2);
	testCPosition.UnregisterEntity(2);
	ComponentSprite testCSprite;
	testCSprite.RegisterEntity(1);
	testCSprite.SetValue(1, 1, 1, 0);

	Vector2* testCameraPosition = new Vector2(0, 0);
	Camera * testCamera = new Camera(testCameraPosition, 1920, 1080);
	SystemDisplay* testSystemDisplay = new SystemDisplay(&testCPosition, &testCSprite, testCamera, &displayManager);


	
	// set up a test world and entity
	World* world = new World(&displayManager);

	int testEntity = world->entityManager->CreateEntity();
	world->entityManager->AddComponent(testEntity, "position");
	world->entityManager->AddComponent(testEntity, "sprite");
	world->mainDisplaySystem->SetActiveCamera(testCamera);

	// End Test Code

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

		printf("Frame Time: %f (%f fps)\n", lastFrameTimeMsFloat, 1/(lastFrameTimeMsFloat/1000));
		
		// draw to the screen
		displayManager.frameSetup();
		world->Update(lastFrameTimeMsFloat);
		displayManager.framePush();

	}
	return 0;
}