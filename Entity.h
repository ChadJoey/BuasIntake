#pragma once

#include <SDL_scancode.h>
#include <typeindex>
#include <vector>
#include <unordered_map>


/* credit: https://www.youtube.com/watch?v=gKQd1qPQHgs&list=PLZHgukYvDo9cUYfUZZ6mtCrPnuX_4hRRl&index=8*/



class Component;

namespace Tmpl8
{
	class Surface;
}



class Entity
{
public:

	Entity() = default;

	Entity(const Entity& copy) = delete;
	
	Entity(Entity&& copy) noexcept;
	
	~Entity();
	//add a component to this entity
	void AddComponent(Component* component);

	template<typename T>
	T* GetComponent() const;


	void SetActive(bool isActive)
	{
		this->isActive = isActive;
	}


	template<typename T>
	std::vector<T*> GetComponents() const;

	virtual void Init();


	//Update the component
	void Update();


	//render the component
	void Render(Tmpl8::Surface& screen);

	//a key is let go
	void KeyUp(SDL_Scancode key);

	//A key is being held
	void KeyDown(SDL_Scancode key);

	//the mouse is moved (screen space)
	void MouseMove(int x, int y);

	//a button on the mouse is pressed
	void MouseDown(int button);

	//mouse button is released
	void MouseUp(int button);


	bool isActive = true;
protected:

private:
	std::unordered_multimap<std::type_index, Component*> components;
};


template <typename T>
T* Entity::GetComponent() const
{
	auto iter = components.find(typeid(T));
	if (iter != components.end())
	{
		return dynamic_cast<T*>((*iter).second);
	}
	return nullptr;
}



template<typename T>
std::vector<T*> Entity::GetComponents() const
{

	auto range = components.equal_range(typeid(T));
	std::vector<T*> res;

	for(auto it = range.first; it != range.second; ++it)
	{
		res.push_back(dynamic_cast<T*>(it->second));
	}

	return res;
}
