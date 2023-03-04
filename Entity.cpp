#include "Entity.h"
#include "Component.h"
#include <utility>

/* credit: https://www.youtube.com/watch?v=gKQd1qPQHgs&list=PLZHgukYvDo9cUYfUZZ6mtCrPnuX_4hRRl&index=8*/


Entity::Entity(Entity&& copy) noexcept
	: components(std::move(copy.components))
{
}


Entity::~Entity()
{
	for (auto& iter : components)
	{
		delete iter.second;
	}
}


void Entity::AddComponent(Component* component)
{
	components.insert({ typeid(*component), component });
}

void Entity::Init()
{
	for (auto& iter : components)
	{
		iter.second->Init(*this);
	}
}

void Entity::Update()
{
	for (auto& iter : components)
	{
		iter.second->Update(*this);
	}
}

void Entity::Render(Tmpl8::Surface& screen)
{
	for (auto& iter : components)
	{
		iter.second->Render(*this, screen);
	}
}

void Entity::KeyUp(SDL_Scancode key)
{
	for (auto& iter : components)
	{
		iter.second->KeyUp(*this, key);
	}
}

void Entity::KeyDown(SDL_Scancode key)
{
	for (auto& iter : components)
	{
		iter.second->KeyDown(*this, key);
	}
}

void Entity::MouseMove(int x, int y)
{
	for (auto& iter : components)
	{
		iter.second->MouseMove(*this, x, y);
	}
}

void Entity::MouseDown(int button)
{
	for (auto& iter : components)
	{
		iter.second->MouseDown(*this, button);
	}
}

void Entity::MouseUp(int button)
{
	for (auto& iter : components)
	{
		iter.second->MouseUp(*this, button);
	}
}

