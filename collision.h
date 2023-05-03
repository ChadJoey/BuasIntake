#pragma once
#include "ColliderComponent.h"
#include "BreakingPlatform.h"
#include "Enemy.h"
#include "Sound.hpp"
class collision
{
public:
	//checks if there is a collision
	static void CheckCol(Entity& player, Entity& object);
	//handles collision responses based on components and direction of collision
	static void CheckSides(Entity& player, Entity& object);
private:
};

