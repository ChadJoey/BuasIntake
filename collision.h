#pragma once
#include "ColliderComponent.h"
class collision
{
public:
	static bool AABB(ColliderComponent::rect& rectA, ColliderComponent::rect& rectB);
	static bool AABB(ColliderComponent* colA, ColliderComponent* colB);
	static bool OneWayAABB(ColliderComponent::rect& rectA, ColliderComponent::rect& rectB);
	static bool OneWayAABB(ColliderComponent* colA, ColliderComponent* colB);
private:
};

