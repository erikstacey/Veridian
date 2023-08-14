#pragma once
#include<cstdint>
#include "Vector2.h"
#include <tuple>

/* Component structures are described here. These simply are common data structures which are used to describe an entity, its properties, and interactions.*/



struct PositionComponent {
	float x = 0;
	float y = 0;
	float r = 0; // rotational component. Use modulus division by 360 when using (r%360).
	PositionComponent() {};
	PositionComponent(float x, float y, float r) : x(x), y(y), r(r) {}
};

struct RenderableComponent {
	// Texture ID is the index of the texture in the ResourceLoader's mTextures array.
	int textureID = 0;
	// Renderer RGB controls
	uint8_t r = 255;
	uint8_t g = 255;
	uint8_t b = 255;
	uint8_t alpha = 255;
	// rendering layer
	unsigned short int layer;
	PositionComponent* worldPosition;

	RenderableComponent() {}
	RenderableComponent(int textureID, uint8_t r, uint8_t g, uint8_t b, uint8_t alpha, unsigned short int layer) :
		textureID(textureID), r(r), g(g), b(b), alpha(alpha), layer(layer) {}
};