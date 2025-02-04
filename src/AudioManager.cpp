#include "AudioManager.h"


void AudioManager::loadSound(std::string filePath, std::string soundName) {
	Mix_Chunk* sound = Mix_LoadWAV(filePath.c_str());
	if (sound == nullptr)
		try {
		throw std::runtime_error("Error loading sound\n");
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	sounds.insert(std::make_pair(soundName, sound));
}


void AudioManager::playSound(AudioManager& audioManager, std::string soundName, int loops) {
	Mix_PlayChannel(-1, audioManager.sounds[soundName], loops);
}