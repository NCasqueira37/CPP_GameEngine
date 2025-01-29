#pragma once

#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "GameManager.h"
#include "AudioManager.h"
#include "TextureManager.h"
#include "FontManager.h"


class Game
{
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	int windowWidth = 800;
	int windowHeight = 600;
	double tileSize = 50;

	bool isRunning = false;

public:
	Game();

	void handleEvents(SDL_Event& event);
	void handleInput(SDL_Event& event);
	void draw(SDL_Renderer* renderer);
	void update(float deltaTime);
};

