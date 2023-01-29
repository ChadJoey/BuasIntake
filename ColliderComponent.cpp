#include "ColliderComponent.h"

#include <iostream>

#include "game.h"


float ColliderComponent::top()
{
	auto* t = entity.GetComponent<TransformComponent>();
	return t->GetPosition().y;
}

float ColliderComponent::bottom()
{
	auto* t = entity.GetComponent<TransformComponent>();
	auto* s = entity.GetComponent<SpriteComponent>();
	return t->GetPosition().y + static_cast<float>(s->GetHeight());
}

float ColliderComponent::left()
{
	auto* t = entity.GetComponent<TransformComponent>();
	return t->GetPosition().x;
}

float ColliderComponent::right()
{
	auto* t = entity.GetComponent<TransformComponent>();
	auto* s = entity.GetComponent<SpriteComponent>();
	return t->GetPosition().x + static_cast<float>(s->GetWidth());
}

void ColliderComponent::Init(Entity& entity)
{

}

bool ColliderComponent::Collision(Entity& entityA, Entity& entityB)
{
	auto* colA = entityA.GetComponent<ColliderComponent>();
	auto* colB =  entityB.GetComponent<ColliderComponent>();

	const Tmpl8::vec2 min1 = { colA->left(), colA->top() };
	const Tmpl8::vec2 max1 = { colA->right(), colA->bottom() };

	const Tmpl8::vec2 min2 = { colB->left(), colB->top() };
	const Tmpl8::vec2 max2 = { colB->right(), colB->bottom() };

	return !(max1.x < min2.x || min1.x > max2.x || max1.y < min2.y || min1.y > max2.y);
}


void ColliderComponent::Update(Entity& entity)
{

}

void ColliderComponent::Render(Entity& entity, Tmpl8::Surface& screen)
{
	auto* transform = entity.GetComponent<TransformComponent>();
	auto* sprite = entity.GetComponent<SpriteComponent>();
	screen.Box(transform->GetPosition().x, transform->GetPosition().y, transform->GetPosition().x + sprite->GetWidth(), transform->GetPosition().y + sprite->GetHeight(), 0xff);
}
