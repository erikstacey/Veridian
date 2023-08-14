#include "DisplayManager.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

DisplayManager::DisplayManager() {

}
DisplayManager::~DisplayManager() {
	SDL_DestroyRenderer(m_renderer);
	m_renderer = nullptr;
	SDL_DestroyWindow(m_window);
	m_window = nullptr;
	IMG_Quit(); SDL_Quit();
}

int DisplayManager::setWindowSize(int w, int h) {
	if (!m_windowActive) {
		m_windowWidth = w;
		m_windowHeight = h;
		return 1;
	}
	else {
		std::cout << "Tried to set window size with window active!\n";
		return 0;
	}
}

int DisplayManager::initializeSDL() {
	printf("INIT SDL: ");
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Failed!\n: ");
		printf("\t %s\n", SDL_GetError());
		return 0;
	}
	printf("Success!\n");
	printf("INIT SDL_image: ");
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		printf("Failed!\n");
		printf("\t SDL Error: %s\n", IMG_GetError());
		return 0;
	}
	else {
		printf("Success!\n");
	}
	return 1;

}

int DisplayManager::createWindow() {
	printf("CREATE WINDOW: ");
	m_window = SDL_CreateWindow("Prototype1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_windowWidth, m_windowHeight, SDL_WINDOW_SHOWN);
	m_surface = SDL_GetWindowSurface(m_window);
	if (m_window == NULL) {
		printf("Failed, window reference null!\n");
		printf("\t SDL Error: %s\n", SDL_GetError());
		return 0;
	}
	if (m_surface == NULL) {
		printf("Failed, surface reference null!\n");
		printf("\t SDL Error: %s\n", SDL_GetError());
		return 0;
	}
	m_windowActive = 1;
	printf("Success!\n");
	return 1;
}

int DisplayManager::createRenderer() {
	printf("CREATE RENDERER: ");
	if (m_window == NULL || !m_windowActive) {
		printf("Failed! Create window first.\n");
		return 0;
	}
	
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (m_renderer == NULL) {
		printf("Failed!\n");
		printf("\t SDL Error: %s\n", SDL_GetError());
		return 0;
	}

	printf("Success!\n");
	SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	return 1;
}

