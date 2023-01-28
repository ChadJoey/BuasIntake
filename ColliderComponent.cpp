#include "ColliderComponent.h"

#include "game.h"


void ColliderComponent::Init(Entity& entity)
{
	auto* transform = entity.GetComponent<TransformComponent>();
	auto* sprite = entity.GetComponent<SpriteComponent>();
	GenerateCollisionData(entity, &cm);
}

void ColliderComponent::GenerateCollisionData(Entity& entity, CollisionManager* cm)
{
	auto* transform = entity.GetComponent<TransformComponent>();
	auto* sprite = entity.GetComponent<SpriteComponent>();
	cm->vRects.push_back(r);
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
