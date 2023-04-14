#pragma once
#include "Component.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"

class Enemy : public Component
{
public:
	virtual void Update(Entity& entity) override;
	bool hit = false;
private:
	float time = 0;
};

