#pragma once

#include "SDL_ttf.h"
#include <unordered_map>
#include <string>
#include <iostream>

class FontManager
{

public:

	std::unordered_map<std::string, TTF_Font*> fonts;

	void loadFont(std::string filePath, std::string fontName, int ptSize);
};

