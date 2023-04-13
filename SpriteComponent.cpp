#include "SpriteComponent.h"


 void SpriteComponent::Update(Entity& entity)
 {
 }



 void SpriteComponent::Render(Entity& entity, Tmpl8::Surface& screen)
 {
	 if (!entity.isActive)
	 {
		 return;
	 }
 	const auto transform = entity.GetComponent<TransformComponent>();
 	RenderObject renderObject(transform->GetPosition(), sprite, &screen);
 	sprite.Draw(renderObject.dst, static_cast<int>(renderObject.pos.x),
 	static_cast<int>(renderObject.pos.y));
 }


void SpriteComponent::SetFrame(unsigned a_Index)
{
	sprite.SetFrame(a_Index);
}

int SpriteComponent::GetWidth()
{
	return sprite.GetWidth();
}


int SpriteComponent::GetHeight()
{
	return sprite.GetHeight();
}

Pixel* SpriteComponent::GetBuffer()
{
	return sprite.GetBuffer();
}


