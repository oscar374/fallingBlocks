#include "Game.h"
#include "settings.h"
#include "engine.h"

#include <iostream>

void Game::startGame() {
	Engine window(settings);

	std::cout << "Game has started: " << "\n";
	std::cout << "difficulty: " << settings.difficulty << "\n";
}