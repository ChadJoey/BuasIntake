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
	t->SetScreenPosition({ static_cast<float>(genX(generator)), static_cast<float>(genY(generator)) });
	std::cout << t->GetScreenPos().y << std::endl;
	lastActivePlatform = entity.GetComponent<TransformComponent>();
}

void ObstacleManager::Update()
{
	UpdatePlatForms();
}



void ObstacleManager::UpdatePlatForms()
{
	if (lastActivePlatform == nullptr)
	{
		lastActivePlatform = platforms[0].GetComponent<TransformComponent>();
	}


	for (auto& p : platforms)
	{
		//make sure to only check for active platforms
		if (!p.isActive)
		{
			continue;
		}

		auto* t = p.GetComponent<TransformComponent>();

		//std::cout << ScreenHeight << std::endl;


		if (t->GetPosition().y >= ScreenHeight)
		{
			std::cout << t->GetScreenPos().y << std::endl;
			std::cout << t->cam->GetPos().y << std::endl;
			MoveObstacle(p, { 0,lastActivePlatform->GetScreenPos().y - minPlatformDist }, { ScreenWidth - 60 ,lastActivePlatform->GetScreenPos().y - maxPlatformDist });
		}
	}


	if (IncreaseCheck())
	{
		const int activeAmount = ActiveAmount(platforms);
		for (size_t i = activeAmount; i <= platformDensity - 1; i++)
		{
			platforms[i].SetActive(true);
			auto* t = platforms[i].GetComponent<TransformComponent>();
			MoveObstacle(platforms[i], { 0,lastActivePlatform->GetScreenPos().y - minPlatformDist }, { ScreenWidth - 60 ,lastActivePlatform->GetScreenPos().y - maxPlatformDist });
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
	const int activeAmount = ActiveAmount(platforms);
	if (activeAmount <= platformDensity)
	{
		return true;
	}
	return false;
}

bool ObstacleManager::DecreaseCheck()
{
	const int activeAmount = ActiveAmount(platforms);
	if (activeAmount > platformDensity)
	{
		return true;
	}
	return false;
}




