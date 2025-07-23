#pragma once

#include "settings.h"
#include "gameObject.h"
#include "World.h"
#include "Vector2.h"
#include "color.h"
#include "physicsSystem.h"

#include <iostream>
#include <SDL3/SDL.h>
#include <vector>

class GameWindow {
public:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	GameWindow(const Settings& settings);
private:
	bool m_isRunning = false;

	World world;
	PhysicsSystem physics = PhysicsSystem(Vector2(0, 0), 0);

	void run();
	void handleEvents();
	void update();
	void render();
};