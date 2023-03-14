#include "DisplayManager.h"
#include <stdio.h>
#include <SDL_image.h>




DisplayManager::DisplayManager(int w, int h) {
	printf("[INIT] Display manager starting with w=%d, h=%d\n", w, h);
	displayWidth = w;
	displayHeight = h;
	// startup fare. Loads SDL/SDL_image, then tries to create a window
	if (!bootSDL()) {
		printf("[INIT] DisplayManager: Failed\n");
		printf("\t SDL boot failed.\n");
	}
	else if (!renderWindowSetup(w, h)) {
		printf("[INIT] DisplayManager: Failed\n");
		printf("\t Renderer and window setup failed.\n");
	}
	else {
		printf("[INIT] DisplayManager: Success\n");
	}
	// load textures
	if (!loadAllTextures("asdf")) {
		printf("[TEX] All Textures: Failed\n");
	}
	else {
		printf("[TEX] All Textures: Success\n");
	}
}

DisplayManager::~DisplayManager() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;
	SDL_Quit();
	IMG_Quit();

}

bool DisplayManager::bootSDL() {
	bool s = true;
	printf("[INIT] SDL: ");
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		s = false;
		printf("Failed\n: ");
		printf("\t %s\n", SDL_GetError());
	}
	printf("Success!\n");
	printf("[INIT] SDL_image: ");
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		s = false;
		printf("Failed\n");
		printf("\t SDL Error: %s\n", IMG_GetError());
	}
	else {
		printf("Success\n");
	}
	return s;
}

bool DisplayManager::renderWindowSetup(int w, int h) {
	bool s = true;
	// set up window and renderer
	window = SDL_CreateWindow("GameEnginePrototype", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
	printf("[INIT] SDL Window: ");
	if (window == NULL) {
		printf("Failed\n");
		printf("\t SDL Error: %s\n", SDL_GetError());
		s = false;
	}
	else {
		printf("Success\n");
		printf("[INIT] SDL Renderer: ");
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == NULL) {
			s = false;
			printf("Failed\n");
			printf("\t SDL Error: %s\n", SDL_GetError());
		}
		else {
			printf("Success\n");
			// set initial renderer colour
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			screenSurface = SDL_GetWindowSurface(window);
		}
	}
	windowW = w;
	windowH = h;
	return s;
}

bool DisplayManager::loadTex(std::string fname, int index) {
	bool s = true;
	SDL_Surface* loadedSurface = IMG_Load(fname.c_str());
	if (loadedSurface == NULL) {
		printf("[TEX] Image could not be loaded. Filename: %s, Error: %s\n", fname.c_str(), IMG_GetError());
		s = false;
	}
	else {
		// colour key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0xFF, 0xFF));
		textures[index] = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (textures[index] == NULL) {
			printf("[TEX] %s: Failed\n\tError:%s\n", fname.c_str(), IMG_GetError());
			s = false;
		}
		else {
			printf("[TEX] %s: Success", fname.c_str());
			SDL_FreeSurface(loadedSurface);
		}
	}
	return s;
}

bool DisplayManager::loadAllTextures(std::string registry) {
	loadTex("res/textures/grass1.png", 0);
	loadTex("res/textures/water1.png", 1);
	loadTex("res/textures/stone1.png", 2);
	loadTex("res/textures/player1.png", 3);
	return true;
}

void DisplayManager::drawTex(Vector2 screenCoordinates, int textureId, float scale) {
	SDL_Rect drawRect = { screenCoordinates.x, screenCoordinates.y, 16*scale, 16*scale};
	SDL_RenderCopy(renderer, textures[textureId], NULL, &drawRect);
}

void DisplayManager::frameSetup() {
	SDL_RenderClear(renderer);

}
void DisplayManager::framePush(){
	SDL_RenderPresent(renderer);
}

void DisplayManager::drawWorld(World* worldPtr) {
	for (int i = 0; i < worldPtr->sizeX; i++) {
		for (int k = 0; k < worldPtr->sizeY; k++) {
			drawTex(activeCamera->transformWorldToLocal(Vector2(i, k)), worldPtr->tilemap[i][k], activeCamera->zoom);
		}
	}
}

