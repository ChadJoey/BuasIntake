#pragma once


#include "surface.h"
#include "template.h"


class Button
{
public:
	Button(Tmpl8::vec2 pos, Tmpl8::Surface* sprite) :
	pos(pos),
	sprite(sprite ,2)
	{}

	~Button() = default;

	void OnClick(bool& state)
	{
		if (!onButton || !active)
		{
			return;
		}

		if (state)
		{
			state = false;
		}
		else
		{
			state = true;
		}

		active = false;
	}


	void MouseMove(int x , int y);

	void MouseDown(bool& state);

	void SetActive(bool state)
	{
		active = state;
		onButton = false;
	}

	void Render(Tmpl8::Surface* screen);

	bool IsActive() { return active; }


	void ButtonUp(){}


private:
	Tmpl8::vec2 pos;
	Tmpl8::Sprite sprite;


	bool active = false;
	bool onButton = false;


};
