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
	Vector2i screenPosition = Vector2i(0, 0);
	Vector2i span = Vector2i(0, 0);
	Viewport(Camera* camera) : camera(camera) {}
	Viewport(Camera* camera, int xPosition, int yPosition, int xSpan, int ySpan) : camera(camera) {
		screenPosition.x = xPosition;
		screenPosition.y = yPosition;
		span.x = xSpan;
		span.y = ySpan;
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
	// Keep a vector in memory such that we don't need to reallocate memory for every transformation
	Vector2 m_transformVector;
	SDL_Renderer* m_renderer;

};

