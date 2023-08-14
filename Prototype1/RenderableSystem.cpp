#include "RenderableSystem.h"
#include <SDL.h>




int RenderableSystem::setResources(ResourceLoader* resourceLoader, std::vector<RenderableComponent>* renderableComponents, SDL_Renderer* renderer) {
	// Sets pointers to the resource loader (for textures), renderable components, and the renderer. Returns 0 if successful, 1 if any of the 
	// pointers are null.
	m_resourceLoader = resourceLoader;
	if (m_resourceLoader == nullptr) {
		return 1;
	}
	m_renderableComponents = renderableComponents;
	if (m_renderableComponents == nullptr) {
		return 1;
	}
	m_renderer = renderer;
	if (m_renderer == nullptr) {
		return 1;
	}

	return 0;
}


void RenderableSystem::transformPositionComponentToScreenCoordinate(PositionComponent* positionComponent, Viewport* viewport) {
	// Using a viewport (which points to a camera, and together completely define the transformation from world to screen), translates
	// the position component to a screen position for rendering
	m_transformVector.x = positionComponent->x;
	m_transformVector.y = positionComponent->y;

	// adjust to camera-relative coordinates
	if (viewport->camera->mAttached) {
		m_transformVector.x -= viewport->camera->mAttachedTo->x;
		m_transformVector.y -= viewport->camera->mAttachedTo->y;
	}
	m_transformVector.x -= viewport->camera->mPosition.x;
	m_transformVector.y -= viewport->camera->mPosition.y;

	// coordinates are now relative to the camera position
	// convert to zoom adjusted coordinates

	m_transformVector.x /= viewport->camera->mZoom;
	m_transformVector.y /= viewport->camera->mZoom;

	// now a change of 1 in any coordinate should correspond to a change of 1 pixel in screen space,
	// and the coordinates are relative to the center of the viewport

	m_transformVector.x -= (viewport->screenPosition.x + viewport->span.x / 2);
	m_transformVector.y -= (viewport->screenPosition.y + viewport->span.y / 2);

	// Done, we now have coordinates relative to the top left corner of the screen.

}

Viewport* RenderableSystem::addViewport(Camera* camera, int xPosition, int yPosition, int xSpan, int ySpan) {
	// Adds a new viewport object to the rendering system's array, returns a reference to it
	m_viewports.emplace_back(camera, xPosition, yPosition, xSpan, ySpan);
	return &m_viewports[m_viewports.size() - 1];
}


void RenderableSystem::renderAll() {
	// This is called once per frame, and will iterate through renderable components to render them on the screen
	// To be added: off screen culling, possibly occlusion culling
	// Iterates over all viewports, which means viewports should be added sparingly if they would be rendering a large number of objects (particularly duplicates)
	PositionComponent* cPositionComponent = nullptr;
	RenderableComponent* cRenderableComponent = nullptr;
	SDL_Texture* cTexture = nullptr;
	TextureMetaData* cTextureMetaData = nullptr;
	Viewport* cViewport = nullptr;

	SDL_Rect* srcRect = new SDL_Rect();
	SDL_Rect* dstRect = new SDL_Rect();


	for (int i = 0; i < m_renderableComponents->size(); i++) {
		// get data
		cRenderableComponent = &(*m_renderableComponents)[i];
		cPositionComponent = cRenderableComponent->worldPosition;
		cTexture = m_resourceLoader->m_textures[cRenderableComponent->textureID];
		cTextureMetaData = &(m_resourceLoader->m_texturesMetaData[cRenderableComponent->textureID]);
		// transform and render it
		for (int k = 0; k < m_viewports.size(); k++) {
			cViewport =  &m_viewports[k];
			transformPositionComponentToScreenCoordinate(cPositionComponent, cViewport);
			dstRect->x = m_transformVector.x;
			dstRect->y = m_transformVector.y;
			dstRect->w = cTextureMetaData->textureSizeX * cViewport->camera->mZoom;
			dstRect->h = cTextureMetaData->textureSizeY * cViewport->camera->mZoom;

			srcRect->x = 0;
			srcRect->y = 0;
			srcRect->w = cTextureMetaData->textureSizeX;
			srcRect->h = cTextureMetaData->textureSizeY;

			SDL_RenderCopy(m_renderer, cTexture, srcRect, dstRect);
		}
	}
	delete srcRect;
	delete dstRect;
}