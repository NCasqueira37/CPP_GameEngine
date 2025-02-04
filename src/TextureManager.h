#pragma once

#include <unordered_map>
#include <string>
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"


class TextureManager
{

public:
	// unordered map to hold all textures with a given name
	std::unordered_map<std::string, SDL_Texture*> textures;

	// Constructors
	TextureManager() = default;

	// Function to load the texture
	void loadTexture(SDL_Renderer* renderer, const std::string filePath, const std::string textureName);
};