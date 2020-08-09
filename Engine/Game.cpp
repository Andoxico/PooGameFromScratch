/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ft(),
	rng(rd()),
	xDist(30.0f, Graphics::ScreenWidth - 31.0f),
	yDist(30.0f, Graphics::ScreenHeight - 31.0f),
	vDist(-float(Poo::GetVectorLimit()), float(Poo::GetVectorLimit()))
{
	for (int i = 0; i < nPoos; i++) {
		if (i < poosVisible) {
			poo[i].Initialize(xDist(rng), yDist(rng), vDist(rng) * 4.5f, vDist(rng) * 4.5f, true);
		}
		else {
			poo[i].Initialize(xDist(rng), yDist(rng), vDist(rng) * 4.5f, vDist(rng) * 4.5f, false);
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	//Records the time the last frame took to complete
	deltaTime = ft.Mark();

	//Rectangle
	if (gameStarted) {
		if (rect.GetIsEaten()) {
			rect.Initialize(xDist(rng), yDist(rng));
		}

		if (!gameOver) {
			//Poos
			for (int i = 0; i < nPoos; i++) {
				poo[i].Update(deltaTime);
				if (poo[i].CollisionTest(dude)) {
					gameOver = true;
					break;
				}
			}

			//Dude
			dude.Controls(wnd.kbd, deltaTime);
			if (rect.CollisionTest(dude)) {
				dude.SpeedUp();
				poosVisible += 2;

				for (int i = poosVisible - 2; i < poosVisible; i++) {
					if (i < nPoos) {
						poo[i].SetIsVisible();
					}
				}
			}
		}

		//Rectangle glowing stuff (persists after game over)
		if (timerUp) {
			timer += 2;
		}
		else {
			timer -= 2;
		}
		if (timer >= 255) {
			timer = 255;
			timerUp = false;
		}
		else if (timer <= 0) {
			timer = 0;
			timerUp = true;
		}
	}
	else {
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
			gameStarted = true;
		}
	}
}

void Game::ComposeFrame()
{
	if (!gameStarted) {
		DrawStartScreen((Graphics::ScreenWidth / 2) - (150 / 2), (Graphics::ScreenHeight / 2) - (175 / 2));
	}
	else {
		rect.DrawBar(gfx, Colors::Cyan);
		rect.DrawBox(gfx, timer);
		dude.Draw(gfx);
		for (int i = 0; i < nPoos; i++) {
			if (poo[i].GetIsVisible()) {
				poo[i].Draw(gfx);
			}
		}
	}

	if (gameOver) {
		DrawGameOver((Graphics::ScreenWidth / 2) - (84 / 2), (Graphics::ScreenHeight / 2) - (64 / 2));
	}
}

void Game::DrawStartScreen(int x, int y)
{
#include "title(150x175).txt"
}

void Game::DrawGameOver(int x, int y)
{
#include "game_over(84x64).txt"
}
