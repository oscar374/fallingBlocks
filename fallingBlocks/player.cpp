#include "Player.h"

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
    this->setVelocity(Vector2(getVelocity().x, m_jumpStrength));
}