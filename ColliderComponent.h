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

	struct rect
	{
		float left;
		float bottom;
		float top;
		float right;

		float leftOffset = 0;
		float bottomOffset = 0;
		float topOffset = 0;
		float rightOffset = 0;

		float vx = 0;
		float vy = 0;
	};

	void SetOffset(float leftOffset, float bottomOffset, float topOffset, float rightOffset);

	void Init(Entity& entity) override;

	void SetVelocity(float vx, float vy);

	//update the component
	auto Update(Entity& entity) -> void override;


	void Render(Entity& entity, Tmpl8::Surface& screen) override;

	Entity& GetEntity();

	rect box{ 0,0,0,0};
protected:
	Entity& entity;
private:


};

