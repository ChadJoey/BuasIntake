#pragma once
#include "PlatformComponent.h"
#include "SpriteComponent.h"

class BreakingPlatform : public Component
{
public:
	BreakingPlatform() = default;
	void Update(Entity& entity);
	void Reset();
	bool playAnim = false;
private:
	float time = 0;
	float velY = 250;
};

