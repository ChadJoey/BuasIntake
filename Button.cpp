#include "Button.h"
#include <SDL_mouse.h>
#include "surface.h"


void Button::MouseMove(int x, int y)
{

	const Tmpl8::vec2 min = pos;
	const Tmpl8::vec2 max = min + Tmpl8::vec2{ static_cast<float>(sprite.GetWidth()), static_cast<float>(sprite.GetHeight()) };

	if (min.x < x && max.x > x && min.y < y && max.y > y)
	{
		onButton = true;
	}
	else
	{
		onButton = false;
	}


}

void Button::Render(Tmpl8::Surface* screen)
{
	if (!active)
	{
		return;
	}


	if (onButton)
	{
		sprite.SetFrame(1);
	}
	else
	{
		sprite.SetFrame(0);
	}

		sprite.Draw(screen, pos.x, pos.y);
}
