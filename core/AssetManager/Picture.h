/**
 * @license
 */

 /**
  * @fileoverview Picture Asset Header
  *
  * Load picture files into the memory
  *
  * @author @alexribeirodesa (Alexandre Ribeiro de Sá)
  */

#ifndef FACTORY2D_RESOURCEMANAGER_PICTURERESOURCE_H_
#define FACTORY2D_RESOURCEMANAGER_PICTURERESOURCE_H_

#include <SDL_opengl.h>
#include "../Asset.h"

namespace F2D
{
	class Picture :
		public Asset {
	private:

	public:
		//virtual void * Data();
		virtual bool Load(std::string path);
	};
}

#endif // FACTORY2D_RESOURCEMANAGER_PICTURERESOURCE_H_