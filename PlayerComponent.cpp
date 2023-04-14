#include "PlayerComponent.h"

#include <iostream>

#include "template.h"



PlayerComponent::PlayerComponent() :
 timer(Timer::Get())
{
}


void PlayerComponent::Update(Entity& entity)
{
	if (!entity.isActive)
	{
		return;
	}

	auto* col = entity.GetComponent<ColliderComponent>();
	auto* t = entity.GetComponent<TransformComponent>();
	col->box.prevRight = col->box.right;
	col->box.prevBottom = col->box.bottom;
	col->box.prevLeft = col->box.left;
	col->box.prevTop = col->box.top;

	if (t->GetPosition().y <= t->cam->GetTop() && velY < 0)
	{
		t->cam->MoveCam(velY);
	}

	if (t->GetPosition().y >= ScreenHeight)
	{
		t->cam->MoveCam(velY);
	}


	visuals(entity);
	Move();
	Wrap(entity);


	t->SetScreenPosition({ x, y });
	col->Update(entity);
}

void PlayerComponent::Wrap(Entity& entity)
{
	auto* pc = entity.GetComponent<ColliderComponent>();
	if (pc->box.right <= -1000)
	{
		return;
	}

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


	auto* transform = entity.GetComponent<TransformComponent>();
	auto* sprite = entity.GetComponent<SpriteComponent>();
	switch (key)
	{
	case SDL_SCANCODE_D:
	case SDL_SCANCODE_RIGHT:
		left = false;
		right = true;
		facingRight = true;
		break;
	case SDL_SCANCODE_A:
	case SDL_SCANCODE_LEFT:
		right = false;
		left = true;
		facingRight = false;
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
	auto* sprite = entity.GetComponent<SpriteComponent>();

	if (knockedOut)
	{
		time += timer.GetElapsedSeconds();
		if (time > timeIncrement)
		{
			// help from erik making this a lot cleaner rather then using a bunch of else if statements
			sprite->SetFrame(knockoutFrame + (facingRight? 9 : 6 ));
			knockoutFrame = ++knockoutFrame % 3;
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



void PlayerComponent::Knockout()
{
	knockedOut = true;
	velY = 0;
}




