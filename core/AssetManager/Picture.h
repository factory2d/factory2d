#ifndef FACTORY2D_RESOURCEMANAGER_PICTURERESOURCE_H_
#define FACTORY2D_RESOURCEMANAGER_PICTURERESOURCE_H_

#include "../Asset.h"

namespace F2D
{
	class Picture :
		Asset {
	public:
		Picture();
		~Picture();

		virtual void Load(std::string asset);
	};
}

#endif // FACTORY2D_RESOURCEMANAGER_PICTURERESOURCE_H_