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

#include <iostream>
#include <vector> 

#include "../Object.h"
#include "ActionObject.h"

namespace F2D
{
	class ControllerObject :
		public F2D::Object {
	private:
		std::vector <ActionObject*> __actions = {};

	public:
		ControllerObject(std::string name);
		~ControllerObject();

		void Push(ActionObject* action);
		bool Pop(std::string name);
		ActionObject* Get(std::string name);
	};
}

#endif // FACTORY2D_INPUTMANAGER_CONTROLLEROBJECT_H_