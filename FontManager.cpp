#include "FontManager.h"


void FontManager::loadFont(std::string filePath, std::string fontName, int ptSize) {
	TTF_Font* font = TTF_OpenFont(filePath.c_str(), ptSize);
	if (font == nullptr)
		std::cout << "Error opening font\n";
		throw std::runtime_error("Error opening font\n");

	fonts.insert(std::make_pair(fontName, font));
}