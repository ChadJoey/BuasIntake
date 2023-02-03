#include "game.h"
#include "surface.h"
#include "collision.h"
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
		player.GetComponent<ColliderComponent>()->SetOffset(10, 5, 10, -10);


		entities.push_back(std::move(player));

		Entity platform;
		platform.AddComponent(new TransformComponent());
		platform.GetComponent<TransformComponent>()->SetPosition({ 40.f,600.0f });
		platform.AddComponent(new SpriteComponent(new Surface("assets/doodle/space-tiles.png"), 4));
		platform.AddComponent(new ColliderComponent(platform));

		entities.push_back(std::move(platform));

		Entity platform2;
		platform2.AddComponent(new TransformComponent());
		platform2.GetComponent<TransformComponent>()->SetPosition({ 100.f,370.0f });
		platform2.AddComponent(new SpriteComponent(new Surface("assets/doodle/space-tiles.png"), 4));
		platform2.AddComponent(new ColliderComponent(platform2));

		entities.push_back(std::move(platform2));

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

	Sprite mainBackground(new Surface("assets/doodle/space-bck@2x.png"), 1);

	void Game::Tick(float)
	{
		Timer::Get().Tick();
		screen->Clear(0);
		mainBackground.Draw(screen, 0, 0);

		//convert deltaTime to seconds
		for (auto& e : entities)
		{
			e.Update();
		}

		for (auto& e : entities)
		{
			e.Render(*screen);
		}

		float posTest;
		for (int i = 1; i < entities.size(); i++)
		{
			if (collision::OneWayAABB(entities[0].GetComponent<ColliderComponent>(), entities[i].GetComponent<ColliderComponent>()))
			{
				if (entities[0].GetComponent<PlayerComponent>()->velY >= 0)
				{
					entities[0].GetComponent<PlayerComponent>()->flipVelocity();
				}
			}
		}

		if (entities[0].GetComponent<TransformComponent>()->GetPosition().y < 300)
		{
			auto pt = entities[0].GetComponent<PlayerComponent>();
			pt->y = 300;
			for (auto& e : entities)
			{
				auto et = e.GetComponent<TransformComponent>();
				et->SetPosition({ et->GetPosition().x,et->GetPosition().y + platformSpeed * static_cast<float>(Timer::Get().GetElapsedSeconds()) });
			}
		}
	}



};