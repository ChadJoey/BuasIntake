#pragma once
#include "PlatformComponent.h"
#include "SpriteComponent.h"
#include "Audio/Sound.hpp"

class BreakingPlatform : public Component
{
public:
	BreakingPlatform(sounds* sound) :
		sound(sound)
	{
		
	}
	void Update(Entity& entity) override;
	void Reset();
	bool playAnim = false;
private:
	sounds* sound;
	float time = 0;
	float velY = 250;
	bool canPlaySound = true;
};

