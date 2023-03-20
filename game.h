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
	Camera* camera = nullptr;
	CameraController* cameraControl = nullptr;
	Surface* screen;
	ObstacleManager* obMan = nullptr;

	float score = 0;
	int platformAmount = 25;
	float platformSpeed = 300;
	float time = 0;

	Entity player;

	std::vector<Entity> platforms;
	std::vector<Entity> BreakingPlatforms;
	std::vector<Entity> enemies;
	std::vector<Button*> buttons;

	bool gameStart = false;
	bool gameActive = false;
	bool gameOver = false;
	bool restart = false;
	bool endGame = false;


	using UiPos = Tmpl8::vec2;

	UiPos startMenu = {0,0};
	UiPos endScreen = { 0,0 };
};
}; // namespace Tmpl8