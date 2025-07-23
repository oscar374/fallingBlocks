#include "PhysicsSystem.h"
#include "settings.h"
#include <iostream>
void PhysicsSystem::update(std::vector<GameObject>& gameobjects, float deltaTime) {

	for (GameObject& object : gameobjects) {
		if (object.getPosition().y < 500 - object.getSize().y) {
			object.setPosition(object.getPosition() + Vector2(0, object.getMass() * m_gravityStrength));
		}
	}
}

PhysicsSystem::PhysicsSystem(const Vector2& winSize, float gravityStrength)
: m_windowSize(winSize), m_gravityStrength(gravityStrength){
}