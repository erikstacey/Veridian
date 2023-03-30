#pragma once
#include "ComponentBase.h"
#include <vector>
#include <unordered_map>

struct SpritePacket {
	unsigned short textureId;
	float scale;
	float rotation; // 0 to 2pi
};

class ComponentSprite : public ComponentBase
{
public:
	std::vector<SpritePacket>* data;

	ComponentSprite();
	~ComponentSprite();

	void RegisterEntity(int id) override;
	void SetValue(int id, unsigned short textureId, float scale, float rotation);
	SpritePacket* GetValue(int id);
	void UnregisterEntity(int id) override;
};

