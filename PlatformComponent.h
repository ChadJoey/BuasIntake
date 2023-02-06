#pragma once
#include <random>
#include "Component.h"
#include "TransformComponent.h"

class PlatformComponent : public Component
{
public:
	PlatformComponent() = default;
	void Update(Entity& entity) override;


	void MovePlatform(Entity& entity, TransformComponent* t)
	{
		std::random_device                  rand_dev;
		std::mt19937                        generator(rand_dev());
		std::uniform_int_distribution<int>  genX(minpos.x, maxpos.x);
		std::uniform_int_distribution<int>  genY(minpos.y, maxpos.y);

		t->SetPosition({ static_cast<float>(genX(generator)), static_cast<float>(-genY(generator))});
	}
	

private:

	Tmpl8::vec2 maxpos = {ScreenWidth - 60,250};
	Tmpl8::vec2 minpos = { 0, 0 };

};

