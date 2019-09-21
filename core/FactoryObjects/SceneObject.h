#ifndef __FACTORY2D_SCENEOBJECT
#define __FACTORY2D_SCENEOBJECT

#include "FactoryObject.h"

class SceneObject :
	public FactoryObject {

public:
	SceneObject() {};
	SceneObject(std::string name);
	~SceneObject();
};

#endif