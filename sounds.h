#pragma once
#include "Sound.hpp"

class sounds
{
public:
	sounds() = default;

	Audio::Sound jump{ "assets/doodle/jump.wav", Audio::Sound::Type::Sound };
	Audio::Sound enemyHit{ "assets/doodle/monster.mp3", Audio::Sound::Type::Sound };
	Audio::Sound playerHit{ "assets/doodle/monster-crash.mp3", Audio::Sound::Type::Sound };
	Audio::Sound breakingPlat{ "assets/doodle/brPlatform.mp3", Audio::Sound::Type::Sound };
	Audio::Sound fall{ "assets/doodle/pada.mp3", Audio::Sound::Type::Sound };
private:
};

