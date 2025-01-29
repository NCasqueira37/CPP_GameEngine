#include "AudioManager.h"


void AudioManager::loadSound(std::string filePath, std::string soundName) {
	Mix_Chunk* sound = Mix_LoadWAV(filePath.c_str());
	if (sound == nullptr)
		std::cout << "Error loading sound\n";
		throw std::runtime_error("Error loading sound\n");

	sounds.insert(std::make_pair(soundName, sound));
}


void AudioManager::playSound(AudioManager& audioManager, std::string soundName, int loops) {
	Mix_PlayChannel(-1, audioManager.sounds[soundName], loops);
}