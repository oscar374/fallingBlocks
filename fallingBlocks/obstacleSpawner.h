#pragma once

#include "world.h"
#include "settings.h"

class ObstacleSpawner {
public:
	ObstacleSpawner(World& world);

	void update(const float& deltaTime);

	float getDifficultyMultiplier() const { return m_difficultyMultiplier; }
private:
	void spawnObstacle();
	float randomFloat(float min, float max);

	World& m_world;

	float m_difficultyMultiplier = 1.0f;
	float m_rate = settings.obstaclesSpawningRate;
	float m_timer = 0.0f;
};