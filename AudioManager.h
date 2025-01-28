#pragma once

#include "SDL_mixer.h"
#include <unordered_map>
#include <string>
#include <iostream>

class AudioManager
{

public:

	std::unordered_map<std::string, Mix_Chunk*> sounds;

	// Constructor
	AudioManager() = default;

	// load sound into unordered map
	void loadSound(std::string filePath, std::string soundName);
	
	// play given sound from unordered map
	static void playSound(AudioManager& audioManager, std::string soundName, int loops);
};

