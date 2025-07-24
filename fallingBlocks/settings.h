#pragma once

#include "enums.h"
#include <string>

struct Settings {
	EGameDifficulty difficulty = EGameDifficulty::EASY;
	const uint32_t windowWidth = 1000;
	const uint32_t windowHeight = 500;

	float physicsGravityStrength = 500;
	
	//obstacles size ( % of the screen width and height )
	float obstacleWidthMin = 0.05f;
	float obstacleWidthMax = 0.15f;

	float obstacleHeightMin = 0.05f;
	float obstacleHeightMax = 0.15f;
};

const Settings settings;
