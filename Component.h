#pragma once
#include <SDL_scancode.h>
#include <string>

/* credit: https://www.youtube.com/watch?v=gKQd1qPQHgs&list=PLZHgukYvDo9cUYfUZZ6mtCrPnuX_4hRRl&index=8*/

namespace Tmpl8
{
	class Surface;
}

class Entity;

class Component
{

public:

	static const std::string& ID()
	{
		static std::string id = "Component";
		return id;
	}

	virtual const std::string& GetID()
	{
		return ID();
	}

	virtual void Init(Entity& entity);

	//Update the component
	virtual void Update(Entity& entity);


	//render the component
	virtual void Render(Entity& entity, Tmpl8::Surface& screen);

	//a key is let go
	virtual void KeyUp(Entity& entity, SDL_Scancode key);

	//A key is being held
	virtual void KeyDown(Entity& entity, SDL_Scancode key);

	//the mouse is moved (screen space)
	virtual void MouseMove(Entity& entity, int x, int y);

	//a button on the mouse is pressed
	virtual void MouseDown(Entity& entity, int button);

	//a mouse button is released
	 virtual void MouseUp(Entity& entity, int);

	 //requirment for minimal base types
	virtual ~Component() = default;

protected:
	//do not construct directly
	Component() = default;
	 
private:
};