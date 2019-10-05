/**
 * @license
 */

 /**
  * @fileoverview Factory2D Input Manager
  *
  * Our InputManager, I'll use my UTools prototype as reference.
  *
  * @author @alexribeirodesa (Alexandre Ribeiro de Sá)
  */

#include "InputManager.h"

namespace F2D_Input
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
}