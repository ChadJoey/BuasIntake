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
		float left = 0;
		float bottom = 0;
		float top = 0;
		float right = 0;

		float prevLeft = 0;
		float prevRight = 0;
		float prevTop = 0;
		float prevBottom = 0;

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
	void Update(Entity& entity) override;


	void Render(Entity& entity, Tmpl8::Surface& screen) override;

	Entity& GetEntity();

	rect box{ 0,0,0,0};
protected:
	Entity& entity;
private:
};

