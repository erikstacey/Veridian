#include "ComponentPosition.h"

ComponentPosition::ComponentPosition() {
	data = new std::vector<Vector2>;
}
ComponentPosition::~ComponentPosition() {
	delete data;
}

void ComponentPosition::RegisterEntity(int id) {
	data->push_back(Vector2(0, 0));
	registry[id] = data->size() - 1;
}



void ComponentPosition::SetValue(int id, Vector2 v) {
	(*data)[registry[id]] = v;
}

Vector2* ComponentPosition::GetValue(int id) {
	return &(*data)[registry[id]];
}

void ComponentPosition::UnregisterEntity(int id) {
	// First verify the key exists in the registered entities
	if (registry.find(id) != registry.end()) {
		// delete the data, then the registry entry
		data->erase(data->begin() + registry[id]);
		registry.erase(id);
	}
}