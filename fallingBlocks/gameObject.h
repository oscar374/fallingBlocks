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
		float mass = 0
	);

	Vector2 getPosition() const;
	Vector2 getSize() const;
	float getMass() const;
	Color getColor() const;

	void setPosition(const Vector2& newPosition);

	std::string getName() const;
private:

protected:
	Vector2 m_position;
	Vector2 m_size;
	Color m_color;
	float m_mass;

	std::string m_name;
};