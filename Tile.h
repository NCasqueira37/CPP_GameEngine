#pragma once

#include <vector>
#include "Vector2I.h"
#include "SDL2/SDL2_MAIN/include/SDL.h"
#include "cmath"


class Tile
{
	enum Type {
		BACKGROUND
	};

public:
	// Tile position, rect, and type
	Vector2I pos;
	SDL_Rect rect;
	Type type = BACKGROUND;

	// Constructors
	Tile() = default;
	Tile(Vector2I pos, int tileSize, std::vector<Tile>& tiles);
	
	// Static function to create tiles, called only once
	static void createTiles(int w, int h, int tileSize, std::vector<Tile>& tiles);

	// Static function to get tile from mouse
	static const Tile& getTile(int tileSize, std::vector<Tile>& tiles);

	// Static function to get tile from input x and y
	static const Tile& getTile(int x, int y, int tileSize, std::vector<Tile>& tiles);

	// function to render each tile
	void draw(SDL_Renderer* renderer) const;
};

