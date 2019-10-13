#include "SDL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>
#include <iostream>

#include "Game.h"
#include "Renderer.h"
#include "GameTime.h"
#include "WindowManager/WindowManager.h"
#include "InputManager/InputManager.h"
#include "SceneManager/SceneManager.h"

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
			GameTime::Update();
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