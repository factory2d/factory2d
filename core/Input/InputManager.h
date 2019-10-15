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

#ifndef FACTORY2D_INPUT_INPUTMANAGER_H_
#define FACTORY2D_INPUT_INPUTMANAGER_H_

/*
a little about my UTools (https://pt.slideshare.net/alexrdes/u-tools-unite-brasil-42578443)

- input manager
  - player
    - x [typeAxis]
	  - joystick X
	  - keyboard button +/-
    - y [typeAxis]
	  - joystick Y
	  - keyboard button +/-
	- attack
	  - joystick button
	  - keyboard button
	  - mouse button
*/

#include <string>
#include <vector> 

#include "ControllerObject.h"

namespace F2D
{
	class InputManager {
	private:
		static std::vector <ControllerObject*> __controllers;

	public:
		static float GetAxis(std::string);

		static bool GetButton(std::string);
		static bool GetButtonUp(std::string);
		static bool GetButtonDown(std::string);

		static void Update(void *event);
	};
}

#endif // FACTORY2D_INPUT_INPUTMANAGER_H_