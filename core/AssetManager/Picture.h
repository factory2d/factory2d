#ifndef FACTORY2D_RESOURCEMANAGER_PICTURERESOURCE_H_
#define FACTORY2D_RESOURCEMANAGER_PICTURERESOURCE_H_

#include <SDL_opengl.h>
#include "../Asset.h"

namespace F2D
{
	class Picture :
		public Asset {
	private:
		//GLuint __texture;
	public:
		//virtual void * Data();
		virtual void Load(std::string asset);
	};
}

#endif // FACTORY2D_RESOURCEMANAGER_PICTURERESOURCE_H_