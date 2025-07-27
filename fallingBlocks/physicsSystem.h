#pragma once

#include <vector>
#include <memory>

#include "Vector2.h"
#include "gameObject.h"

class PhysicsSystem {
public:
	PhysicsSystem(const Vector2& winSize, float gravityStrength);

	void update(std::vector<std::shared_ptr<GameObject>>, float deltaTime);
private:
	Vector2 m_windowSize;
	float m_gravityStrength;
};