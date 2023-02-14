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
		camera = new Camera();
		cameraControl = new CameraController(camera);


		Entity player;
		player.AddComponent(new TransformComponent());
		player.AddComponent(new PlayerComponent);
		player.AddComponent(new SpriteComponent(new Surface("assets/doodle/space-doodles.png"), 10));
		player.AddComponent(new ColliderComponent(player));
		player.GetComponent<ColliderComponent>()->SetOffset(10, 5, 10, -10);
		entities.push_back(std::move(player));


		vec2 startingPos[12] = { {40.0f, 650.0f},
			{120.0f, 500.0f} ,{400.0f, 480.0f}
			,{250.0f, 200.0f} ,{350.0f, 350.0f}
			,{600.0f, 150.0f} ,{550.0f, 700.0f},
		{470.0f, 200.0f} ,{320, 00.0f} ,
		{-100.0f, 0.0f} ,{-200.0f, 350.0f} ,{-400.0f, 350.0f} };

		vec2 storagePos{-100, -100 };

		for (size_t i = 0; i < platformAmount; i++)
		{
			Entity platform;
			platform.AddComponent(new TransformComponent());
			platform.GetComponent<TransformComponent>()->SetPosition({ startingPos[i] });
			platform.AddComponent(new SpriteComponent(new Surface("assets/doodle/space-tiles.png"), 4));
			platform.AddComponent(new ColliderComponent(platform));
			platform.AddComponent(new PlatformComponent());
			entities.push_back(std::move(platform));
		}

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
	Sprite startMenu(new Surface("assets/doodle/space-menu.png"), 1);

	

	void Game::Tick(float)
	{
		Timer::Get().Tick();
		screen->Clear(0);
		mainBackground.Draw(screen, 0, 0);
		startMenu.Draw(screen, 0, 0);
		//convert deltaTime to seconds
		for (auto& e : entities)
		{
			e.Update();
		}

		for (auto& e : entities)
		{
			e.Render(*screen);
		}
		//check for collision
		for (int i = 1; i < entities.size(); i++)
		{
			if (!entities[i].GetComponent<ColliderComponent>())
			{
				return;
			}
			if (collision::OneWayAABB(entities[0].GetComponent<ColliderComponent>(), entities[i].GetComponent<ColliderComponent>()))
			{
				if (entities[0].GetComponent<PlayerComponent>()->velY >= 0)
				{
					entities[0].GetComponent<PlayerComponent>()->flipVelocity();
				}
			}
		}


		
		//camera bounds
		if (entities[0].GetComponent<TransformComponent>()->GetPosition().y < 330)
		{
			cameraControl->SetPos({ 0, 350.0f * static_cast<float>(Timer::Get().GetElapsedSeconds()) });
			auto pt = entities[0].GetComponent<PlayerComponent>();
			pt->y = 330;
			for (auto& e : entities)
			{
				auto et = e.GetComponent<TransformComponent>();

				et->SetOffset(cameraControl->GetPos());
				et->SetPosition({et->GetOffsetPos()});
			}
		}
	}



};