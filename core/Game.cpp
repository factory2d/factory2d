/**
 * @license
 * F2D are available under the zlib license:
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * varising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

 /**
  * @fileoverview Game.cpp
  *
  * Base game object
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#include "SDL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>
#include <iostream>

#include "Game.h"
#include "Renderer.h"
#include "Time/TimeManager.h"
#include "Window/WindowManager.h"
#include "Input/InputManager.h"
#include "Scene/SceneManager.h"

namespace F2D
{
	Game::Game() {}
	Game::~Game() {}

	bool Game::Initialize() {
		WindowManager::Initialize();

		return true;
	}

	void Game::Run() {
		while(!__quit) {
			this->Update();
			this->Draw();
			TimeManager::Update();
		}

		//	TODO: destroy everything before close the app
	}

	void Game::Update() {
		SDL_Event e;



		//	https://wiki.libsdl.org/SDL_Event
		while(SDL_PollEvent(&e)) {
			// window events
			WindowManager::Update(&e);

			// input events
			InputManager::Update(&e);

			// game events
			switch(e.type) {
			case SDL_QUIT:
				__quit = true;
				break;
			};

			// TODO: every window, app, input event base
		}

		SceneManager::Update();
	}

	float r = 0.0f;
	float g = 0.0f;
	float b = 0.0f;

	void Game::Draw() {
		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		SceneManager::Draw();
		WindowManager::Draw();
	}
}