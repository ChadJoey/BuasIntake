#pragma once
#include <random>
#include "TransformComponent.h"

class PlatformComponent : public Component
{
public:
	PlatformComponent() = default;
	void Update(Entity& entity) override;

	void Init(Entity& entity) override;

	virtual void MovePlatform(Entity& entity, TransformComponent* t)
	{
		std::random_device                  rand_dev;
		std::mt19937                        generator(rand_dev());
		std::uniform_int_distribution<int>  genX(minpos.x, maxpos.x);
		std::uniform_int_distribution<int>  genY(minpos.y, maxpos.y);

		t->SetPosition({ static_cast<float>(genX(generator)), static_cast<float>(-genY(generator))});
	}
protected:
	Tmpl8::vec2 maxpos = { ScreenWidth - 60,80 };
	Tmpl8::vec2 minpos = { 0, 0 };
};

