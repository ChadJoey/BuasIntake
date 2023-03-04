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

	int platformAmount = 12;
	float platformSpeed = 300;
	float time = 0;

	Entity player;

	std::vector<Entity> platforms;
	std::vector<Entity> BreakingPlatforms;
	std::vector<Entity> enemies;
	std::vector<Button*> buttons;
	
	Tmpl8::vec2 startingPos[12]{{40.0f, 650.0f },
			{120.0f, 500.0f} ,{400.0f, 480.0f}
			,{250.0f, 200.0f} ,{350.0f, 350.0f}
			,{600.0f, 150.0f} ,{550.0f, 700.0f},
		{470.0f, 200.0f} ,{320, 00.0f} ,
		{-100.0f, 0.0f} ,{-200.0f, 350.0f} ,{-400.0f, 350.0f}
	};

	bool gameStart = false;
	bool gameOver = false;
	bool restart = false;
	bool endGame = false;


	using UiPos = Tmpl8::vec2;

	UiPos startMenu = {0,0};
	UiPos endScreen = { 0,0 };
};
}; // namespace Tmpl8