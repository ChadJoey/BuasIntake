#pragma once
#include "Component.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "CollisionManager.h"
class ColliderComponent : public Component
{
public:
	ColliderComponent(const CollisionManager& cm) :
	cm(cm)
	{}

	CollisionManager::rect r = {id, {0.0f, 0.0f},{0.0f, 0.0f},{0.0f, 0.0f} };


	void Init(Entity& entity) override;

	void GenerateCollisionData(Entity& entity, CollisionManager* cm);


	//update the component
	void Update(Entity& entity) override;


	void Render(Entity& entity, Tmpl8::Surface& screen) override;


	

protected:
private:
	int id;
	//Tmpl8::vec2 pos;
	//Tmpl8::vec2 size;

	CollisionManager cm;
};

