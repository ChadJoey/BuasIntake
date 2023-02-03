#include "PlayerComponent.h"

#include <iostream>
#include <windows.h>

#include "template.h"



PlayerComponent::PlayerComponent() :
 timer(Timer::Get())
{
	
}


float x = 0.0f;



void PlayerComponent::Update(Entity& entity)
{
	TransformComponent* transform = entity.GetComponent<TransformComponent>();
	SpriteComponent* sprite = entity.GetComponent<SpriteComponent>();

	const float delta = timer.GetElapsedSeconds();

	if (right)
	{
		x += speedX * delta;
		sprite->SetFrame(4);
	}
	
	
	if (left)
	{
		x -= speedX * delta;
		sprite->SetFrame(0);
	}


	//---------------------------------------------------------------






	velY += gravity * delta;
	y += velY * delta;

	if (y > (ScreenHeight - sprite->GetHeight()))
	{

		y = ScreenHeight - sprite->GetHeight();
	}

	//update position
	transform->SetPosition({x, y});


	//------------------------------------------------------------------------

	Wrap(entity);
}


void PlayerComponent::Render(Entity& entity, Tmpl8::Surface& screen)
{

}

void PlayerComponent::Wrap(Entity& entity)
{
	auto pc = entity.GetComponent<ColliderComponent>();
	if (ScreenWidth <= pc->box.left)
	{
		x = -50;
	}
	else if (pc->box.right <= 0)
	{
		x = ScreenWidth - 10;
	}

}




void PlayerComponent::KeyDown(Entity& entity, const SDL_Scancode key)
{
	TransformComponent* transform = entity.GetComponent<TransformComponent>();
	SpriteComponent* sprite = entity.GetComponent<SpriteComponent>();
	switch (key)
	{
	case SDL_SCANCODE_D:
	case SDL_SCANCODE_RIGHT:
		left = false;
		right = true;
		
		break;
	case SDL_SCANCODE_A:
	case SDL_SCANCODE_LEFT:
		right = false;
		left = true;
		
		break;
	}
}

void PlayerComponent::KeyUp(Entity& entity, SDL_Scancode key)
{
	switch (key)
	{
	case SDL_SCANCODE_D:
	case SDL_SCANCODE_RIGHT:
		right = false;
		break;

	case SDL_SCANCODE_A:
	case SDL_SCANCODE_LEFT:
		left = false;
		break;
	}
}

void PlayerComponent::flipVelocity()
{
	velY = maxVelY;
}








