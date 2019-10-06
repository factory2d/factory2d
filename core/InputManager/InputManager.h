/**
 * @license
 */

 /**
  * @fileoverview Factory2D Input Manager Header
  *
  * Our InputManager, I'll use my UTools prototype as reference.
  *
  * @author @alexribeirodesa (Alexandre Ribeiro de Sá)
  */

#ifndef FACTORY2D_INPUTMANAGER_INPUTMANAGER_H_
#define FACTORY2D_INPUTMANAGER_INPUTMANAGER_H_

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
	};
}

#endif // FACTORY2D_INPUTMANAGER_INPUTMANAGER_H_