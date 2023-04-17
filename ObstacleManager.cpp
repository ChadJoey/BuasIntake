#include "ObstacleManager.h"

#include <iostream>
#include <random>



void ObstacleManager::MoveObstacle(Entity& entity, Tmpl8::vec2 minpos, Tmpl8::vec2 maxpos)
{
	if (DecreaseCheck())
	{
		entity.SetActive(false);
		return;
	}

	auto* t = entity.GetComponent<TransformComponent>();
	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	std::uniform_int_distribution<int>  genX(minpos.x, maxpos.x);
	std::uniform_int_distribution<int>  genY(minpos.y, maxpos.y);
	float y = static_cast<float>(genY(generator));
	if (entity.GetComponent<BreakingPlatform>())
	{
		if (y >= 0)
		{
			y = -50;
		}
	}
	t->SetScreenPosition({ static_cast<float>(genX(generator)), y });
	lastActiveObject = entity.GetComponent<TransformComponent>();
}

void ObstacleManager::Update()
{
	UpdateObjects();
}



void ObstacleManager::UpdateObjects()
{
	if (lastActiveObject == nullptr)
	{
		lastActiveObject = ObjectList[0].GetComponent<TransformComponent>();
	}


	for (auto& p : ObjectList)
	{
		//make sure to only check for active ObjectList

		if (ObjectDensity == 0)
		{
			return;
		}

		if (!p.isActive)
		{
			continue;
		}



		auto* t = p.GetComponent<TransformComponent>();

		if (t->GetPosition().y >= ScreenHeight)
		{
			if (p.GetComponent<BreakingPlatform>())
			{
				p.GetComponent<BreakingPlatform>()->Reset();
			}

			MoveObstacle(p, { 0,lastActiveObject->GetScreenPos().y - minObjectDist }, { ScreenWidth - 60 ,lastActiveObject->GetScreenPos().y - maxObjectDist });
		}
		if (p.GetComponent<Enemy>() && p.GetComponent<Enemy>()->hit)
		{
			MoveObstacle(p, { 0,lastActiveObject->GetScreenPos().y - minObjectDist }, { ScreenWidth - 60 ,lastActiveObject->GetScreenPos().y - maxObjectDist });
			p.GetComponent<Enemy>()->hit = false;
		}
	}


	if (IncreaseCheck())
	{
		const int activeAmount = ActiveAmount(ObjectList);
		for (size_t i = activeAmount; i <= ObjectDensity - 1; i++)
		{
			ObjectList[i].SetActive(true);
			auto* t = ObjectList[i].GetComponent<TransformComponent>();
			MoveObstacle(ObjectList[i], { 0,lastActiveObject->GetScreenPos().y - minObjectDist }, { ScreenWidth - 60 ,lastActiveObject->GetScreenPos().y - maxObjectDist });
		}
	}
}




int ObstacleManager::ActiveAmount(const std::vector<Entity>& listToCheck)
{
	int activeAmount = 0;
	for (auto& e : listToCheck)
	{
		if (e.isActive)
		{
			activeAmount++;
		}
	}
	return activeAmount;
}

bool ObstacleManager::IncreaseCheck()
{
	const int activeAmount = ActiveAmount(ObjectList);
	if (activeAmount <= ObjectDensity)
	{
		return true;
	}
	return false;
}

bool ObstacleManager::DecreaseCheck()
{
	const int activeAmount = ActiveAmount(ObjectList);
	if (activeAmount > ObjectDensity)
	{
		return true;
	}
	return false;
}

void ObstacleManager::SetParameters(int density, float min, float max)
{
	ObjectDensity = density;
	maxObjectDist = max;
	minObjectDist = min;
}




