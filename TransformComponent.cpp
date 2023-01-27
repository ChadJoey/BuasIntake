#include "TransformComponent.h"
#include "Entity.h"
#include "PlayerComponent.h"

void TransformComponent::Update(Entity& entity)
{
	PlayerComponent* pc = entity.GetComponent<PlayerComponent>();
	if (pc)
	{
		pc->Update(entity);
	}

	auto playerComponents = entity.GetComponents<PlayerComponent>();
	for (auto pc : playerComponents)
	{
		pc->Update(entity);
	}
}


