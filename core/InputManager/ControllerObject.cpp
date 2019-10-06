/**
 * @license
 */

 /**
  * @fileoverview Input Controller Object
  *
  * This is our base controller, you can have more than one controller
  * in your game, one for each player os one for different screen.
  *
  * @author @alexribeirodesa (Alexandre Ribeiro de Sá)
  */

#include "ControllerObject.h"

namespace F2D
{
	ControllerObject::ControllerObject(std::string n) {
		name = n;
		enabled = true;
	}

	ControllerObject::~ControllerObject() {}

	void ControllerObject::Push(ActionObject * action) {
		__actions.push_back(action);
	}

	bool ControllerObject::Pop(std::string name) {
		for(int x = 0; x < __actions.size(); x++) {
			if(__actions[x]->name == name) {
				__actions.erase(__actions.begin() + x);
				return true;
			}
		}

		return false;
	}

	ActionObject* ControllerObject::Get(std::string name) {
		for(int x = 0; x < __actions.size(); x++) {
			if(__actions[x]->name == name) {
				return __actions[x];
			}
		}

		return nullptr;
	}
}