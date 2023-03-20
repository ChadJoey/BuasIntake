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

	Tmpl8::vec2 GetPos()
	{
		return pos;
	}

	void SetPos(Tmpl8::vec2 pos)
	{
		this->pos = pos;
	}

	void ButtonUp(){}


private:
	Tmpl8::vec2 pos;
	Tmpl8::Sprite sprite;

	bool active = false;
	bool onButton = false;


};
