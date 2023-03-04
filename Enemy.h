#pragma once
#include "Component.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"

class Enemy : public Component
{
	void Update(Entity& entity) override;
private:
	float time = 0;
};

