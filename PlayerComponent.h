#pragma once
#include "template.h"
#include "Component.h"
#include "TransformComponent.h"
#include "Entity.h"
#include "SpriteComponent.h"
#include "ColliderComponent.h"
#include "Timer.h"

class PlayerComponent : public Component
{
public:
	PlayerComponent();

	static const std::string& ID()
	{
		static std::string id = "PlayerComponent";
		return id;
	}

	virtual const std::string& GetID()
	{
		return ID();
	}






	void Update(Entity& entity) override;


	virtual void Render(Entity& entity, Tmpl8::Surface& screen) override;

	// a key is pressed
	virtual void KeyDown(Entity& entity, SDL_Scancode key) override;

	//a key is let go
	virtual void KeyUp(Entity& entity, SDL_Scancode key) override;









protected:

private:
	Timer& timer;
	//pixels per second
	float speedX = 100.0f;
	float velY = 0.0f;
	float gravity = 100.0f;

	bool right = false;
	bool left = false;




	

};

