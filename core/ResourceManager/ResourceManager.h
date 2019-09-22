#ifndef __FACTORY2D_ASSETMANAGER
#define __FACTORY2D_ASSETMANAGER

#include <string>
#include <map>
#include <vector> 

namespace F2D
{
	/*enum ResourceTypes {
		IMAGE = 0,
		SOUND,
		FONT,
	};

	enum ImagesTypes {
		PNG = 0,
		JPG,
	};*/

	struct Resource {
		//ResourceTypes type;
		std::string path;
		void * data;
	};


	class ResourceManager {
	private:
		static std::map <std::string, std::vector<Resource*>*> __resources;

	public:
		static void * Load(std::string name);
		static void * LoadImage(std::string name, int type) { return NULL; };
	};
}

#endif