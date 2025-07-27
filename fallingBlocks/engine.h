#pragma once

#include "settings.h"
#include "gameObject.h"
#include "World.h"
#include "Vector2.h"
#include "color.h"
#include "physicsSystem.h"
#include "obstacleSpawner.h"
#include "player.h"

#include <iostream>
#include <SDL3/SDL.h>
#include <vector>
#include <memory>

class Engine {
public:
	Engine();
	void run();

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
private:
	bool m_isRunning = false;

	World world;
	PhysicsSystem physics = PhysicsSystem(Vector2(0, 0), 0);
	ObstacleSpawner* obstacleSpawner;
	std::shared_ptr<Player> player;

	void handleEvents();
	void update(const float& deltatime);
	void render();
};