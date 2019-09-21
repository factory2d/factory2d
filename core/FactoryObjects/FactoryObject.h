#ifndef __FACTORY2D_FACTORYOBJECT
#define __FACTORY2D_FACTORYOBJECT

#include <string>

#include "../Object.h"
#include "../Transform.h"

class Transform;

class FactoryObject :
	public Object {
public:
	Transform* transform;

	FactoryObject() {};
	FactoryObject(std::string name);
	~FactoryObject();

	virtual void Update();
	virtual void Draw();
};

#endif