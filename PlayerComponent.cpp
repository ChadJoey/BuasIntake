#include "PlayerComponent.h"

#include <windows.h>

#include "template.h"



PlayerComponent::PlayerComponent() :
 timer(Timer::Get())
{
	
}


float y = 400;


void PlayerComponent::Update(Entity& entity)
{
	TransformComponent* transform = entity.GetComponent<TransformComponent>();
	SpriteComponent* sprite = entity.GetComponent<SpriteComponent>();

	const float delta = timer.GetElapsedSeconds();

	double x = 0.0f;
	if (right)
		x += speedX * delta;
	
	if (left)
		x -= speedX * delta;
	
	
	transform->AddPosition({ static_cast<float>(x) , 0 });


	//---------------------------------------------------------------






	velY += gravity * delta;
	y += velY * delta;


	if (y > (ScreenHeight - sprite->GetHeight()))
	{
		velY = -velY;
		y = ScreenHeight - sprite->GetHeight();
	}

	//update position
	transform->SetPosition({ transform->GetPosition().x, (y)});





	//------------------------------------------------------------------------
}


void PlayerComponent::Render(Entity& entity, Tmpl8::Surface& screen)
{

}





void PlayerComponent::KeyDown(Entity& entity, const SDL_Scancode key)
{
	TransformComponent* transform = entity.GetComponent<TransformComponent>();
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

