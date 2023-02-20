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
		Button* button = (new Button({110,299}, new Surface("assets/doodle/play-btn.png")));
		buttons.push_back(*button);


		//Button* closeButton = (new Button({400,500}, new Surface("assets/doodle/close.png")));
		//buttons.push_back(*closeButton);


		buttons[0].SetActive(true);
		//buttons[1].SetActive(true);
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

	Sprite mainBackground(new Surface("assets/doodle/space-bck@2x.png"), 1);
	Sprite startMenuSprite(new Surface(("assets/doodle/space-menu.png")), 1);


	void Game::Init()
	{
		for (auto& e : entities)
		{
			e.Init();
		}
		entities[1].SetActive(true);
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
		buttons[0].OnClick(gameStart);
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

		for (auto& b : buttons)
		{
			b.MouseMove(x, y);
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
		mainBackground.Draw(screen, 0, 0);
		startMenuSprite.Draw(screen, startMenu.pos.x, startMenu.pos.y);
		//convert deltaTime to seconds
		for (auto& e : entities)
		{
			e.Update();
		}

		for (auto& e : entities)
		{
			e.Render(*screen);
		}

		for (auto& b : buttons)
		{
			b.Render(*screen);
		}

		//check for collision
		for (int i = 1; i < entities.size(); i++)
		{
			if (!entities[i].GetComponent<ColliderComponent>())
			{
				return;
			}

			float colTime = collision::SweptAABB(entities[0].GetComponent<ColliderComponent>(), entities[i].GetComponent<ColliderComponent>());


				if (entities[0].GetComponent<PlayerComponent>()->velY >= 0)
				{
					//check if there is a collision within a small window of time
					if (colTime <= 0.05f)
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


		if (gameStart)
		{
			if (startMenu.pos.y > -ScreenHeight)
			{
				time += Timer::Get().GetElapsedSeconds();
				StartScreenAnim();
			}
		}



	}



	void Game::StartScreenAnim()
	{
		if (time < 0.1f)
		{
			startMenu.pos.y += (750 * Timer::Get().GetElapsedSeconds());
		}
		else
		{
			startMenu.pos.y -= (2000 * Timer::Get().GetElapsedSeconds());
		}

	}



};