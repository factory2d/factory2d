#ifndef __FACTORY2D_TEXTUREOBJECT_H
#define __FACTORY2D_TEXTUREOBJECT_H

#include "FactoryObject.h"

namespace F2D
{
	class TextureObject :
		public Object {
	public:
		TextureObject();
		~TextureObject();

		int Width();
		int Height();
	};
}

#endif