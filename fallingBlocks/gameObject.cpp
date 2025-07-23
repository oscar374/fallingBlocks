#include "gameObject.h"
#include "Vector2.h"


GameObject::GameObject(const std::string& name, Vector2 position, Vector2 size, Color color, float mass)
	: m_name(name), m_position(position), m_size(size), m_color(color), m_mass(mass) {
}

//GET
Vector2 GameObject::getPosition() const {
	return m_position;
}

Vector2 GameObject::getSize() const {
	return m_size;
}

float GameObject::getMass() const {
	return m_mass;
}

Color GameObject::getColor() const {
	return m_color;
}

std::string GameObject::getName() const {
	return m_name;
}


//SET
void GameObject::setPosition(const Vector2& newPosition) {
	m_position = newPosition;
}
