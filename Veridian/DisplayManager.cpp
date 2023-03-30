#include "DisplayManager.h"
#include <stdio.h>
#include <SDL_image.h>




DisplayManager::DisplayManager(int w, int h) {
	// Constructor for displaymanager initializes SDL, then creates a window and renderer, and finally loads all textures
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
	// Starts up SDL and SDL image
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
	// Creates a window and renderer
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
	// Loads a single texture using SDL_Image IMG_Load, then stores it in the textures array at position index
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
	// A method to load all textures. Currently temporary.
	loadTex("res/textures/grass1.png", 0);
	loadTex("res/textures/water1.png", 1);
	loadTex("res/textures/stone1.png", 2);
	loadTex("res/textures/player1.png", 3);
	return true;
}

void DisplayManager::drawTex(Vector2 screenCoordinates, int textureId, float scale) {
	// Draws a texture indicated by textureId at screenCoordinates scaled by scale. Note that screencoordinates are the
	// pixel coordinates of the window. E.g. for a 1920x1080 screen, Vector2.x must be greater than zero and less than 1920.
	SDL_Rect drawRect = { screenCoordinates.x, screenCoordinates.y, 16*scale, 16*scale};
	SDL_RenderCopy(renderer, textures[textureId], NULL, &drawRect);
}

void DisplayManager::frameSetup() {
	SDL_RenderClear(renderer);

}
void DisplayManager::framePush(){
	SDL_RenderPresent(renderer);
}

