#pragma once
#include "Component.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "sounds.h"

class Enemy : public Component
{
public:
	Enemy(sounds* sound) :
	sound(sound)
	{}
	//updates enemies animations
	void Update(Entity& entity) override;
	bool hit = false;
	sounds* sound;
private:
	float time = 0;

};

