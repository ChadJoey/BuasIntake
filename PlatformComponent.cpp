#include "PlatformComponent.h"

void PlatformComponent::Update(Entity& entity)
{
	auto* t = entity.GetComponent<TransformComponent>();
	if (t->GetPosition().y > ScreenHeight)
	{
		MovePlatform(entity, t);
	}
}
