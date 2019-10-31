#ifndef __FACTORY2D_SPRITEOBJECT
#define __FACTORY2D_SPRITEOBJECT

#include "../Asset/PictureAsset.h"
#include "FactoryObject.h"

namespace F2D
{
	class SpriteObject :
		public FactoryObject {
	public:
		PictureAsset *p;

		SpriteObject() {};
		SpriteObject(std::string name);
		~SpriteObject();

		void Update() override;
		void Draw() override;
	};
}

#endif