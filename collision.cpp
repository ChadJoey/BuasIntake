#include "collision.h"

bool collision::AABB(ColliderComponent::rect& rectA, ColliderComponent::rect& rectB)
{
	return(rectA.posX + rectA.width >= rectB.posX && rectB.posX + rectB.width >= rectA.posX &&
		rectA.posY + rectA.height >= rectB.posY && rectB.posY + rectB.height >= rectA.posY);
}

bool collision::AABB(ColliderComponent& colA, ColliderComponent& colB)
{
	return AABB(colA.box, colB.box);
}
