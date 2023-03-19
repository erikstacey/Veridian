#include "ComponentVector2.h"

ComponentVector2::ComponentVector2() {
	component = new std::vector<Vector2>;
	registry = new std::unordered_map<int, int>;
}

ComponentVector2::~ComponentVector2() {
	delete component;
	delete registry;
}

void ComponentVector2::RegisterEntity(int id) {
	component->push_back(Vector2(0,0));
	(*registry)[id] = component->size() - 1;
}

void ComponentVector2::UnregisterEntity(int id) {
	component->erase((*component).begin() + (*registry)[id]);
	registry->erase(id);
}

Vector2* ComponentVector2::GetValue(int id) {
	return &(*component)[(*registry)[id]];
}