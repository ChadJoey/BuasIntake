#pragma once


#include "surface.h"
#include "template.h"


class Button
{
public:
	Button(Tmpl8::vec2 pos, Tmpl8::Surface* surface) :
		pos(pos),
		sprite(surface, 2)
	{}


	~Button() = default;

	//flip a bool for when the button is pressed
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

	//detects is hovering above button
	void MouseMove(int x , int y);

	//sets state for the button
	void SetActive(bool state)
	{
		active = state;
		onButton = false;
	}

	//renders the button
	void Render(Tmpl8::Surface* screen);

	//checks if button is active or not
	bool IsActive() { return active; }

	//returns pos
	Tmpl8::vec2 GetPos()
	{
		return pos;
	}

	//sets pos
	void SetPos(Tmpl8::vec2 pos)
	{
		this->pos = pos;
	}


private:
	Tmpl8::vec2 pos;
	Tmpl8::Sprite sprite;

	bool active = false;
	bool onButton = false;


};
