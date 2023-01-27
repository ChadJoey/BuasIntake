#include "CollisionManager.h"


bool CollisionManager::DynamicRectVsRect(const ColliderComponent::rect& in, const ColliderComponent::rect& target,
	Tmpl8::vec2& contact_point, Tmpl8::vec2& contact_normal, float& contact_time, float elapsed_time)
{
	if (in.velocity.x == 0 && in.velocity.y == 0)
	{
		return false;
	}

	ColliderComponent::rect expanded_target;
	expanded_target.pos.x = target.pos.x - in.size.x / 2;
	expanded_target.pos.y = target.pos.y - in.size.y / 2;
	expanded_target.size.x = target.size.x + in.size.x;
	expanded_target.size.y = target.size.y + in.size.y;


	if (RayVsRect({ in.pos.x + in.size.x / 2,in.pos.y + in.size.y / 2 }, in.velocity * elapsed_time, expanded_target, contact_point, contact_normal, contact_time))
	{
		if (contact_time <= 1.0f)
		{
			return true;
		}

	}
	return false;
}

bool CollisionManager::RayVsRect(const Tmpl8::vec2& ray_origin, const Tmpl8::vec2& ray_dir,
                                 const ColliderComponent::rect& target, Tmpl8::vec2& contact_point, Tmpl8::vec2& contact_normal, float& t_hit_near)
{
	Tmpl8::vec2 t_near((target.pos.x - ray_origin.x) / ray_dir.x, (target.pos.y - ray_origin.y) / ray_dir.y);
	Tmpl8::vec2 t_far((target.pos.x + target.size.x - ray_origin.x) / ray_dir.x, (target.pos.y + target.size.y - ray_origin.y) / ray_dir.y);

	if (t_near.x > t_far.x)
	{
		std::swap(t_near.x, t_far.x);
	}

	if (t_near.y > t_far.y)
	{
		std::swap(t_near.y, t_far.y);
	}

	if (t_near.x > t_far.y || t_near.y > t_far.x)
	{
		return false;
	}

	t_hit_near = std::max(t_near.x, t_near.y);
	float t_hit_far = std::min(t_far.x, t_far.y);

	if (t_hit_far < 0)
	{
		return false;
	}

	contact_point.x = (ray_origin.x + t_hit_near * ray_dir.x);
	contact_point.y = (ray_origin.y + t_hit_near * ray_dir.y);

	if (t_near.x > t_near.y)
	{
		if (ray_dir.x < 0)
		{
			contact_normal = { 1,0 };
		}
		else
		{
			contact_normal = { -1,0 };
		}
	}
	else if (t_near.x < t_near.y)
	{
		if (ray_dir.y < 0)
		{
			contact_normal = { 0,1 };
		}
		else
		{
			contact_normal = { 0,-1 };
		}
	}

	return true;

}

void CollisionManager::GetCollisionData(ColliderComponent::rect r)
{
	vRects.push_back(r);
}

void CollisionManager::Update()
{
	Tmpl8::vec2 cp, cn;
	float t;

}


