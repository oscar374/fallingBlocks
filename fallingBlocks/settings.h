#pragma once

#include "enums.h"
#include <string>

struct Settings {
	EGameDifficulty difficulty = EGameDifficulty::EASY;

	const uint32_t windowWidth = 1000;
	const uint32_t windowHeight = 500;
};