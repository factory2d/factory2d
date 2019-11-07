/**
 * @license
 * F2D are available under the zlib license:
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * varising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

 /**
  * @fileoverview FactoryObject.h
  *
  * --- FILE NOTES ---
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#ifndef FACTORY2D_OBJECTS_FACTORYOBJECT_H_
#define FACTORY2D_OBJECTS_FACTORYOBJECT_H_

#include <string>
#include <vector>

#include "../Object.h"
#include "../Transform.h"
#include "../Material/Material.h"
#include "../Behavior/Behaviour.h"

namespace F2D
{
	class Transform;
	class Behaviour;

	class FactoryObject :
		public Object {
	private:
		std::string __tag;
		std::vector <Behaviour*> __behaviours;

	public:
		Transform* transform;
		Material material;

		// constructor and destructor
		FactoryObject() {};
		FactoryObject(std::string name);
		~FactoryObject();

		// render and update
		virtual void Draw();
		virtual void Update();

		// tag
		std::string GetTag();
		void SetTag(std::string tag);
		void RemoveTag();

		// behaviour
		Behaviour* AddBehaviour(Behaviour* action);
		Behaviour* GetBehaviour(int behaviour);
		bool RemoveBehaviour(std::string name);
	};
}

#endif // FACTORY2D_OBJECTS_FACTORYOBJECT_H_
