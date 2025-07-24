#include "gameObject.h"
#include "Vector2.h"

GameObject::GameObject(const std::string& name, Vector2 position, Vector2 size, Color color, float mass, bool autoMass)
	: m_name(name), m_position(position), m_size(size), m_color(color), m_mass(mass) {

	m_velocity = Vector2(0.0f, 0.0f);
	if(autoMass)
		calculateMass();
}

bool GameObject::isFalling() const {
	return m_velocity.y > 0.0f;
}	

//SET
void GameObject::setPosition(const Vector2& newPosition) {
	m_position = newPosition;
}

void GameObject::setSize(const Vector2& newSize) {
	m_size = newSize;
}

void GameObject::setVelocity(const Vector2& newVelocity) {
	m_velocity = newVelocity;
}


void GameObject::calculateMass() {

}
