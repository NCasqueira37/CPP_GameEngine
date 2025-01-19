#include "Game.h"



Game::Game() {

	// Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// Create window
	window = SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	if (window == nullptr) {
		std::cout << SDL_GetError() << std::endl;
	}
	else {
		// Create Renderer
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == nullptr) {
			std::cout << SDL_GetError() << std::endl;
		}
		else {
			// window and renderer created successfully

			// Open audio
			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2040) < 0) {
				std::cout << Mix_GetError() << std::endl;
				SDL_Quit();
			}

			// Initialize ttf
			if (TTF_Init() < 0) {
				std::cout << TTF_GetError() << std::endl;
			}

			// Main Loop
			isRunning = true;
			SDL_Event event{};
			while (isRunning) {
				SDL_PollEvent(&event);

				// Calculate deltaTime

				// Handle Update

				// Handle Events
				handleEvents(event);

				// Handle Input
				handleInput(event);
			}
		}
	}
}


void Game::handleEvents(SDL_Event& event) {
	if (event.type == SDL_QUIT) {
		isRunning = false;
	}
}


void Game::handleInput(SDL_Event& event) {

}


void Game::update(float deltaTime) {

}