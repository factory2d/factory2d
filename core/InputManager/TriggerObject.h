/**
 * @license
 */

 /**
  * @fileoverview Controller Action Trigger Object Header
  *
  * Here we set the action trigger, like mouse button, keyboard press...
  *
  * @author @alexribeirodesa (Alexandre Ribeiro de Sá)
  */

#ifndef FACTORY2D_INPUTMANAGER_TRIGGEROBJECT_H_
#define FACTORY2D_INPUTMANAGER_TRIGGEROBJECT_H_

#include "../Object.h"

namespace F2D_Input
{
	class TriggerObject :
		public F2D::Object {
	public:
		TriggerObject();
		~TriggerObject();
	};
}

#endif // FACTORY2D_INPUTMANAGER_TRIGGEROBJECT_H_