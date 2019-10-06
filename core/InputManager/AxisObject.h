/**
 * @license
 */

 /**
  * @fileoverview Axis Action Object Header
  *
  * Controller Axis Action Object
  *
  * @author @alexribeirodesa (Alexandre Ribeiro de Sá)
  */

#ifndef FACTORY2D_INPUTMANAGER_AXISOBJECT_H_
#define FACTORY2D_INPUTMANAGER_AXISOBJECT_H_

#include "ActionObject.h"

namespace F2D
{
	class AxisObject :
		public ActionObject {
	public:
		AxisObject(std::string name);
		~AxisObject();
	};
}

#endif // FACTORY2D_INPUTMANAGER_AXISOBJECT_H_