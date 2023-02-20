#pragma once

#include <vector>
#include "Entity.h"
#include "PlayerComponent.h"
#include "TransformComponent.h"
#include "ColliderComponent.h"
#include "SpriteComponent.h"
#include "PlatformComponent.h"
#include "Camera.h"
#include "CameraController.h"
#include "game.h"
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

	Game(Game&& copy) = delete;
	Game& operator=(Game&& copy) = delete;

	void SetTarget(Surface* surface) { screen = surface; };
	void Init();
	void Shutdown();
	void Tick( float deltaTime );
	void StartScreenAnim();
	void MouseUp(int button);
	void MouseDown(int button);
	void MouseMove(int x, int y);
	void KeyUp(SDL_Scancode key);
	void KeyDown(SDL_Scancode key);
	int platformAmount = 12;

private:
	Camera* camera = nullptr;
	CameraController* cameraControl = nullptr;
	Surface* screen;
	float platformSpeed = 300;
	std::vector<Entity> entities;
	std::vector<Button> buttons;
	float time = 0;
	

	bool gameStart = false;


	struct UiScreen
	{
		vec2 pos = {0};
	};

	UiScreen startMenu;
	UiScreen endScreen;
};
}; // namespace Tmpl8