#pragma once
#include "ColliderComponent.h"
#include "BreakingPlatform.h"
#include "Enemy.h"
class collision
{
public:
	static void CheckCol(Entity& player, Entity& object);
	static void CheckSides(Entity& player, Entity& object);

private:
};

