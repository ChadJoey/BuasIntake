#include "ColliderComponent.h"

#include <iostream>

#include "game.h"


void ColliderComponent::SetOffset(float leftOffset, float bottomOffset, float topOffset, float rightOffset)
{
	box.leftOffset = leftOffset;
	box.bottomOffset = bottomOffset;
	box.topOffset = topOffset;
	box.rightOffset = rightOffset;
}

void ColliderComponent::Init(Entity& entity)
{

}




void ColliderComponent::Update(Entity& entity)
{
	auto* t = entity.GetComponent<TransformComponent>();
	auto* s = entity.GetComponent<SpriteComponent>();


	box.right = (t->GetPosition().x + s->GetWidth()) + box.rightOffset;
	box.left = t->GetPosition().x + box.leftOffset;
	box.bottom = (t->GetPosition().y + s->GetHeight()) + box.bottomOffset;
	box.top = t->GetPosition().y + box.topOffset;
}

void ColliderComponent::Render(Entity& entity, Tmpl8::Surface& screen)
{
	auto* transform = entity.GetComponent<TransformComponent>();
	auto* sprite = entity.GetComponent<SpriteComponent>();
	screen.Box(box.left, box.top,box.right,box.bottom, 0xff);
}

Entity& ColliderComponent::GetEntity()
{
	return entity;
}
