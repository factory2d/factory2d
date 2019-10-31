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
  * @fileoverview InputManager.h
  *
  * Here we manage our input, I'm using my old UTools plugin as referenct
  * (https://pt.slideshare.net/alexrdes/u-tools-unite-brasil-42578443)
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#include "InputManager.h"

#include "SDL.h"

#include "../Time/TimeManager.h"

namespace F2D
{
	std::vector <Controller*>InputManager::__controllers = {};
	std::map <unsigned char, bool>InputManager::__keyboardKeys = {};
	long InputManager::__lastUpdate = -1;

	float InputManager::GetAxis(std::string controller, std::string action) {
		unsigned int totalController = __controllers.size();

		for(unsigned int x = 0; x < totalController; x++) {
			if(__controllers[x]->enabled) {
				F2D::Action *a = __controllers[x]->Get(action);
				if(a != nullptr) {
					return a->GetAxis();
				}
			}
		}

		return 0.0f;
	}

	bool InputManager::GetButton(std::string controller, std::string action) {
		unsigned int totalController = __controllers.size();

		for(unsigned int x = 0; x < totalController; x++) {
			if(__controllers[x]->enabled) {
				F2D::Action *a = __controllers[x]->Get(action);
				if(a != nullptr) {
					return a->GetButton();
				}
			}
		}
		return false;
	}

	bool InputManager::GetButtonUp(std::string controller, std::string action) {
		return false;
	}

	bool InputManager::GetButtonDown(std::string controller, std::string action) {
		return false;
	}

	bool InputManager::GetKeyboardKey(unsigned char key) {
		if(__keyboardKeys[key] != NULL)
			return __keyboardKeys[key];
		return false;
	}

	void InputManager::Update(void *event) {
		SDL_Event *e = (SDL_Event *)event;

		switch(e->type) {
		// keyboard
		case SDL_KEYDOWN:
			//std::cout << "keyboard key event: press " << SDL_GetKeyName(e->key.keysym.sym) << "\n";
			__keyboardKeys[e->key.keysym.sym] = true;
			break;
		case SDL_KEYUP:
			//std::cout << "keyboard key event: release " << SDL_GetKeyName(e->key.keysym.sym) << "\n";
			__keyboardKeys[e->key.keysym.sym] = false;
			break;

		// mouse
		case SDL_MOUSEBUTTONDOWN:
			//std::cout << "mouse button event: press " << SDL_GetKeyName((int)e->button.button) << "\n";
			switch(e->button.button) {
			case 1:
				__keyboardKeys[F2D_MOUSE_LEFT] = true;
				break;
			case 2:
				__keyboardKeys[F2D_MOUSE_MIDDLE] = true;
				break;			
			case 3:
				__keyboardKeys[F2D_MOUSE_RIGHT] = true;
				break;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			//std::cout << "mouse button event: release " << (int)e->button.button << "\n";
			switch(e->button.button) {
			case 1:
				__keyboardKeys[F2D_MOUSE_LEFT] = false;
				break;
			case 2:
				__keyboardKeys[F2D_MOUSE_MIDDLE] = false;
				break;
			case 3:
				__keyboardKeys[F2D_MOUSE_RIGHT] = false;
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			__keyboardKeys[F2D_MOUSE_WRIGHT] = (e->wheel.x > 0);
			__keyboardKeys[F2D_MOUSE_WLEFT] = (e->wheel.x < 0);
			__keyboardKeys[F2D_MOUSE_WDOWN] = (e->wheel.y < 0);
			__keyboardKeys[F2D_MOUSE_WUP] = (e->wheel.y > 0);

			break;
		case SDL_MOUSEMOTION:
			//std::cout << "mouse motion event: " << (int)(e->motion.xrel) << ", " << (int)(e->motion.yrel) << "\n";
			break;

		// joystick
		/*
		case SDL_JOYDEVICEADDED:
			std::cout << "joystick added: " << e->jdevice.which << "\n";
			break;
		case SDL_JOYDEVICEREMOVED:
			std::cout << "joystick removed: " << e->jdevice.which << "\n";
			break;
		case SDL_JOYBUTTONDOWN:
			break;
		case SDL_JOYBUTTONUP:
			break;
		case SDL_JOYHATMOTION:
			break;
		case SDL_JOYAXISMOTION:
			break;
		*/

		// xinput?

		// touch

		// sensores
		}
	}

	Controller* InputManager::Push(Controller * controller) {
		__controllers.push_back(controller);
		return __controllers.back();
	}
}
