#pragma once
#include "Tile.h"

class GameManager
{

public:
	// All tiles in game
	std::vector<Tile> tiles;

	// Default constructor
	GameManager() = default;
};