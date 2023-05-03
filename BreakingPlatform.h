#pragma once
#include "PlatformComponent.h"
#include "SpriteComponent.h"
#include "Sound.hpp"

class BreakingPlatform : public Component
{
public:
	BreakingPlatform(sounds* sound) :
		sound(sound)
	{
		
	}
	//updates the breaking platforms behaviour
	void Update(Entity& entity) override;
	//reset the state for the platform
	void Reset();
	bool playAnim = false;
private:
	sounds* sound;
	float time = 0;
	float velY = 250;
	bool canPlaySound = true;
};

