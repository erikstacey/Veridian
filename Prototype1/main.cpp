#include <iostream>
#include "DisplayManager.h"
#include <SDL.h>
#include "ResourceLoader.h"
#include "RenderableSystem.h"
#include "EntityManager.h"
#include "Vector2.h"
#include "Camera.h"

DisplayManager gDisplayManager;

int main(int argc, char *argv[]) {
	// perform display manager setup
	if (!gDisplayManager.initializeSDL()) {
		return 1;
	}
	if (!gDisplayManager.createWindow()) {
		return 1;
	}
	if (!gDisplayManager.createRenderer()) {
		return 1;
	}

	ResourceLoader* resourceLoader = new ResourceLoader();
	if (!resourceLoader->setRenderer(gDisplayManager.m_renderer)) {
		return 1;
	}
	resourceLoader->addTextureRegistry("./res/art/registry.csv");
	resourceLoader->loadTextures();


	RenderableSystem renderableSystem;
	EntityManager entityManager;
	PrototypeManager prototypeManager;

	// Do some setup
	if (renderableSystem.setResources(resourceLoader, &entityManager.m_renderableComponents, gDisplayManager.m_renderer)) {
		return 1;
	}
	entityManager.setPrototypeManager(&prototypeManager);
	entityManager.addEntity("TestPrototype");

	Camera* mainCamera = new Camera();
	renderableSystem.addViewport(mainCamera, 0, 0, gDisplayManager.m_windowWidth, gDisplayManager.m_windowHeight);
	

	// main loop. Each system should have its main method called here, which handles all of its per-frame behaviour.
	bool quit = false;
	SDL_Event e;

	while (!quit) {
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		SDL_RenderClear(gDisplayManager.m_renderer);
		renderableSystem.renderAll();
		SDL_RenderPresent(gDisplayManager.m_renderer);
	}
	return 0;
}