#pragma once
#include "Component.h"
#include "TransformComponent.h"

class PlatformComponent : Component
{
public:


	/*
	 *for next time so i know what to do.
	 *say 800 is the lowest point that the player reaches.
	 *when the player hits a new platform this is called
	 *this platform will need to move down to the lowest position in this case 800
	 *the platform that was at 800 alrdy needs to move down out of screen
	 *get the platform that was last hit and calculate the distance between this one and the one you are on now
	 *that distance is the amount the platform needs to move down
	 *
	 */

	void MovePlatform(Entity& entity)
	{

	}

private:
};

