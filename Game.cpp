#include "Game.h"

GameManager gameManager;
AudioManager audioManager;
TextureManager textureManager;
FontManager fontManager;

Game::Game() {

	// Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// Create window
	window = SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, 0);
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

			// Set blend mode for transparent textures
			SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

			// Open audio
			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2040) < 0) {
				std::cout << Mix_GetError() << std::endl;
				SDL_Quit();
			}

			// Initialize ttf
			if (TTF_Init() < 0) {
				std::cout << TTF_GetError() << std::endl;
			}

			// Load Texture files
			
			// Load Font files
			fontManager.loadFont("Data/Fonts/square-deal.ttf", "SquareDeal", 100);

			// Load Audio files
			audioManager.loadSound("Data/Sounds/laserShoot.wav", "Laser1");

			// Create tiles
			Tile::createTiles(windowWidth, windowHeight, (int)tileSize, gameManager.tiles);

			// Delta time variables
			Uint64 previousFrame = SDL_GetPerformanceCounter();
			Uint64 currentFrame = SDL_GetPerformanceCounter();
			float deltaTime = 0;

			// FPS
			int fps = 0;

			// Main Loop
			isRunning = true;
			SDL_Event event{};
			while (isRunning) {
				SDL_PollEvent(&event);

				// Handle Events
				handleEvents(event);

				// Handle Input
				handleInput(event);

				// Calculate deltaTime
				currentFrame = SDL_GetPerformanceCounter();
				deltaTime = static_cast<double>(currentFrame - previousFrame) / SDL_GetPerformanceFrequency();	
				previousFrame = currentFrame;

				// FPS
				fps = (1 / deltaTime);

				// Handle Update
				update(deltaTime);

				// handle draw
				draw(renderer);
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
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		if (event.button.button == SDL_BUTTON_LEFT) {

		}
	}
}


void Game::update(float deltaTime) {
	//std::cout << deltaTime << "\n";
}


void Game::draw(SDL_Renderer* renderer) {
	// Clear the renderer
	SDL_RenderClear(renderer);

	// Set the background color to black
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	// Draw tiles
	for (auto& t : gameManager.tiles) {
		t.draw(renderer);
	}

	// Updates the renderer
	SDL_RenderPresent(renderer);
}