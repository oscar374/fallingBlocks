#include "Game.h"
#include "settings.h"

#include <iostream>

void Game::startGame() {
	GameWindow window(settings);

	std::cout << "Game has started: " << "\n";
	std::cout << "difficulty: " << settings.difficulty << "\n";
}