#include "World.h"

std::vector<GameObject>& World::getAllGameObjects() {
	return m_gameobjects;
}

void World::addGameObject(const GameObject& obj) {
	m_gameobjects.push_back(obj);
}