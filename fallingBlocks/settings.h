#pragma once

#include "enums.h"
#include <string>

struct Settings {
	EGameDifficulty difficulty = EGameDifficulty::EASY;
	const uint32_t windowWidth = 1920;
	const uint32_t windowHeight = 1080;

	const float physicsGravityStrength = 2000;

	//obstacles size ( % of the screen width and height )
	const float obstacleWidthMin = 0.02f;
	const float obstacleWidthMax = 0.07f;

	const float obstacleHeightMin = 0.02f;
	const float obstacleHeightMax = 0.07f;

	//movement
	const float jumpStrength = 700;
	const float moveSpeed = 300;


	//spawning
	const float obstaclesSpawningRate = 0.2f; // seconds
};

const Settings settings;
