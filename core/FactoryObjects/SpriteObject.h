#ifndef __FACTORY2D_SPRITEOBJECT
#define __FACTORY2D_SPRITEOBJECT

#include "FactoryObject.h"

class SpriteObject :
	public FactoryObject {
public:
	SpriteObject() {};
	SpriteObject(std::string name);
	~SpriteObject();

	void Update() override;
	void Draw() override;
};

#endif