#pragma once

#include "Vector2.h"
#include "color.h"

#include <string>

class GameObject {
public:
	GameObject(
		const std::string& name = "unnamed object",
		Vector2 position = { 0, 0 },
		Vector2 size = { 0, 0 },
		Color color = { 0, 0, 0, 0 },
		float mass = 0,
		bool autoMass = true
	);

	std::string getName() const { return m_name; }
	Vector2 getPosition() const { return m_position; }
	Vector2 getSize() const { return m_size; }
	float getMass() const { return m_mass; }
	Color getColor() const { return m_color; }
	Vector2 getVelocity() { return m_velocity; }

	void setPosition(const Vector2& newPosition);
	void setSize(const Vector2& newSize);
	void setVelocity(const Vector2& newVelocity);
	void setGrounded(bool grounded);

	bool isFalling() const;


private:
	void calculateMass();

protected:
	Vector2 m_position;
	Vector2 m_size;
	Color m_color;
	float m_mass;
	bool m_grounded;

	Vector2 m_velocity;

	std::string m_name;
};