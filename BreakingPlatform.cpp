#include "BreakingPlatform.h"

void BreakingPlatform::Update(Entity& entity)
{
	if (!entity.isActive)
	{
		return;
	}

	auto* t = entity.GetComponent<TransformComponent>();
	auto* s = entity.GetComponent<SpriteComponent>();

	if (t->GetPosition().y > ScreenHeight)
	{
		playAnim = false;
		time = 0;
		s->SetFrame(2);
		MovePlatform(entity, t);
	}

	if (playAnim)
	{
		t->AddPosition({0, velY * static_cast<float>(Timer::Get().GetElapsedSeconds())});
		time += Timer::Get().GetElapsedSeconds();
		if (time < 0.2f)
		{
			s->SetFrame(1);
		}
		else if (time < 0.4f)
		{
			s->SetFrame(2);
		}
	}
	else
	{
		s->SetFrame(0);
	}


}


void BreakingPlatform::Reset()
{
	playAnim = false;
	time = 0;
}
