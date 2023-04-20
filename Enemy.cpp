#include "Enemy.h"

void Enemy::Update(Entity& entity)
{
	if (!entity.isActive)
	{
		return;
	}

	time += Timer::Get().GetElapsedSeconds();

	auto* s = entity.GetComponent<SpriteComponent>();

	if (time < 0.03f)
	{
		s->SetFrame(0);
	}
	else if (time < 0.06f)
	{
		s->SetFrame(1);
	}
	else if (time < 0.09f)
	{
		s->SetFrame(2);
	}
	else if (time < 0.12f)
	{
		s->SetFrame(3);
	}
	else if(time > 0.12f)
	{
		time = 0;
	}

}
