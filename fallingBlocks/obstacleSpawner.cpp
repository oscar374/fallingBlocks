#include "obstacleSpawner.h"

#include <random>

#include "gameObject.h"
#include "settings.h"

ObstacleSpawner::ObstacleSpawner(World& world)
	: m_world(world) { }

void ObstacleSpawner::update(const float& deltaTime) {
	m_timer += deltaTime;

	if (m_timer >= m_rate) {
		m_timer = 0.0f;
		spawnObstacle();
	}
}

void ObstacleSpawner::spawnObstacle() {
	float obstacleWidth = (randomFloat(settings.obstacleWidthMin, settings.obstacleWidthMax) * settings.windowWidth);
	float obstacleHeight = (randomFloat(settings.obstacleHeightMin, settings.obstacleHeightMax) * settings.windowHeight);
	Vector2 size = Vector2(obstacleWidth, obstacleHeight);

	Vector2 position = Vector2(randomFloat(0.0f, settings.windowWidth - obstacleWidth), 0.0f);

	std::shared_ptr<GameObject> obstacle = std::make_shared<GameObject>("obstacle", position, size, Color(255, 0, 0, 0), 1, false);
	m_world.addGameObject(obstacle);


}

float ObstacleSpawner::randomFloat(float min, float max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(min, max);
	return dis(gen);
}