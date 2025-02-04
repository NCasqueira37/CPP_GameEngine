#pragma once

#include <iostream>
#include "SDL.h"
#include "Vector2D.h"

class Entity
{

public:
	SDL_Texture* texture = nullptr;
	SDL_Rect rect{};
	Vector2D pos;

	// Draw the Entity with the given texture
	void draw(SDL_Renderer* renderer) const;
};

