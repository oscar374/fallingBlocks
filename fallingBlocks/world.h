#pragma once

#include "gameObject.h"
#include <vector>

class World {
public:
	void addGameObject(const GameObject& obj);

	std::vector<GameObject>& getAllGameObjects();
private:
	std::vector<GameObject> m_gameobjects;
};