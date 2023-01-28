#pragma once

#include <vector>
#include "Entity.h"
#include "CollisionManager.h"
#include "PlayerComponent.h"
#include "TransformComponent.h"
#include "ColliderComponent.h"
#include "SpriteComponent.h"

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
	void MouseUp(int button);
	void MouseDown(int button);
	void MouseMove(int x, int y);
	void KeyUp(SDL_Scancode key);
	void KeyDown(SDL_Scancode key);
private:
	Surface* screen;
	Entity* player = nullptr;
	std::vector<Entity> entities;
};

}; // namespace Tmpl8