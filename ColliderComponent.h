#pragma once
#include "Component.h"
#include "TransformComponent.h"
#include "CollisionManager.h"
class ColliderComponent : public Component
{
public:
	ColliderComponent(CollisionManager* cm);
	struct rect
	{
		int ID;
		Tmpl8::vec2 pos;
		Tmpl8::vec2 size;
		Tmpl8::vec2 velocity;
	};
	rect r;

	void GenerateCollisionData();


	//update the component
	void Update(Entity& entity) override;


	void Render(Entity& entity, Tmpl8::Surface& screen) override;


	

protected:
private:
};

