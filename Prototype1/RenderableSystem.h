#pragma once

#include "Components.h"
#include <vector>
#include <SDL.h>
#include "ResourceLoader.h"
#include "Vector2.h"
#include "Vector2i.h"
#include <memory>
#include "Camera.h"


// Viewport indicates an area on the screen which is connected to a camera 
struct Viewport {
	Camera* camera;
	SDL_Rect rect;
	Viewport(Camera* camera, int xPosition, int yPosition, int xSpan, int ySpan) : camera(camera) {
		rect.x = xPosition;
		rect.y = yPosition;
		rect.w = xSpan;
		rect.h = ySpan;
	}
};


class RenderableSystem
{
public:
	RenderableSystem() {}

	int setResources(ResourceLoader* resourceLoader, std::vector<RenderableComponent>* renderableComponents, SDL_Renderer* renderer);

	ResourceLoader* m_resourceLoader = nullptr;
	std::vector<PositionComponent>* m_positionComponents = nullptr;
	std::vector<RenderableComponent>* m_renderableComponents = nullptr;
	std::vector<Viewport> m_viewports;

	void transformPositionComponentToScreenCoordinate(PositionComponent* positionComponent, Viewport* viewport);


	Viewport* addViewport(Camera* camera, int xPosition, int yPosition, int xSpan, int ySpan);

	void renderAll();

private:
	// Keep two SDL_Rects in memory such that we don't need to reallocate memory for every render pass
	SDL_Rect m_srcRect;
	SDL_Rect m_dstRect;
	SDL_Renderer* m_renderer;

};

