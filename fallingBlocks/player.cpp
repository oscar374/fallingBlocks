#include "Player.h"

#include <iostream>

Player::Player(
    const std::string& name,
    Vector2 position,
    Vector2 size,
    Color color,
    float mass,
    bool autoMass
) : GameObject(name, position, size, color, mass, autoMass)
{

}

void Player::Jump() {
    if (this->getVelocity().y == 0)
        m_doubleJumpProgress = 0;

    if (m_doubleJumpProgress > 1)
        return;

    if (m_doubleJumpProgress == 0)
        this->setVelocity(Vector2(getVelocity().x, -m_jumpForce));
    else if (m_doubleJumpProgress == 1)
        this->setVelocity(Vector2(getVelocity().x, -m_jumpForce * 0.7));

    m_doubleJumpProgress++;
} 

void Player::Move(bool direction, float deltaTime) {
    if (direction) {
        this->setPosition(Vector2(getPosition().x + (m_movementSpeed * deltaTime), getPosition().y));
    }
    else {
        this->setPosition(Vector2(getPosition().x - (m_movementSpeed * deltaTime), getPosition().y));
    }
}