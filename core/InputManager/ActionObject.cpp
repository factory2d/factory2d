/**
 * @license
 */

 /**
  * @fileoverview Controller Action Object
  *
  * This is the controller action, each controller can have multiple
  * actions, like JUMP, ATTACK, X and/or Y.
  *
  * @author @alexribeirodesa (Alexandre Ribeiro de Sá)
  */

#include "ActionObject.h"

namespace F2D
{
	ActionObject::ActionObject(std::string n) {
		name = n;
		enabled = true;
	}

	ActionObject::~ActionObject() {}
}