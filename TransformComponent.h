#pragma once
#include "template.h"
#include "Component.h"
#include "PlayerComponent.h"

class TransformComponent : public Component
{
public:
	TransformComponent() = default;

	static const std::string& ID()
	{
		static std::string id = "TransformComponent";
		return id;
	}

	virtual const std::string& GetID()
	{
		return ID();
	}

	virtual void Update(Entity& entity) override;

	void SetPosition(const Tmpl8::vec2& position)
	{
		this->position = position;
	}

	void AddPosition(const Tmpl8::vec2 position)
	{
		this->position += position;
	}

	Tmpl8::vec2 GetPosition() const
	{
		return position;
	}
	
private:

	Tmpl8::vec2 position;
};
