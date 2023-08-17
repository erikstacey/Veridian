#pragma once
#include "Components.h"

class Camera
	/* The Camera object is principally responsible for existing somewhere in the game world, either with its own position or following something else.
	It describes the position and span (through zoom) of a view into the game world, which can then be rendered to a position on the screen defined by a viewport.
	NOTE: IF YOU SET ATTACHEDTO/ATTACHED, mPosition IS TAKEN TO BE A POSITION RELATIVE TO THE POSITION OF ITS ATTACHED OBJECT*/
{
public:
	bool mAttached = false;
	PositionComponent* mAttachedTo = nullptr;
	PositionComponent mPosition = PositionComponent(0, 0, 0);
	float mZoom = 1;
};

