#pragma once
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

	void Update(Entity& entity) override;


	void Render(Entity& entity, Tmpl8::Surface& screen) override {};

	// a key is pressed
	virtual void KeyDown(Entity& entity, SDL_Scancode key) override;

	//a key is let go
	virtual void KeyUp(Entity& entity, SDL_Scancode key) override;


	void Wrap(Entity& entity);

	void flipVelocity();
	void visuals(Entity& entity);
	void Move();
	void Knockout(Entity& entity);

	void Reset()
	{
		velX = 0;
		velY = 0;
		y = 300;
		x = 50;
		canMove = false;
		left = false;
		right = false;
		knockedOut = false;
	}


	float velY = 0.0f;
	float yOffset = 0.0f;
	float y = 300;
	float velX = 0;
	bool canMove = false;
	bool knockedOut = false;

	//false = left true is right
	bool lastDir = false;

protected:

private:
	Timer& timer;
	//pixels per second
	float speedX = 100.0f;
	float gravity = 100.0f;
	float maxVelY = -210;
	float maxVelx = speedX;
	float x = 50;
	float time = 0;
	bool right = false;
	bool left = false;
};

