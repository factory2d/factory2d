/**
 * @license
 */

 /**
  * @fileoverview Input Controller Object Header
  *
  * This is our base controller, you can have more than one controller
  * in your game, one for each player os one for different screen.
  *
  * @author @alexribeirodesa (Alexandre Ribeiro de Sá)
  */

#ifndef FACTORY2D_INPUTMANAGER_CONTROLLEROBJECT_H_
#define FACTORY2D_INPUTMANAGER_CONTROLLEROBJECT_H_

#include "../Object.h"

namespace F2D_Input
{
	class ControllerObject :
		public F2D::Object {

	public:
		ControllerObject();
		~ControllerObject();
	};
}

#endif // FACTORY2D_INPUTMANAGER_CONTROLLEROBJECT_H_