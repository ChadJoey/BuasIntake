#pragma once
#include "vector"
#include "template.h"

class CollisionManager
{
public:
	CollisionManager() = default;

	struct rect
	{
		int ID;
		Tmpl8::vec2 pos;
		Tmpl8::vec2 size;

		Tmpl8::vec2 velocity;
	};

	std::vector<rect> vRects;


	bool DynamicRectVsRect(const rect& in, const rect& target, Tmpl8::vec2& contact_point, Tmpl8::vec2& contact_normal, float& contact_time, float elapsed_time);


	bool RayVsRect(const Tmpl8::vec2& ray_origin, const Tmpl8::vec2& ray_dir, const rect& target, Tmpl8::vec2& contact_point, Tmpl8::vec2& contact_normal, float& t_hit_near);


	void Update();

private:

};

