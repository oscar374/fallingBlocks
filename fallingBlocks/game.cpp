#include "Game.h"
#include "settings.h"
#include "engine.h"

#include <iostream>

void Game::startGame() {
	Engine engine;
	engine.run();
}