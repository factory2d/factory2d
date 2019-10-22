/**
* @license
* F2D are available under the zlib license :
*
* This software is provided 'as-is', without any express or implied
* warranty.In no event will the authors be held liable for any damages
* varising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
*including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions :
*
* 1. The origin of this software must not be misrepresented; you must not
*    claim that you wrote the original software.If you use this software
*    in a product, an acknowledgment in the product documentation would be
*    appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
*    misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
* /

/**
 * @fileoverview Window.cpp
 *
 * Create and manage the game window
 *
 * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
 *
 */

#include <iostream>
#include <sstream>

#include "WindowManager.h"
#include "../Debug.h"

#include "../Time/TimeManager.h"

namespace F2D {
	// window components
	SDL_Window* WindowManager::__sdl_window = NULL;
	SDL_GLContext WindowManager::__sdl_context;

	// window properties
	std::string WindowManager::__title = "Factory2D Game"; // window title
	bool WindowManager::__allowUserResize = true; // allow user to resize the window
	int WindowManager::__width = 800;
	int WindowManager::__height = 600;

	bool WindowManager::Initialize() {
		bool output = false;

		// initialize SDL
		if(SDL_Init(SDL_INIT_VIDEO) < 0) {
			_ERROR(SDL_GetError());
			//printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		}
		else {
			// use OpenGL 2.1
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

			//SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, 0);
			//SDL_RenderSetLogicalSize(_renderer, 640, 480)

			// create window
			__sdl_window = SDL_CreateWindow(__title.c_str(),
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				__width, __height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

			if(__sdl_window == NULL) {
				_ERROR(SDL_GetError());
				//printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			}
			else {
				// enable window resize
				SDL_SetWindowResizable(__sdl_window, (SDL_bool)__allowUserResize);

				// create context
				__sdl_context = SDL_GL_CreateContext(__sdl_window);
				if(__sdl_context == NULL) {
					_ERROR(SDL_GetError());
					//printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
				}
				else {
					// use VSync
					if(SDL_GL_SetSwapInterval(false) < 0) {
						_ERROR(SDL_GetError());
						//printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
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
		if(e->type != SDL_WINDOWEVENT)
			return;

		switch(e->window.event) {
		case SDL_WINDOWEVENT_SHOWN:
			break;
		case SDL_WINDOWEVENT_HIDDEN:
			break;
		case SDL_WINDOWEVENT_SIZE_CHANGED:
		case SDL_WINDOWEVENT_RESIZED:
			__width = SDL_GetWindowSurface(__sdl_window)->w;
			__height = SDL_GetWindowSurface(__sdl_window)->h;
			break;

		/*case SDL_WINDOWEVENT:		//	https://wiki.libsdl.org/SDL_WindowEvent
			// Here we will get window events we will use in editor
			std::cout << "window event" << e->window.event  << "\n";
			break;*/
		}
	}

	void WindowManager::Draw() {
		SDL_GL_SwapWindow(__sdl_window);

		if(__sdl_window != NULL) {
			std::ostringstream t;
			t << __title << " (" << TimeManager::FPS() << ")";
			SDL_SetWindowTitle(__sdl_window, t.str().c_str());
		}
	}

	std::string WindowManager::Title() {
		return __title;
	}

	void WindowManager::Title(std::string title) {
		__title = title;
	}

	bool WindowManager::Resizable() {
		return __allowUserResize;
	}

	void WindowManager::Resizable(bool value) {
		__allowUserResize = value;
		if(__sdl_window != NULL) {
			SDL_SetWindowResizable(__sdl_window, (SDL_bool)__allowUserResize);
		}
	}

	int WindowManager::Width() {
		return __width;
	}

	void WindowManager::Width(int value) {
		__width = value;
		if(__sdl_window != NULL) {
			SDL_SetWindowSize(__sdl_window, __width, __height);
		}
	}

	int WindowManager::Height() {
		return __height;
	}

	void WindowManager::Height(int value) {
		__height = value;
		if(__sdl_window != NULL) {
			SDL_SetWindowSize(__sdl_window, __width, __height);
		}
	}
}