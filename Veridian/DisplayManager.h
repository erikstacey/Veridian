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
	DisplayManager();
	~DisplayManager();
	bool Initialize();
	bool Initialize(int x, int y);
	bool BootSDL();
	bool RenderWindowSetup();
	bool Reboot();

	void FrameSetup();
	void FramePush();

	int displayWidth, displayHeight;

	SDL_Texture* textures[65535]; // max size of unsigned short int.
	// Keeping the textures limited means we can use 2-byte integers in
	// world tilemaps, saving ram
	void DrawTex(Vector2 screenCoordinates, int textureId, float scale);

private:
	SDL_Renderer* renderer = NULL;
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;

	bool LoadAllTextures(std::string registry);
	bool LoadTex(std::string fname, int index);
	
};

