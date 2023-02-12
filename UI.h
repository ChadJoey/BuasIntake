#pragma once
#include "game.h"


constexpr bool isPlaying = false;

class UI
{
public:
	UI(Tmpl8::Surface* sufrace, Tmpl8::Surface* screen) :
		Surface(Surface), sprite(sufrace, 1), screen(screen)
	{}

	void StartMenu()
	{
		sprite.Draw(screen, 0,0);
	}

private:

	Tmpl8::Sprite sprite;
	Tmpl8::Surface* Surface;
	Tmpl8::Surface* screen;

};

