#pragma once
#include <vector>
#include "Entity.h"
#include "TransformComponent.h"
#include "CameraController.h"
class ObstacleManager
{


public:
	ObstacleManager(std::vector<Entity>& platforms ,std::vector<Entity>& breakingPlats ,std::vector<Entity>& enemies, CameraController& cam) :
	platforms(platforms),
	breakingPlats(breakingPlats),
	enemies(enemies),
	cam(cam)
	{
		
	}


	void MoveObstacle(Entity& entity, Tmpl8::vec2 minpos, Tmpl8::vec2 maxpos);

	void Update();
	void UpdatePlatForms();

	int ActiveAmount(const std::vector<Entity>& listToCheck);


	bool IncreaseCheck();
	bool DecreaseCheck();
	int platformDensity = 24;
	float maxPlatformDist = 50;
	float minPlatformDist = 100;

private:
	std::vector<Entity>& platforms;
	std::vector<Entity>& breakingPlats;
	std::vector<Entity>& enemies;

	CameraController& cam;

	TransformComponent* lastActivePlatform = nullptr;
	//TransformComponent* lastActitiveBreakingPlat = nullptr;

	int breakingPlatDensity = 1;
	int enemyDensity = 0;
};

