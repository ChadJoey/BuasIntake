#include "PlayerComponent.h"

#include <iostream>

#include "template.h"



PlayerComponent::PlayerComponent() :
 timer(Timer::Get())
{
	velX = 0;
}


void PlayerComponent::Update(Entity& entity)
{
	if (!entity.isActive)
	{
		return;
	}
	TransformComponent* transform = entity.GetComponent<TransformComponent>();

	visuals(entity);
	Move();

	Wrap(entity);
	transform->SetPosition({ x, y });
}



void PlayerComponent::Wrap(Entity& entity)
{
	auto pc = entity.GetComponent<ColliderComponent>();
	if (ScreenWidth <= pc->box.left)
	{
		x = -50;
	}
	else if (pc->box.right < 0)
	{
		x = ScreenWidth - 15;
	}
}




void PlayerComponent::KeyDown(Entity& entity, const SDL_Scancode key)
{
	if (!entity.isActive || !canMove)
	{
		return;
	}


	TransformComponent* transform = entity.GetComponent<TransformComponent>();
	SpriteComponent* sprite = entity.GetComponent<SpriteComponent>();
	switch (key)
	{
	case SDL_SCANCODE_D:
	case SDL_SCANCODE_RIGHT:
		left = false;
		right = true;
		lastDir = true;
		break;
	case SDL_SCANCODE_A:
	case SDL_SCANCODE_LEFT:
		right = false;
		left = true;
		lastDir = false;
		
		break;
	}
}

void PlayerComponent::KeyUp(Entity& entity, SDL_Scancode key)
{

	if (!entity.isActive || !canMove)
	{
		return;
	}
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



void PlayerComponent::visuals(Entity& entity)
{
	SpriteComponent* sprite = entity.GetComponent<SpriteComponent>();
	
	if (knockedOut)
	{
		time += timer.GetElapsedSeconds();
		if (time < 0.15f)
		{
			if (!lastDir)
			{
				sprite->SetFrame(6);
			}
			else
			{
				sprite->SetFrame(9);
			}
		}
		else if (time < 0.3f)
		{
			if (!lastDir)
			{
				sprite->SetFrame(7);
			}
			else
			{
				sprite->SetFrame(10);
			}
		}
		else if (time < 0.45f)
		{
			if (!lastDir)
			{
				sprite->SetFrame(8);
			}
			else
			{
				sprite->SetFrame(11);
			}
		}
		else if (time > 0.45f)
		{
			time = 0;
		}
		return;
	}




	if (sprite->GetFrame() == 4 && velY == maxVelY)
	{
		sprite->SetFrame(5);

	}
	else if (sprite->GetFrame() == 5 && velY >= -210)
	{
		sprite->SetFrame(4);
	}

	if (sprite->GetFrame() == 0 && velY == maxVelY)
	{
		sprite->SetFrame(1);
	}
	else if (sprite->GetFrame() == 1 && velY >= -210)
	{
		sprite->SetFrame(0);
	}


	if (right)
	{
		sprite->SetFrame(4);
	}
	if (left)
	{
		sprite->SetFrame(0);
	}
}

void PlayerComponent::Move()
{

	const float delta = timer.GetElapsedSeconds();

	if (right && !knockedOut)
	{
		velX += speedX * delta;
		if (velX >= maxVelx)
		{
			velX = maxVelx;
		}
		x += velX * delta;
	}

	if (left && !knockedOut)
	{
		velX -= speedX * delta;
		if (velX >= -maxVelx)
		{
			velX = maxVelx;
		}
		x -= velX * delta;
	}

	velY += gravity * delta;
	y += velY * delta;
}



void PlayerComponent::Knockout(Entity& entity)
{
	knockedOut = true;
	velY = 0;
}




