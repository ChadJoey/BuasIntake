#include "collision.h"

//source
//https://www.gamedev.net/tutorials/programming/general-and-gameplay-programming/swept-aabb-collision-detection-and-response-r3084/

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
	if (rectA.bottom <= rectB.top)
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



float collision::SweptAABB(ColliderComponent* rectA, ColliderComponent* rectB)
{
	return SweptAABB(rectA->box, rectB->box);
}


float collision::SweptAABB(ColliderComponent::rect& rectA, ColliderComponent::rect& rectB)
{

	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;
	//get distance between objects
	if (rectA.vx > 0.0f)
	{
		xInvEntry = rectB.left - rectA.right;
		xInvExit = rectB.right - rectA.left;
	}
	else
	{
		xInvEntry = rectB.right - rectA.left;
		xInvExit = rectB.left - rectA.right;
	}

	if (rectA.vy > 0.0f)
	{
		yInvEntry = rectB.top - rectA.bottom;
		yInvExit = rectB.bottom - rectA.top;
	}
	else
	{
		yInvEntry = rectB.bottom - rectA.top;
		yInvExit = rectB.top - rectA.bottom;
	}

	float xEntry, yEntry;
	float xExit, yExit;
	//find the time between objects
	if (rectA.vx == 0.0f)
	{
		xEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		xEntry = xInvEntry / rectA.vx;
		xExit = xInvExit / rectA.vx;
	}

	if (rectA.vy == 0.0f)
	{
		yEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		yEntry = yInvEntry / rectA.vy;
		yExit = yInvExit / rectA.vy;
	}

	const float entryTime = std::max(xEntry, yEntry);
	const float exitTime = std::min(xExit, yExit);

	//check if we have collided or not
	if (entryTime > exitTime || xEntry < 0.0f && yEntry < 0.0f || xEntry > 1.0f || yEntry > 1.0f)
	{
		return 1.0f;
	}
	else
	{
		if (rectA.bottom <= rectB.top)
		{
			return entryTime;
		}
	}


}


