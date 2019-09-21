#ifndef __FACTORY2D_ASSETMANAGER
#define __FACTORY2D_ASSETMANAGER

#include <string>
#include <vector> 

class ResourceManager {
private:

public:
	static void * Load(std::string name);
};

#endif