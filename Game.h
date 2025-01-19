#pragma once

#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

class Game
{
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	bool isRunning = false;

public:
	Game();

	void handleEvents(SDL_Event& event);
	void handleInput(SDL_Event& event);
	void update(float deltaTime);
};

