#include "Tile.h"


Tile::Tile(Vector2D pos, int tileSize, std::vector<Tile>& tiles) {
	// Set tile position
	this->pos.x = pos.x;
	this->pos.y = pos.y;

	// Set rect position and size
	rect.x = pos.x * tileSize;
	rect.y = pos.y * tileSize;
	rect.w = tileSize;
	rect.h = tileSize;

	// Set tile type
	type = BACKGROUND;

	// Add tile to vector
	tiles.push_back(*this);
}


void Tile::createTiles(int w, int h, int tileSize, std::vector<Tile>& tiles) {
	for (int x = 0; x < w / tileSize; x++) {
		for (int y = 0; y < h / tileSize; y++) {
			Tile t(Vector2D(x, y), tileSize, tiles);
		}
	}
}


void Tile::draw(SDL_Renderer* renderer) const {
	bool dark = ((int)pos.x + (int)pos.y) % 2 == 0;
	switch (type)
	{
	case Tile::BACKGROUND:
		if (dark) {
			SDL_SetRenderDrawColor(renderer, 200, 198, 175, 255);
		}
		else {
			SDL_SetRenderDrawColor(renderer, 215, 208, 200, 255);
		}
		break;
	default:
		break;
	}
	
	SDL_RenderFillRect(renderer, &rect);
}


const Tile Tile::getTile(int tileSize, std::vector<Tile>& tiles) {
	int x, y;
	SDL_GetMouseState(&x, &y);

	for (auto& t : tiles) {
		if (x / tileSize == t.pos.x && y / tileSize == t.pos.y) {
			return t;
		}
	}
}


const Tile Tile::getTile(int x, int y, int tileSize, std::vector<Tile>& tiles) {
	for (auto& t : tiles) {
		if (x / tileSize == t.pos.x && y / tileSize == t.pos.y) {
			return t;
		}
	}
}