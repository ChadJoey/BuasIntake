#include "game.h"
#include "surface.h"

#include "Timer.h";
#include <iostream>

#include <cstdio> //printf


/* credit: https://www.youtube.com/watch?v=gKQd1qPQHgs&list=PLZHgukYvDo9cUYfUZZ6mtCrPnuX_4hRRl&index=8*/

namespace Tmpl8
{

	Game::Game()
	{
		Entity player;
		player.AddComponent(new TransformComponent());
		player.AddComponent(new PlayerComponent);
		player.AddComponent(new SpriteComponent(new Surface("assets/doodle/space-doodles.png"), 10));
		player.AddComponent(new ColliderComponent(player));

		entities.push_back(std::move(player));

		Entity platform;
		platform.AddComponent(new TransformComponent());
		platform.GetComponent<TransformComponent>()->SetPosition({ 40.f,600.0f });
		platform.AddComponent(new SpriteComponent(new Surface("assets/doodle/space-tiles.png"),4));
		platform.AddComponent(new ColliderComponent(platform));

		entities.push_back(std::move(platform));
	}


	void Game::Init()
	{

		for (auto& e : entities)
		{
			e.Init();
		}

	}
	
	void Game::Shutdown()
	{
	}


	

	void Game::MouseUp(int button)
	{
		for (auto& e : entities)
		{
			e.MouseUp(button);
		}
	}

	void Game::MouseDown(int button)
	{
		for (auto& e : entities)
		{
			e.MouseDown(button);
		}
	}

	void Game::MouseMove(int x, int y)
	{
		for (auto& e : entities)
		{
			e.MouseMove(x, y);
		}
	}

	void Game::KeyDown(SDL_Scancode key)
	{

		for (auto& e : entities)
		{
			e.KeyDown(key);
		}
	}

	void Game::KeyUp(SDL_Scancode key)
	{
		for (auto& e : entities)
		{
			e.KeyUp(key);
		}
	}

	void Game::Tick(float)
	{
		Timer::Get().Tick();
		screen->Clear(0);

		//screen->Line(0, 10, 800, 10, 0xff);

		//convert deltaTime to seconds
		for (auto& e : entities)
		{
			e.Update();

			
		}

		for (auto& e : entities)
		{
			e.Render(*screen);
		}




	}
};