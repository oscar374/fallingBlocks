#pragma once

#include "gameObject.h"
#include "settings.h"

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
	void Move(bool direction, float deltaTime);
private:
	const float m_jumpForce = settings.jumpStrength;
	const float m_movementSpeed = settings.moveSpeed;

	int m_doubleJumpProgress = 0;
};