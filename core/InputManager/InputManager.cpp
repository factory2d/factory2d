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
  * @fileoverview Factory2D Input Manager
  *
  * Our InputManager, I'll use my UTools prototype as reference.
  *
  * @author @alexribeirodesa (Alexandre Ribeiro de Sá)
  */

#include "InputManager.h"

#include "SDL.h"

namespace F2D
{
	std::vector <ControllerObject*>InputManager::__controllers = {};

	float InputManager::GetAxis(std::string) {
		return 0.0f;
	}

	bool InputManager::GetButton(std::string) {
		return false;
	}

	bool InputManager::GetButtonUp(std::string) {
		return false;
	}

	bool InputManager::GetButtonDown(std::string) {
		return false;
	}

	void InputManager::Update(void *event) {
		SDL_Event *e = (SDL_Event *)event;

		switch(e->type) {
		// keyboard
		case SDL_KEYDOWN:
			std::cout << "keyboard key event: press " << SDL_GetKeyName(e->key.keysym.sym) << "\n";
			break;
		case SDL_KEYUP:
			std::cout << "keyboard key event: release " << SDL_GetKeyName(e->key.keysym.sym) << "\n";
			break;

		// mouse
		case SDL_MOUSEBUTTONDOWN:
			std::cout << "mouse button event: press " << (int)e->button.button << "\n";
			break;
		case SDL_MOUSEBUTTONUP:
			std::cout << "mouse button event: release " << (int)e->button.button << "\n";
			break;
		case SDL_MOUSEWHEEL:
			if(e->wheel.x != 0)
				std::cout << "mouse wheel X event: " << (int)(e->wheel.x) << "\n";
			if(e->wheel.y != 0)
				std::cout << "mouse wheel Y event: " << (int)(e->wheel.y) << "\n";
			break;
		case SDL_MOUSEMOTION:
			std::cout << "mouse motion event: " << (int)(e->motion.xrel) << ", " << (int)(e->motion.yrel) << "\n";
			break;
		}

		// joystick

		// touch

		// sensores
	}
}