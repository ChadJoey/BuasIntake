#pragma once

#include "Component.h"
#include "Entity.h"
#include "surface.h"
#include "template.h"
#include "TransformComponent.h"



typedef unsigned int Pixel;


struct RenderObject
{
	/* huge thanks to cynic for showing his implementation for refference
	 * https://github.com/Cynic1254/Game
	 */

	RenderObject(float x, float y, Tmpl8::Sprite& sprite, Tmpl8::Surface* screen) :
		pos(x, y),
		sprite(sprite),
		dst(screen)
	{}

	RenderObject(Tmpl8::vec2 pos, Tmpl8::Sprite& sprite, Tmpl8::Surface* screen) :
		pos(pos),
		sprite(sprite),
		dst(screen)
	{}

	Tmpl8::vec2 pos;
	Tmpl8::Sprite& sprite;
	Tmpl8::Surface* dst;
};




class SpriteComponent : public Component
{
public:
	SpriteComponent(Tmpl8::Surface* surface, int numFrames) :
	sprite(surface, numFrames)
	{}




	static const std::string& ID()
	{
		static std::string id = "SpriteComponent";
		return id;
	}

	virtual const std::string& GetID()
	{
		return ID();
	}

	virtual void Update(Entity& entity) override;

	void Render(Entity& entity, Tmpl8::Surface& screen) override;



	void SetFrame(unsigned int a_Index);

	int GetWidth();

	int GetHeight();

	Pixel* GetBuffer();

protected:
private:
	Tmpl8::Sprite sprite;
};
