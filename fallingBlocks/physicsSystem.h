#pragma once

#include <vector>

#include "Vector2.h"
#include "gameObject.h"

class PhysicsSystem {
public:
	PhysicsSystem(const Vector2& winSize, float gravityStrength);

	void update(std::vector<GameObject>& gameobjects, float deltaTime);
private:
	Vector2 m_windowSize;
	float m_gravityStrength = 1;
};