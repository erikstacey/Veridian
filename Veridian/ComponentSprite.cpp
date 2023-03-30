#include "ComponentSprite.h"

ComponentSprite::ComponentSprite() {
	data = new std::vector<SpritePacket>;
};

ComponentSprite::~ComponentSprite() {
	delete data;
}

void ComponentSprite::RegisterEntity(int id) {
	data->push_back({ 1, 1, 0 });
	registry[id] = data->size() - 1;
}

void ComponentSprite::SetValue(int id, unsigned short textureId, float scale, float rotation) {
	(*data)[registry[id]] = { textureId, scale, rotation };
}

SpritePacket* ComponentSprite::GetValue(int id) {
	return &(*data)[registry[id]];
}

void ComponentSprite::UnregisterEntity(int id) {
	// First verify the key exists in the registered entities
	if (registry.find(id) != registry.end()) {
		// delete the data, then the registry entry
		data->erase(data->begin() + registry[id]);
		registry.erase(id);
	}
}