#include "collision.h"

bool collision::AABB(ColliderComponent::rect& rectA, ColliderComponent::rect& rectB)
{
	return(rectA.right > rectB.left && rectA.left < rectB.right && rectA.bottom > rectB.top &&
		rectA.top < rectB.bottom);
}

bool collision::AABB(ColliderComponent* colA, ColliderComponent* colB)
{
	return AABB(colA->box, colB->box);
}

bool collision::OneWayAABB(ColliderComponent::rect& rectA, ColliderComponent::rect& rectB)
{
	//magic number i know cringe
	if (rectA.bottom <= rectB.top + 5)
	{
		return(rectA.right > rectB.left && rectA.left < rectB.right&& rectA.bottom > rectB.top &&
		rectA.top < rectB.bottom);
	}
	return false;
}


bool collision::OneWayAABB(ColliderComponent* colA, ColliderComponent* colB)
{
	return OneWayAABB(colA->box, colB->box);
}
