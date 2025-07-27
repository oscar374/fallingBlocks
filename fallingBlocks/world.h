#pragma once

#include "gameObject.h"
#include <memory>
#include <vector>

class World {
public:
	void addGameObject(std::shared_ptr<GameObject> object);

	std::vector<std::shared_ptr<GameObject>> getAllGameObjects() const;
private:
	/*std::vector<GameObject> m_gameobjects;*/
	std::vector<std::shared_ptr<GameObject>> m_gameobjects;
};