#include "TextureManager.h"

void TextureManager::loadTexture(SDL_Renderer* renderer, const std::string filePath, const std::string textureName) {
	SDL_Texture* texture = nullptr;
	texture = IMG_LoadTexture(renderer, filePath.c_str());

	if (texture == nullptr) {
		std::cout << "Error Loading texture\n";
	}
	else {
		// Set blend mode for transparent textures
		SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);

		// Add texture to vector
		textures.insert(std::make_pair(textureName, texture));
	}
}