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
		Init(entity);
	}

	//holds collision data for individual entities
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
	};

	//sets offset to the collision box
	void SetOffset(float leftOffset, float bottomOffset, float topOffset, float rightOffset);

	//initializes entities collision data
	void Init(Entity& entity) override;


	//update the component
	void Update(Entity& entity) override;

	//shows collision bounds when in debug mode
	void Render(Entity& entity, Tmpl8::Surface& screen) override;

	//return its entity owner
	Entity& GetEntity();

	rect box{ 0,0,0,0};
protected:
	Entity& entity;
private:
};

