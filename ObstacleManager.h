#pragma once
#include <vector>
#include "Entity.h"
#include "TransformComponent.h"
#include "Enemy.h"
#include "BreakingPlatform.h"
class ObstacleManager
{


public:
	ObstacleManager(std::vector<Entity>& objectList) :
	ObjectList(objectList)
	{
		
	}


	void MoveObstacle(Entity& entity, Tmpl8::vec2 minpos, Tmpl8::vec2 maxpos);

	void Update();
	void UpdateObjects();

	int ActiveAmount(const std::vector<Entity>& listToCheck);
	bool IncreaseCheck();
	bool DecreaseCheck();
	void SetParameters(int density, float min, float max);
	TransformComponent* lastActiveObject = nullptr;

private:
	int ObjectDensity = 24;
	float maxObjectDist = 50;
	float minObjectDist = 100;
	std::vector<Entity>& ObjectList;
};

