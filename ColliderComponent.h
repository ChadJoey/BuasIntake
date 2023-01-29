#pragma once
#include "Component.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
class ColliderComponent : public Component
{
public:
	ColliderComponent(Entity& entity) :
	entity(entity)
	{
	}

	float top();
	float bottom();
	float left();
	float right();

	void Init(Entity& entity) override;


	bool Collision(Entity& entityA, Entity& entityB);


	//update the component
	void Update(Entity& entity) override;


	void Render(Entity& entity, Tmpl8::Surface& screen) override;


	

protected:
private:

	Entity& entity;

};

