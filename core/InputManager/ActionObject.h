/**
 * @license
 */

 /**
  * @fileoverview Controller Action Object Header
  *
  * This is the controller action, each controller can have multiple
  * actions, like JUMP, ATTACK, X and/or Y.
  *
  * @author @alexribeirodesa (Alexandre Ribeiro de Sá)
  */

#ifndef FACTORY2D_INPUTMANAGER_ACTIONOBJECT_H_
#define FACTORY2D_INPUTMANAGER_ACTIONOBJECT_H_

#include "../Object.h"

namespace F2D
{
	class ActionObject :
		public F2D::Object {
	public:
		ActionObject(std::string name);
		~ActionObject();
	};
}

#endif // FACTORY2D_INPUTMANAGER_ACTIONOBJECT_H_