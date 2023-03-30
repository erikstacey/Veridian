#include "ComponentPosition.h"

ComponentPosition::ComponentPosition() {}

void ComponentPosition::RegisterEntity(int id) {
	data.push_back(Vector2(0, 0));
	registry[id] = data.size() - 1;
}

void ComponentPosition::UnregisterEntity(int id) {
	data.erase(data.begin() + registry[id]);
	registry.erase(id);
}

void ComponentPosition::SetValue(int id, Vector2 v) {
	data[registry[id]] = v;
}

Vector2* ComponentPosition::GetValue(int id) {
	return &data[registry[id]];
}