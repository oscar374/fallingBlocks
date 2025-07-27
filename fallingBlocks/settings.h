#pragma once

#include "enums.h"
#include <string>

struct Settings {
	EGameDifficulty difficulty = EGameDifficulty::EASY;
	const uint32_t windowWidth = 1000;
	const uint32_t windowHeight = 1000;

	const float physicsGravityStrength = 2000;
	
	//obstacles size ( % of the screen width and height )
	const float obstacleWidthMin = 0.05f;
	const float obstacleWidthMax = 0.15f;

	const float obstacleHeightMin = 0.05f;
	const float obstacleHeightMax = 0.15f;
};

const Settings settings;
