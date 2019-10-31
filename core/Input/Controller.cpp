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
  * @fileoverview ControllerObject.cpp
  *
  * --- FILE NOTES ---
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#include "Controller.h"

namespace F2D
{
	Controller::Controller(std::string n) {
		name = n;
		enabled = true;
	}

	Controller::~Controller() {}

	Action* Controller::Push(Action * action) {
		__actions.push_back(action);
		return __actions.back();
	}

	bool Controller::Pop(std::string name) {
		unsigned int totalActions = __actions.size();

		for(unsigned int x = 0; x < totalActions; x++) {
			if(__actions[x]->name == name) {
				__actions.erase(__actions.begin() + x);
				return true;
			}
		}

		return false;
	}

	Action* Controller::Get(std::string name) {
		unsigned int totalActions = __actions.size();

		for(unsigned int x = 0; x < totalActions; x++) {
			if(__actions[x]->name == name) {
				return __actions[x];
			}
		}

		return nullptr;
	}
}
