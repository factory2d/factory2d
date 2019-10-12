#include "WindowManager.h"
#include <iostream>

namespace F2D {
	std::string WindowManager::__title = "Factory2D Game";					// window title
	bool WindowManager::__alowUserResize = false;							// allow user to resize the window

	SDL_Window* WindowManager::__sdl_window = NULL;
	SDL_GLContext WindowManager::__sdl_context;

	bool WindowManager::Initialize() {
		bool output = false;

		// initialize SDL
		if(SDL_Init(SDL_INIT_VIDEO) < 0) {
			printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		}
		else {
			// use OpenGL 2.1
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

			// create window
			__sdl_window = SDL_CreateWindow(__title.c_str(),
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

			if(__sdl_window == NULL) {
				printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			}
			else {
				// create context
				__sdl_context = SDL_GL_CreateContext(__sdl_window);
				if(__sdl_context == NULL) {
					printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
				}
				else {
					// use Vsync
					if(SDL_GL_SetSwapInterval(1) < 0) {
						printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
					}

					// initialize OpenGL
					output = true;
				}
			}
		}

		return output;
	}

	void WindowManager::Update(void * event) {
		SDL_Event *e = (SDL_Event *)event;

		switch(e->type) {
		case SDL_WINDOWEVENT:		//	https://wiki.libsdl.org/SDL_WindowEvent
			// Here we will get window events we will use in editor
			std::cout << "window event" << e->window.event  << "\n";
			break;
		}
	}

	void WindowManager::Draw() {
		SDL_GL_SwapWindow(__sdl_window);
	}

	std::string WindowManager::Title() {
		return __title;
	}

	void WindowManager::Title(std::string title) {
		__title = title;
		if(__sdl_window != NULL) {
			SDL_SetWindowTitle(__sdl_window, __title.c_str());
		}
	}

	// cache this stuff
	int WindowManager::Width() {
		return SDL_GetWindowSurface(__sdl_window)->w;
	}

	int WindowManager::Height() {
		return SDL_GetWindowSurface(__sdl_window)->h;
	}
}