#pragma once
#include "ColliderComponent.h"
#include "BreakingPlatform.h"
#include "Enemy.h"
#include "Sound.hpp"
class collision
{
public:
	static void CheckCol(Entity& player, Entity& object);
	static void CheckSides(Entity& player, Entity& object);
private:
};

