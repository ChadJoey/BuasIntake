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
