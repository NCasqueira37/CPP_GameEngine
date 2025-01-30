#include "FontManager.h"


void FontManager::loadFont(std::string filePath, std::string fontName, int ptSize) {
	TTF_Font* font = TTF_OpenFont(filePath.c_str(), ptSize);
	if (font == nullptr)
		try {
		throw std::runtime_error("Error opening font\n");
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}


	fonts.insert(std::make_pair(fontName, font));
}