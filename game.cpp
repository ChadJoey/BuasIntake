#include "game.h"
#include "surface.h"
#include "collision.h"
#include "Timer.h";
#include <iostream>
#include "SDL.h"
#include <cstdio> //printf



/* credit: https://www.youtube.com/watch?v=gKQd1qPQHgs&list=PLZHgukYvDo9cUYfUZZ6mtCrPnuX_4hRRl&index=8*/
namespace Tmpl8
{


	Game::Game()
	{
		buttons.push_back(new Button({ 110,299 }, new Surface("assets/doodle/play-btn.png")));

		buttons.push_back(new Button({ 441,650 }, new Surface("assets/doodle/close.png")));

		buttons.push_back(new Button({ 200,458 }, new Surface("assets/doodle/restart.png")));

		buttons[0]->SetActive(true);
		buttons[1]->SetActive(true);

		camera = new Camera();
		cameraControl = new CameraController(camera);

		player.AddComponent(new TransformComponent());
		player.AddComponent(new PlayerComponent);
		player.AddComponent(new SpriteComponent(new Surface("assets/doodle/space-doodles.png"), 12));
		player.AddComponent(new ColliderComponent(player));
		player.GetComponent<ColliderComponent>()->SetOffset(10, 5, 10, -10);

		vec2 storagePos{-100, -100 };

		for (size_t i = 0; i < platformAmount; i++)
		{
			Entity platform;
			platform.AddComponent(new TransformComponent());
			platform.GetComponent<TransformComponent>()->SetPosition({ startingPos[i] });
			platform.AddComponent(new SpriteComponent(new Surface("assets/doodle/space-tiles.png"), 4));
			platform.AddComponent(new ColliderComponent(platform));
			platform.AddComponent(new PlatformComponent());
			platforms.push_back(std::move(platform));
		}
		//make sprites shared
		Entity breakingBad;
		breakingBad.AddComponent(new TransformComponent());
		breakingBad.GetComponent<TransformComponent>()->SetPosition({350, 200});
		breakingBad.AddComponent(new SpriteComponent(new Surface("assets/doodle/breakingBad.png"), 4));
		breakingBad.AddComponent(new ColliderComponent(breakingBad));
		breakingBad.AddComponent(new BreakingPlatform());
		BreakingPlatforms.push_back(std::move(breakingBad));

		Entity enemy;
		enemy.AddComponent(new TransformComponent());
		enemy.GetComponent<TransformComponent>()->SetPosition({ 250,50 });
		enemy.AddComponent(new SpriteComponent(new Surface("assets/doodle/Enemies.png"), 4));
		enemy.AddComponent(new ColliderComponent(enemy));
		enemy.AddComponent(new Enemy());

		enemies.push_back(std::move(enemy));

		SetPlatforms(false);
		platforms[0].SetActive(true);

		endScreen = { 0, 800 };
	}

	void Game::ResetGame()
	{
		gameStart = false;
		gameOver = false;
		cameraControl->reset();
		player.GetComponent<PlayerComponent>()->Reset();
		for (size_t i = 0; i < platforms.size(); i++)
		{
			platforms[i].GetComponent<TransformComponent>()->SetPosition(startingPos[i]);
		}

		for (auto& breakingPlat : BreakingPlatforms)
		{
			breakingPlat.GetComponent<BreakingPlatform>()->Reset();
			breakingPlat.GetComponent<TransformComponent>()->SetPosition({ 350, 200 });
		}


		SetPlatforms(false);
		platforms[0].SetActive(true);

		startMenu = { 0,0 };
		buttons[0]->SetActive(true);
		buttons[1]->SetActive(true);


		endScreen = { 0, 800 };
	}

	Sprite mainBackground(new Surface("assets/doodle/space-bck@2x.png"), 1);
	Sprite startMenuSprite(new Surface(("assets/doodle/space-menu.png")), 1);
	Sprite endScreenSprite(new Surface(("assets/doodle/end-screen.png")), 1);


	void Game::Init()
	{
		platforms[0].SetActive(true);
	}
	
	void Game::Shutdown()
	{
	}

	void Game::MouseUp(int button)
	{
		player.MouseUp(button);


		buttons[0]->OnClick(gameStart);
		buttons[1]->OnClick(endGame);
		buttons[2]->OnClick(restart);
	}

	void Game::MouseDown(int button)
	{
		player.MouseDown(button);
	}

	void Game::MouseMove(int x, int y)
	{
		player.MouseMove(x, y);

		for (auto& b : buttons)
		{
			b->MouseMove(x, y);
		}
	}

	void Game::KeyDown(SDL_Scancode key)
	{
		player.KeyDown(key);
	}

	void Game::KeyUp(SDL_Scancode key)
	{
		player.KeyUp(key);
	}

	void Game::Tick(float)
	{
		Timer::Get().Tick();
		screen->Clear(0);
		mainBackground.Draw(screen, 0, 0);
		startMenuSprite.Draw(screen, startMenu.x, startMenu.y);
		endScreenSprite.Draw(screen, endScreen.x, endScreen.y);


		if (restart)
		{
			ResetGame();
			restart = false;
		}

		UpdateEntities();
		RenderEntities();

		if (!player.GetComponent<PlayerComponent>()->knockedOut)
		{
			CheckCollisions();
		}

		for (auto& b : buttons)
		{
			b->Render(screen);
		}

		
		//camera bounds
		if (player.GetComponent<TransformComponent>()->GetPosition().y < 350)
		{
			cameraControl->SetPos({ 0, 320.0f * static_cast<float>(Timer::Get().GetElapsedSeconds()) });
			auto pt = player.GetComponent<PlayerComponent>();
			pt->y = 350;
			for (auto& p : platforms)
			{
				auto t = p.GetComponent<TransformComponent>();
				t->SetOffset(cameraControl->GetPos());
				t->SetPosition({t->GetOffsetPos()});
			}
			for (auto& p : BreakingPlatforms)
			{
				auto t = p.GetComponent<TransformComponent>();
				t->SetOffset(cameraControl->GetPos());
				t->SetPosition({ t->GetOffsetPos() });
			}
			for (auto& e : enemies)
			{
				auto t = e.GetComponent<TransformComponent>();
				t->SetOffset(cameraControl->GetPos());
				t->SetPosition({ t->GetOffsetPos() });
			}
		}


		if (gameStart)
		{
			if (startMenu.y > -ScreenHeight)
			{
				time += Timer::Get().GetElapsedSeconds();
				buttons[1]->SetActive(false);
				player.GetComponent<PlayerComponent>()->velX += 1;
				StartScreenAnim();
			}
			else
			{
				player.GetComponent<PlayerComponent>()->canMove = true;
				SetPlatforms(true);
				gameStart = false;
			}
		}

		if (endGame)
		{
			SDL_Event e;
			e.type = SDL_QUIT;
			SDL_PushEvent(&e);
		}

		if (player.GetComponent<TransformComponent>()->GetPosition().y + player.GetComponent<SpriteComponent>()->GetHeight() >= 800)
		{
			gameOver = true;
		}

		if (gameOver)
		{
			MoveToEndScreen();

			for (auto& bp: BreakingPlatforms)
			{
				bp.SetActive(false);
			}
		}
	}



	void Game::MoveToEndScreen()
	{
		if (endScreen.y >= -100)
		{
			cameraControl->SetPos({ 0, -800.0f * static_cast<float>(Timer::Get().GetElapsedSeconds()) });
			endScreen.y -= 800 * static_cast<float>(Timer::Get().GetElapsedSeconds());

			for (auto& bp : BreakingPlatforms)
			{
				bp.SetActive(false);
			}

			auto pt = player.GetComponent<PlayerComponent>();
			for (auto& p : platforms)
			{
				auto t = p.GetComponent<TransformComponent>();
				t->SetOffset(cameraControl->GetPos());
				t->SetPosition({ t->GetOffsetPos() });
			}
			for (auto& e : enemies)
			{
				auto t = e.GetComponent<TransformComponent>();
				t->SetOffset(cameraControl->GetPos());
				t->SetPosition({ t->GetOffsetPos() });
			}
			pt->y = 710;

			if (endScreen.y <= -90)
			{
				buttons[2]->SetActive(true);
			}
		}
	}

	//==============================================================================================

	void Game::CheckCollisions()
	{
		for (auto& p : platforms)
		{

			if (player.GetComponent<PlayerComponent>()->velY >= 0)
			{
				const float colTime = collision::SweptAABB(player.GetComponent<ColliderComponent>(), p.GetComponent<ColliderComponent>());
				//check if there is a collision within a small window of time
				if (colTime <= 0.05f)
				{
					player.GetComponent<PlayerComponent>()->flipVelocity();
				}

			}


		}

		for (auto& bp : BreakingPlatforms)
		{
			if (player.GetComponent<PlayerComponent>()->velY >= 0)
			{
				const float colTime = collision::SweptAABB(player.GetComponent<ColliderComponent>(), bp.GetComponent<ColliderComponent>());
				//check if there is a collision within a small window of time
				if (colTime <= 0.05f)
				{
					if (bp.GetComponent<BreakingPlatform>())
					{
						bp.GetComponent<BreakingPlatform>()->playAnim = true;
					}
				}
			}
		}


		for (auto& e : enemies)
		{
			//check if there is a collision within a small window of time
			if (collision::AABB(player.GetComponent<ColliderComponent>(), e.GetComponent<ColliderComponent>()))
			{
				player.GetComponent<PlayerComponent>()->Knockout(player);
			}
		}
	}


	//==============================================================================================

	void Game::SetPlatforms(bool state)
	{
		for (auto& p : platforms)
		{
			p.SetActive(state);
		}
		for (auto& bp : BreakingPlatforms)
		{
			bp.SetActive(state);
		}
	}


	//==============================================================================================
	void Game::StartScreenAnim()
	{
		if (time < 0.1f)
		{
			startMenu.y += (750 * Timer::Get().GetElapsedSeconds());
		}
		else
		{
			startMenu.y -= (2000 * Timer::Get().GetElapsedSeconds());
		}
	}

	//==============================================================================================

	void Game:: UpdateEntities()
	{
		for (auto& p : platforms)
		{
			p.Update();
		}

		for (auto& bp : BreakingPlatforms)
		{
			bp.Update();
		}

		for (auto& e : enemies)
		{
			e.Update();
		}

		player.Update();
	}

	//==============================================================================================

	void Game::RenderEntities()
	{

		for (auto& p : platforms)
		{
			p.Render(*screen);
		}

		for (auto& bp : BreakingPlatforms)
		{
			bp.Render(*screen);
		}

		for (auto& e : enemies)
		{
			e.Render(*screen);
		}


		player.Render(*screen);
	}


};