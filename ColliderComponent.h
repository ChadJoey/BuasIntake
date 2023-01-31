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
	};



	void Init(Entity& entity) override;


	bool Collision(Entity& entityA, Entity& entityB);


	//update the component
	void Update(Entity& entity) override;


	void Render(Entity& entity, Tmpl8::Surface& screen) override;



	rect box{ 0,0,0,0};
protected:
private:

	Entity& entity;


};

