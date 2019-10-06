/**
 * @license
 */

 /**
  * @fileoverview Button Action Object Header
  *
  * Controller Button Action Object
  *
  * @author @alexribeirodesa (Alexandre Ribeiro de Sá)
  */

#ifndef FACTORY2D_INPUTMANAGER_BUTTONOBJECT_H_
#define FACTORY2D_INPUTMANAGER_BUTTONOBJECT_H_

#include "ActionObject.h"

namespace F2D
{
	class ButtonObject :
		public ActionObject {
	public:
		ButtonObject(std::string name);
		~ButtonObject();
	};
}

#endif // FACTORY2D_INPUTMANAGER_BUTTONOBJECT_H_