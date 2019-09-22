#include "SDL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>
#include <iostream>

#include "Game.h"
#include "Renderer.h"
#include "SceneManager/SceneManager.h"

namespace F2D
{
	Game::Game() {}
	Game::~Game() {}

	bool Game::Initialize() {
		Renderer::window = new Window();
		__time = new GameTime();

		return true;
	}

	void Game::Run() {
		while(!__quit) {
			this->Update();
			this->Draw();
		}

		//	TODO: destroy everything before close the app
	}

	void Game::Update() {
		SDL_Event event;

		//	https://wiki.libsdl.org/SDL_Event
		while(SDL_PollEvent(&event)) {
			//	window events
			switch(event.type) {
			case SDL_WINDOWEVENT:		//	https://wiki.libsdl.org/SDL_WindowEvent
				LOG("Window Event");
				//TEST("Window Event");
				//std::cout << "window event" << event.window.event  << "\n";
				break;
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
		SDL_GL_SwapWindow(Renderer::window->SDLWindow());
	}
}