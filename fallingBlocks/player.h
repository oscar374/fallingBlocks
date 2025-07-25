#pragma once

#include "gameObject.h"

class Player : public GameObject {
public:
	Player(
		const std::string& name = "unnamed object",
		Vector2 position = { 0, 0 },
		Vector2 size = { 0, 0 },
		Color color = { 0, 0, 0, 0 },
		float mass = 0,
		bool autoMass = true
	);

	void Jump();
private:
	const float m_jumpStrength = 1000;
	const float m_movementSpeed = 500;
};