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

	//moves objects to a random position between set parameters
	void MoveObstacle(Entity& entity, Tmpl8::vec2 minpos, Tmpl8::vec2 maxpos);

	void Update();

	//checks if an object needs to get added or moved
	void UpdateObjects();

	//returns the amount of active objects in the vector
	int ActiveAmount(const std::vector<Entity>& listToCheck);

	//checks if there are less object active then needed
	bool IncreaseCheck();
	//checks if there are more objects active then needed
	bool DecreaseCheck();

	//sets parameters for object spawning
	void SetParameters(int density, float min, float max);
	TransformComponent* lastActiveObject = nullptr;

private:
	int ObjectDensity = 24;
	float maxObjectDist = 50;
	float minObjectDist = 100;
	std::vector<Entity>& ObjectList;
};

