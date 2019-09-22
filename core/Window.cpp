#include "Window.h"

namespace F2D {
	Window::Window() {
		this->Initialize();
	}

	Window::~Window() {}

	bool Window::Initialize() {
		bool output = false;

		//Initialize SDL
		if(SDL_Init(SDL_INIT_VIDEO) < 0) {
			printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		}
		else {
			//Use OpenGL 2.1
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

			//Create window
			__sdl_window = SDL_CreateWindow(__title.c_str(),
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

			if(__sdl_window == NULL) {
				printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			}
			else {
				//Create context
				__sdl_context = SDL_GL_CreateContext(__sdl_window);
				if(__sdl_context == NULL) {
					printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
				}
				else {
					//Use Vsync
					if(SDL_GL_SetSwapInterval(1) < 0) {
						printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
					}

					//Initialize OpenGL
					output = true;
				}
			}
		}

		return output;
	}

	std::string & Window::Title() {
		return __title;
	}

	void Window::Title(std::string & title) {
		__title = title;
		if(__sdl_window != NULL) {
			SDL_SetWindowTitle(__sdl_window, __title.c_str());
		}
	}

	SDL_Window* Window::SDLWindow() {
		return __sdl_window;
	};

	int Window::Width() {
		return SDL_GetWindowSurface(__sdl_window)->w;
	}

	int Window::Height() {
		return SDL_GetWindowSurface(__sdl_window)->h;
	}
}