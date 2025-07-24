#include "PhysicsSystem.h"
#include "settings.h"
#include <iostream>
void PhysicsSystem::update(std::vector<GameObject>& gameobjects, float deltaTime) {

	for (GameObject& object : gameobjects) {
		bool isColliding = false;

		if (!(object.getPosition().y < 500 - object.getSize().y)) isColliding = true;   //ground check
		
		for (GameObject& collider : gameobjects) {  //other objects collision check                           
			if (&object == &collider) continue;
			if (collider.getPosition().x + collider.getSize().x > object.getPosition().x &&
				collider.getPosition().x < object.getPosition().x + object.getSize().x &&
				collider.getPosition().y + collider.getSize().y > object.getPosition().y &&
				collider.getPosition().y < object.getPosition().y + object.getSize().y) {
				isColliding = true;
			}
		}

		if (!isColliding) {
			object.setVelocity(Vector2(object.getVelocity().x, object.getVelocity().y + m_gravityStrength * deltaTime));
		}
		else {
			if (object.getVelocity().y > 0.0f) {
				object.setVelocity(Vector2(object.getVelocity().x, 0));
			}
		}

		object.setPosition(Vector2(object.getPosition().x + object.getVelocity().x * deltaTime, object.getPosition().y + object.getVelocity().y * deltaTime));
	}
}

PhysicsSystem::PhysicsSystem(const Vector2& winSize, float gravityStrength)
: m_windowSize(winSize), m_gravityStrength(gravityStrength){
}