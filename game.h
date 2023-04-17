#pragma once

#include <vector>
#include "Entity.h"
#include "PlayerComponent.h"
#include "TransformComponent.h"
#include "ColliderComponent.h"
#include "SpriteComponent.h"
#include "PlatformComponent.h"
#include "CameraController.h"
#include "BreakingPlatform.h"
#include "ObstacleManager.h"
#include "Enemy.h"
#include "Button.h" 
#include "SDL_scancode.h"


namespace Tmpl8 {

class Surface;
class Game
{
public:
	Game();
	~Game();
	Game(const Game& copy) = delete;
	Game& operator=(const Game& copy) = delete;

	void ResetGame();

	Game(Game&& copy) = delete;
	Game& operator=(Game&& copy) = delete;

	void SetTarget(Surface* surface) { screen = surface; };
	void Init();
	void Shutdown();
	void Tick( float deltaTime );
	void MoveToEndScreen();
	void CheckCollisions();
	void SetPlatforms(bool state);
	void StartScreenAnim();
	void UpdateEntities();
	void RenderEntities();
	void MouseUp(int button);
	void MouseDown(int button);
	void MouseMove(int x, int y);
	void KeyUp(SDL_Scancode key);
	void KeyDown(SDL_Scancode key);

private:
	//storage container for easy switching between generation styles
	struct GenerationData
	{
		int platformDensity;
		float platformMin;
		float platformMax;

		int enemyDensity;
		float enemyMin;
		float enemyMax;

		int brDensity;
		float brMin;
		float brMax;
	};

	Camera* camera = nullptr;
	CameraController* cameraControl = nullptr;
	Surface* screen;
	ObstacleManager* platformMan = nullptr;
	ObstacleManager* enemyMan = nullptr;
	ObstacleManager* breakingPlatMan = nullptr;

	float score = 0;
	int platformAmount = 25;
	int breakingPlatformAmount = 5;
	int enemyAmount = 3;
	float platformSpeed = 300;
	float time = 0;

	Entity player;

	std::vector<Entity> platforms;
	std::vector<Entity> BreakingPlatforms;
	std::vector<Entity> enemies;
	std::vector<Button*> buttons;

	std::vector<GenerationData*> levels;

	bool gameStart = false;
	bool gameActive = false;
	bool gameOver = false;
	bool restart = false;
	bool endGame = false;


	using UiPos = Tmpl8::vec2;

	UiPos startMenu = {0,0};
	UiPos endScreen = { 0,0 };


	int level = 0;

	bool hasLevelChanged = false;

	GenerationData level1{20,50,50, 3, 2000, 1000, 4, 300, 200};
	GenerationData level2{20,130,100, 3,2000,1000, 4, 300, 200};
	GenerationData level3{20,220,200, 3,2000,1000, 4, 1200, 1000};
	GenerationData level4{20,70,50, 3, 2000, 1000, 4, 300, 200};
};
}; // namespace Tmpl8