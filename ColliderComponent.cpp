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


	box.height = t->GetPosition().y + s->GetHeight();
	box.width = t->GetPosition().x + s->GetWidth();
	box.posX = t->GetPosition().x;
	box.posY = t->GetPosition().y;
}

void ColliderComponent::Render(Entity& entity, Tmpl8::Surface& screen)
{
	auto* transform = entity.GetComponent<TransformComponent>();
	auto* sprite = entity.GetComponent<SpriteComponent>();
	screen.Box(transform->GetPosition().x, transform->GetPosition().y, transform->GetPosition().x + sprite->GetWidth(), transform->GetPosition().y + sprite->GetHeight(), 0xff);
}
