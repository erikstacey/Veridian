#include "SystemDisplay.h"
#include <stdexcept>
#include "DisplayManager.h"

SystemDisplay::SystemDisplay(ComponentPosition* position, ComponentSprite* sprite, Camera* camera, DisplayManager* displayManager) :
	position(position), sprite(sprite), camera(camera), displayManager(displayManager) {
	if (position == NULL) {
		throw std::invalid_argument("Display System initialized with null position component pointer!");
	}
	if (sprite == NULL) {
		throw std::invalid_argument("Display System initialized with null sprite component pointer!");
	}
}
SystemDisplay::~SystemDisplay() {
	position = NULL;
	sprite = NULL;
	camera = NULL;
	displayManager = NULL;
}

void SystemDisplay::Update(float deltaT) {
	// Skip all of this if this doesn't have an active camera
	if (camera != NULL) {
		int cId;
		SpritePacket* cSpritePacket;
		Vector2 cDrawCoordinates;
		// iterate over all key-value pairs in the spritecomponent registry
		// this gives us entity Ids, which we can use to retrieve the positions and spritepackets
		for (auto it = sprite->registry.begin(); it != sprite->registry.end(); ++it) {
			cId = it->first;
			cSpritePacket = sprite->GetValue(cId);
			cDrawCoordinates = camera->TransformWorldToLocal(*(position->GetValue(cId)));
			displayManager->DrawTex(cDrawCoordinates, cSpritePacket->textureId, cSpritePacket->scale);
		}
	}
}

void SystemDisplay::SetActiveCamera(Camera* newCamera) {
	camera = newCamera;
}