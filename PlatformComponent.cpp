#include "PlatformComponent.h"

void PlatformComponent::Update(Entity& entity)
{
	if (!entity.isActive)
	{
		return;
	}
}

void PlatformComponent::Init(Entity& entity)
{
	entity.SetActive(false);
}
