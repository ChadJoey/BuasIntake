#include "ColliderComponent.h"

#include <iostream>

#include "game.h"


void ColliderComponent::Init(Entity& entity)
{

}




void ColliderComponent::Update(Entity& entity)
{
	auto* t = entity.GetComponent<TransformComponent>();
	auto* s = entity.GetComponent<SpriteComponent>();


	box.bottom = t->GetPosition().y + s->GetHeight();
	box.right = t->GetPosition().x + s->GetWidth();
	box.left = t->GetPosition().x;
	box.top = t->GetPosition().y;
}

void ColliderComponent::Render(Entity& entity, Tmpl8::Surface& screen)
{
	auto* transform = entity.GetComponent<TransformComponent>();
	auto* sprite = entity.GetComponent<SpriteComponent>();
	screen.Box(box.left, box.top,box.right,box.bottom, 0xff);
}
