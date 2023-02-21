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


	virtual void Render(Entity& entity, Tmpl8::Surface& screen) override;

	// a key is pressed
	virtual void KeyDown(Entity& entity, SDL_Scancode key) override;

	//a key is let go
	virtual void KeyUp(Entity& entity, SDL_Scancode key) override;


	void Wrap(Entity& entity);

	void flipVelocity();


	float velY = 0.0f;
	float yOffset = 0.0f;
	float y = 300;
	float velX = 0;
	bool canMove = false;


protected:

private:
	Timer& timer;
	//pixels per second
	float speedX = 100.0f;
	float gravity = 100.0f;
	float maxVelY = -210;
	float maxVelx = speedX;
	float x = 50;
	bool right = false;
	bool left = false;




	

};

