#ifndef __FACTORY2D_SCENEOBJECT
#define __FACTORY2D_SCENEOBJECT

#include "FactoryObject.h"

namespace F2D {
	class SceneObject :
		public FactoryObject {

	public:
		SceneObject() {};
		SceneObject(std::string name);
		~SceneObject();
	};
}

#endif