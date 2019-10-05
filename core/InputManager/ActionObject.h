/**
 * @license
 */

 /**
  * @fileoverview Controller Action Object Header
  *
  * This is the controller action, each controller can have multiple
  * actions, like JUMP, ATTACK, X and/or Y.
  *
  * @author @alexribeirodesa (Alexandre Ribeiro de S�)
  */

#ifndef FACTORY2D_INPUTMANAGER_ACTIONOBJECT_H_
#define FACTORY2D_INPUTMANAGER_ACTIONOBJECT_H_

#include "../Object.h"

namespace F2D_Input
{
	class ActionObject :
		public F2D::Object {
	public:
		ActionObject();
		~ActionObject();
	};
}

#endif // FACTORY2D_INPUTMANAGER_ACTIONOBJECT_H_