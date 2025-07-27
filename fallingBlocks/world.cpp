#include "World.h"

std::vector<std::shared_ptr<GameObject>> World::getAllGameObjects() const{
	return m_gameobjects;
}

void World::addGameObject(std::shared_ptr<GameObject> obj) {
	m_gameobjects.push_back(obj);
}