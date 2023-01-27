#pragma once
#include "ColliderComponent.h"
#include "template.h"

class CollisionManager
{
public:
	CollisionManager() = default;


	std::vector<ColliderComponent::rect> vRects;


	bool DynamicRectVsRect(const ColliderComponent::rect& in, const ColliderComponent::rect& target, Tmpl8::vec2& contact_point, Tmpl8::vec2& contact_normal, float& contact_time, float elapsed_time);


	bool RayVsRect(const Tmpl8::vec2& ray_origin, const Tmpl8::vec2& ray_dir, const ColliderComponent::rect& target, Tmpl8::vec2& contact_point, Tmpl8::vec2& contact_normal, float& t_hit_near);

	void GetCollisionData(ColliderComponent::rect r);


	void Update();

private:

};

