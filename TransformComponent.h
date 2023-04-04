#pragma once
#include "template.h"
#include "Component.h"
#include "CameraController.h"
#include "PlayerComponent.h"

class TransformComponent : public Component
{
public:
	TransformComponent(CameraController* cam) :
	cam(cam)
	{
		
	};

	void SetPosition(const Tmpl8::vec2& position)
	{
		this->position = position + cam->GetPos();
	}

	void AddPosition(const Tmpl8::vec2 position)
	{
		this->position += position;
	}

	Tmpl8::vec2 GetPosition() const
	{
		return position + cam->GetPos();
	}


	CameraController* cam;
private:
	Tmpl8::vec2 position;
};

