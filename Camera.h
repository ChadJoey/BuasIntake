#pragma once
#include "template.h"

class Camera
{
public:
	Tmpl8::vec2 camPos;

	struct CameraBounds
	{
		float left = 0;
		float right = ScreenWidth;
		float top = 250;
		float bottom = ScreenHeight;
	}camBounds;
	// cam is just a position loop trough it at the end in the transform update as a last call
private:
};

