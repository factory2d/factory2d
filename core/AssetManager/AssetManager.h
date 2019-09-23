#ifndef __FACTORY2D_ASSETMANAGER
#define __FACTORY2D_ASSETMANAGER

#include <string>
#include <map>
#include <vector> 

#include "../Asset.h"

namespace F2D
{
	/*
	struct Resource {
		ResourceTypes type;
		std::string path;
		void * data;
	};
	*/

	class AssetManager {
	private:
		static std::map <std::string, Asset*> __assets;

	public:
		static void * Load(std::string name);
		//static void * LoadPicture(std::string name, ImagesTypes type);
	};
}

#endif