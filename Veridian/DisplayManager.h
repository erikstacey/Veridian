#pragma once
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "World.h"
#include "Camera.h"

class DisplayManager
{
public:
	DisplayManager(int x, int y);
	~DisplayManager();
	bool bootSDL();
	bool renderWindowSetup(int w, int h);

	int windowW;
	int windowH;

	void frameSetup();
	void framePush();

	SDL_Texture* textures[65535]; // max size of unsigned short int.
	// Keeping the textures limited means we can use 2-byte integers in
	// world tilemaps, saving ram

	void drawWorld(World* worldPtr);

	Camera* activeCamera;

private:
	SDL_Renderer* renderer = NULL;
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	int displayWidth, displayHeight;

	bool loadAllTextures(std::string registry);
	bool loadTex(std::string fname, int index);
	void drawTex(Vector2 screenCoordinates, int i, float zoom);
};

