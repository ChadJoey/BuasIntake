#pragma once
#include "Component.h"
#include "TransformComponent.h"
class ColliderComponent : public Component
{
public:
	ColliderComponent();
	struct rect
	{
		int ID;
		Tmpl8::vec2 pos;
		Tmpl8::vec2 size;
		Tmpl8::vec2 velocity;
	};
	rect r;
	virtual void Init(Entity& entity) override;


	//update the component
	virtual void Update(Entity& entity) override;
	

	virtual void Render(Entity& entity, Tmpl8::Surface& screen) override;


	

protected:
private:
};

