#pragma once
#include "Component.h"
#include "TransformComponent.h"
#include "Entity.h"
#include "SpriteComponent.h"
#include "ColliderComponent.h"
#include "Timer.h"
#include "sounds.h"

class PlayerComponent : public Component
{
public:
	PlayerComponent(sounds* sound);

	//updates player component
	void Update(Entity& entity) override;


	void Render(Entity& entity, Tmpl8::Surface& screen) override {}

	// a key is pressed
	void KeyDown(Entity& entity, SDL_Scancode key) override;

	//a key is let go
	 void KeyUp(Entity& entity, SDL_Scancode key) override;

	 //wraps player when leaving either side
	void Wrap(Entity& entity);

	//reverses players Y velocity
	void flipVelocity(bool playSound);
	//handles animation frames
	void visuals(Entity& entity);
	//handles player physics 
	void Move();
	//handles knocked out state
	void Knockout();

	//resets player conditions
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

	int frame = 0;
	float velY = 0.0f;
	float yOffset = 0.0f;
	float y = 300;
	float velX = 0;
	bool canMove = false;
	bool knockedOut = false;
	bool facingRight = false;

	sounds& sound;
protected:


private:
	Timer& timer;
	//pixels per second
	float speedX = 300.0f;
	float gravity = 400.0f;
	float maxVelY = -430;
	float maxVelx = speedX;
	float x = 50;
	float time = 0;
	float timeIncrement = 0.05f;
	int knockoutFrame = 0;
	bool right = false;
	bool left = false;
};

