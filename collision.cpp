#include "collision.h"

//source
//https://www.gamedev.net/tutorials/programming/general-and-gameplay-programming/swept-aabb-collision-detection-and-response-r3084/

void collision::CheckCol(Entity& player, Entity& object)
{
	if (!object.isActive)
	{
		return;
	}
	
	auto rectA = player.GetComponent<ColliderComponent>()->box;
	auto rectB = object.GetComponent<ColliderComponent>()->box;
	if (rectA.bottom >= rectB.top && rectA.top <= rectB.bottom && rectA.left <= rectB.right && rectA.right >= rectB.left)
	{
		CheckSides(player, object);
	}
}


void collision::CheckSides(Entity& player, Entity& object)
{
	auto rectA = player.GetComponent<ColliderComponent>()->box;
	auto rectB = object.GetComponent<ColliderComponent>()->box;
	auto p = player.GetComponent<PlayerComponent>();


	if (rectA.prevBottom < rectB.top && rectA.bottom >= rectB.top)
	{

		if (object.GetComponent<BreakingPlatform>())
		{
			object.GetComponent<BreakingPlatform>()->playAnim = true;
			return;
		}



		//collision at the bottom of the player
		if (!object.GetComponent<BreakingPlatform>() && p->velY > 0)
		{
			auto* t = player.GetComponent<TransformComponent>();
			auto* ot = object.GetComponent<TransformComponent>();
			t->SetScreenPosition({ t->GetScreenPos().x, ot->GetScreenPos().y});
			p->flipVelocity();

			if (object.GetComponent<Enemy>())
			{
				object.GetComponent<Enemy>()->hit = true;
			}
			return;
		}
	}




	if (!object.GetComponent<Enemy>())
	{
		
	}
	else if(!object.GetComponent<Enemy>()->hit)
	{
		p->Knockout();
	}

}


