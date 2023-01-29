#pragma once
#include "ColliderComponent.h"
class collision
{
public:
	bool AABB(ColliderComponent::rect& rectA, ColliderComponent::rect& rectB);
	bool AABB(ColliderComponent& colA, ColliderComponent& colB);
};

