#pragma once
#include <SDL.h>

class DisplayManager
	/* The display manager is responsible for managing the game window, including setting up the SDL2 renderer and providing it to the rendering system.*/
{
public:
	DisplayManager();
	~DisplayManager();
	int m_windowWidth = 1280;
	int m_windowHeight = 720;
	int m_windowActive = 0;

	SDL_Window* m_window = NULL;
	SDL_Renderer* m_renderer = NULL;
	SDL_Surface* m_surface = NULL;


	// For the display manager
	int setWindowSize(int w, int h);

	// to liase with SDL
	int initializeSDL();
	int createWindow();
	int createRenderer();
private:

};
