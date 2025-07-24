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

	Vector2 getPosition() const;
	Vector2 getSize() const;
	float getMass() const;
	Color getColor() const;
	Vector2 getVelocity() const;

	void setPosition(const Vector2& newPosition);
	void setSize(const Vector2& newSize);
	void setVelocity(const Vector2& newVelocity);
	std::string getName() const;

	bool isFalling() const;


private:
	void calculateMass();

protected:
	Vector2 m_position;
	Vector2 m_size;
	Color m_color;
	float m_mass;

	Vector2 m_velocity;

	std::string m_name;
};