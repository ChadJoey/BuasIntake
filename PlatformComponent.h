#pragma once
#include <random>
#include "TransformComponent.h"

class PlatformComponent : public Component
{
public:
	PlatformComponent() = default;
	void Update(Entity& entity) override;

	void Init(Entity& entity) override;

protected:
	Tmpl8::vec2 maxpos = { ScreenWidth - 60,80 };
	Tmpl8::vec2 minpos = { 0, 0 };
};

