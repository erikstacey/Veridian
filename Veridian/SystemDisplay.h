#pragma once
#include "SystemBase.h"
#include "ComponentPosition.h"
#include "ComponentSprite.h"
#include "Camera.h"

class DisplayManager;

class SystemDisplay : public SystemBase
{
public:
	// Component pointers
	ComponentPosition* position;
	ComponentSprite* sprite;
	Camera* camera;

	SystemDisplay(ComponentPosition* position, ComponentSprite* sprite, Camera* camera);
	~SystemDisplay();

	void Update(float deltaT) override;
	void SetActiveCamera(Camera* camera);
};

