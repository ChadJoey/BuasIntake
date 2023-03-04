#include "PlatformComponent.h"

void PlatformComponent::Update(Entity& entity)
{
	if (!entity.isActive)
	{
		return;
	}

	auto* t = entity.GetComponent<TransformComponent>();
	if (t->GetPosition().y > ScreenHeight)
	{
		MovePlatform(entity, t);
	}
}

void PlatformComponent::Init(Entity& entity)
{
	entity.SetActive(false);
}
